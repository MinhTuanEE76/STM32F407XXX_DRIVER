#include "stm32f407xxx_can.h"
#include "stm32f407xxx_systick.h"

#define NULL ((void *)0)
#define CAN_TIMEOUT_VALUE 1000U

/*< General CAN initialization function
1. validate the input parameters: hcan NULL,instance,init,baudrate,mode
2. check driver state: tx/rx busy, reject init if busy
3. update state to busy
4. exit sleep mode if requested and enter initialization mode
5. clear old configuration of MCR BTR
6. configure MCR and BTR based on Init parameters
7. Config operating mode
8. configure bit timing parameters
9. exit initialization mode and update state to ready
10. clear error code
11. Update state to ready
12. return status
*/
CAN_Status_t CAN_Init(CAN_Handle_t *hcan)
{
    uint32_t tickstart = SYSTICK_GetTick();
    if (hcan == NULL)
    {
        return CAN_ERROR;
    }

    hcan->ErrorCode = CAN_ERROR_NONE;

    if (hcan->Instance == NULL)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    if (hcan->State == CAN_STATE_BUSY)
    {
        return CAN_BUSY;
    }

    if (hcan->Init.Mode > CAN_MODE_SILENT_LOOPBACK)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }
    // validate timing
    if (hcan->Init.BitTiming.Prescaler < 1U || hcan->Init.BitTiming.Prescaler > 1024U)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    if (hcan->Init.BitTiming.TS1 < 1U ||
        hcan->Init.BitTiming.TS1 > 16U)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    if (hcan->Init.BitTiming.TS2 < 1U || hcan->Init.BitTiming.TS2 > 8U)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    if (hcan->Init.BitTiming.SJW < 1U || hcan->Init.BitTiming.SJW > 4U)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    if (hcan->Init.BitTiming.SJW > hcan->Init.BitTiming.TS2)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    // update state to busy
    hcan->State = CAN_STATE_BUSY;

    /*< exit sleep mode to enter initialization mode */
    if (hcan->Instance->MSR & CAN_MSR_SLAK)
    {
        hcan->Instance->MCR &= ~CAN_MCR_SLEEP; // exit sleep mode
        tickstart = SYSTICK_GetTick();
        while (hcan->Instance->MSR & CAN_MSR_SLAK) // wait until SLAK bit is cleared
        {
            if (SYSTICK_GetTick() - tickstart > CAN_TIMEOUT_VALUE)
            {
                hcan->ErrorCode |= CAN_ERROR_TIMEOUT;
                hcan->State = CAN_STATE_TIMEOUT;
                return CAN_TIMEOUT;
            }
        }
    }

    hcan->Instance->MCR |= CAN_MCR_INRQ; // enter initialization mode
    tickstart = SYSTICK_GetTick();
    while (!(hcan->Instance->MSR & CAN_MSR_INAK)) // wait until INAK bit is set
    {
        if (SYSTICK_GetTick() - tickstart > CAN_TIMEOUT_VALUE)
        {
            hcan->ErrorCode |= CAN_ERROR_TIMEOUT;
            hcan->State = CAN_STATE_TIMEOUT;
            return CAN_TIMEOUT;
        }
    }

    // clear old configuration of MCR BTR
    hcan->Instance->MCR &= ~(CAN_MCR_TXFP |
                             CAN_MCR_RFLM |
                             CAN_MCR_NART |
                             CAN_MCR_AWUM |
                             CAN_MCR_ABOM);

    hcan->Instance->BTR &= ~(CAN_BTR_LBKM |
                             CAN_BTR_SILM);

    // configure features based on Init parameters
    if (hcan->Init.AutoBussOff)
    {
        hcan->Instance->MCR |= CAN_MCR_ABOM; // set bit auto bus-off management
    }

    if (hcan->Init.AutoWakeUp)
    {
        hcan->Instance->MCR |= CAN_MCR_AWUM; // set bit auto wake-up mode
    }

    if (hcan->Init.AutoRetransmission)
    {
        hcan->Instance->MCR &= ~CAN_MCR_NART; // clear bit to enable auto retransmission
    }
    else
    {
        hcan->Instance->MCR |= CAN_MCR_NART; // set bit to disable auto retransmission
    }

    if (hcan->Init.ReceiveFifoLocked)
    {
        hcan->Instance->MCR |= CAN_MCR_RFLM; // receive FIFO locked mode = 1 ->discard new message when FIFO is full
    }
    else
    {
        hcan->Instance->MCR &= ~CAN_MCR_RFLM; // receive FIFO locked mode = 0 -> overwrite old message when FIFO is full
    }

    if (hcan->Init.TransmitFifoPriority)
    {
        hcan->Instance->MCR |= CAN_MCR_TXFP; // transmit FIFO priority by the order of requests
    }
    else
    {
        hcan->Instance->MCR &= ~CAN_MCR_TXFP; // transmit FIFO priority by the identifier of the message
    }

    // configure operating mode
    switch (hcan->Init.Mode)
    {
    case CAN_MODE_NORMAL:
        break;

    case CAN_MODE_LOOPBACK:
        hcan->Instance->BTR |= CAN_BTR_LBKM;
        break;

    case CAN_MODE_SILENT:
        hcan->Instance->BTR |= CAN_BTR_SILM;
        break;

    case CAN_MODE_SILENT_LOOPBACK:
        hcan->Instance->BTR |= (CAN_BTR_LBKM | CAN_BTR_SILM);
        break;

    default:
        hcan->State = CAN_STATE_ERROR;
        hcan->ErrorCode |= CAN_ERROR_PARAM;

        return CAN_ERROR;
    }

    // configure bit timing parameters
    hcan->Instance->BTR &= ~(CAN_BTR_BRP_Msk |
                             CAN_BTR_TS1_Msk |
                             CAN_BTR_TS2_Msk |
                             CAN_BTR_SJW_Msk); // clear BTR before configuring

    hcan->Instance->BTR |= ((hcan->Init.BitTiming.Prescaler - 1U) << CAN_BTR_BRP_Pos) & CAN_BTR_BRP_Msk;
    hcan->Instance->BTR |= ((hcan->Init.BitTiming.TS1 - 1U) << CAN_BTR_TS1_Pos) & CAN_BTR_TS1_Msk;
    hcan->Instance->BTR |= ((hcan->Init.BitTiming.TS2 - 1U) << CAN_BTR_TS2_Pos) & CAN_BTR_TS2_Msk;
    hcan->Instance->BTR |= ((hcan->Init.BitTiming.SJW - 1U) << CAN_BTR_SJW_Pos) & CAN_BTR_SJW_Msk;

    // update state to ready
    hcan->State = CAN_STATE_READY;

    return CAN_OK;
}

/*Initialize filter
1. Validate parameters
   - bank
   - scale
   - mode
   - fifo
   - etc
2. Enter filter init mode FMR.FINIT = 1
3. Disable target filter bank FA1R &= ~
4. Configure filter scale FS1R
5. Configure filter mode FM1R
6. Configure FIFO assignment FFA1R
7. Write FR1/FR2
8. Activate filter if requested FA1R |=
9. Exit filter init mode FMR.FINIT = 0
*/
/*< Configure CAN filter */
CAN_Status_t CAN_ConfigFilter(CAN_Handle_t *hcan, CAN_FilterConfig_t *FilterConfig)
{
    // Validate parameters
    if (hcan == NULL || FilterConfig == NULL)
    {
        return CAN_ERROR;
    }

    hcan->ErrorCode = CAN_ERROR_NONE;

    /* check CAN instance */
    if (hcan->Instance == NULL)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /* validate filter bank
     * bxCAN on STM32F407 has 28 filter banks: 0 -> 27
     */
    if (FilterConfig->FilterBank > 27U)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /* validate filter mode */
    if (FilterConfig->FilterMode > CAN_FILTERMODE_IDLIST)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /* validate filter scale */
    if (FilterConfig->FilterScale > CAN_FILTER_SCALE_32BIT)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /* validate FIFO assignment */
    if (FilterConfig->FifoAssignment > CAN_RX_FIFO1)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /*=====================================================
     * Enter filter initialization mode
     *
     * FINIT = 1:
     * - Freeze all filters
     * - Allow software to modify filter registers
     *=====================================================*/
    hcan->Instance->FMR |= CAN_FMR_FINIT;

    /*=====================================================
     * Disable filter before reconfiguration
     *
     * IMPORTANT:
     * Filter must be deactivated before changing:
     * - scale
     * - mode
     * - FR1/FR2
     *=====================================================*/
    hcan->Instance->FA1R &= ~(1U << FilterConfig->FilterBank);

    /*=====================================================
     * Configure filter scale
     *
     * FSCx = 0 -> 16-bit scale
     * FSCx = 1 -> 32-bit scale
     *=====================================================*/
    if (FilterConfig->FilterScale == CAN_FILTER_SCALE_32BIT)
    {
        hcan->Instance->FS1R |= (1U << FilterConfig->FilterBank);
    }
    else
    {
        hcan->Instance->FS1R &= ~(1U << FilterConfig->FilterBank);
    }

    /*=====================================================
     * Configure filter mode
     *
     * FBMx = 0 -> Mask mode
     * FBMx = 1 -> List mode
     *=====================================================*/
    if (FilterConfig->FilterMode == CAN_FILTERMODE_IDLIST)
    {
        hcan->Instance->FM1R |= (1U << FilterConfig->FilterBank);
    }
    else
    {
        hcan->Instance->FM1R &= ~(1U << FilterConfig->FilterBank);
    }

    /*=====================================================
     * Configure FIFO assignment
     *
     * FFAx = 0 -> FIFO0
     * FFAx = 1 -> FIFO1
     *=====================================================*/
    if (FilterConfig->FifoAssignment == CAN_RX_FIFO1)
    {
        hcan->Instance->FFA1R |= (1U << FilterConfig->FilterBank);
    }
    else
    {
        hcan->Instance->FFA1R &= ~(1U << FilterConfig->FilterBank);
    }

    /*=====================================================
     * Configure filter registers
     *
     * IMPORTANT:
     *
     * bxCAN filter format is NOT fixed.
     *
     * The meaning of FR1/FR2 depends on:
     * - 16-bit / 32-bit mode
     * - Mask mode / List mode
     * - Standard / Extended ID
     *
     * Therefore:
     * Driver only writes raw packed values.
     *
     * User/helper function must prepare
     * correctly formatted values before calling.
     *=====================================================*/

    /*-----------------------------------------------------
     * 32-bit scale
     *-----------------------------------------------------
     * MASK MODE:
     *   FR1 = ID
     *   FR2 = MASK
     *
     * LIST MODE:
     *   FR1 = ID1
     *   FR2 = ID2
     *----------------------------------------------------*/
    if (FilterConfig->FilterScale == CAN_FILTER_SCALE_32BIT)
    {
        hcan->Instance->sFilterRegister[FilterConfig->FilterBank].FR1 = FilterConfig->FilterID1;
        hcan->Instance->sFilterRegister[FilterConfig->FilterBank].FR2 = FilterConfig->FilterID2;
    }
    /*-----------------------------------------------------
     * 16-bit scale
     *-----------------------------------------------------
     * FR1 and FR2 each contain:
     * - two 16-bit fields
     *
     * User must pack data manually.
     *----------------------------------------------------*/
    else
    {
        hcan->Instance->sFilterRegister[FilterConfig->FilterBank].FR1 = FilterConfig->FilterID1;

        hcan->Instance->sFilterRegister[FilterConfig->FilterBank].FR2 = FilterConfig->FilterID2;
    }

    /*=====================================================
     * Activate filter if requested
     *
     * FACTx = 1 -> filter enabled
     * FACTx = 0 -> filter disabled
     *=====================================================*/
    if (FilterConfig->FilterActivation == CAN_FILTER_ENABLE)
    {
        hcan->Instance->FA1R |= (1U << FilterConfig->FilterBank);
    }
    else
    {
        hcan->Instance->FA1R &= ~(1U << FilterConfig->FilterBank);
    }

    /*=====================================================
     * Exit filter initialization mode
     *
     * FINIT = 0:
     * Filters become active again
     *=====================================================*/
    hcan->Instance->FMR &= ~CAN_FMR_FINIT;

    return CAN_OK;
}

/*=========================================================
 * CAN_Start
 *
 * Leave initialization mode and start CAN operation
 *
 * After this function:
 * - CAN participates on the bus
 * - TX/RX becomes active
 *=========================================================*/
CAN_Status_t CAN_Start(CAN_Handle_t *hcan)
{
    uint32_t tickstart = SYSTICK_GetTick();

    /* Check NULL handle */
    if (hcan == NULL)
    {
        return CAN_ERROR;
    }

    /* Clear previous error */
    hcan->ErrorCode = CAN_ERROR_NONE;

    /* Check CAN instance */
    if (hcan->Instance == NULL)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /*-----------------------------------------------------
     * CAN must already be initialized
     *
     * Allowed states:
     * - READY
     * - STOPPED
     *----------------------------------------------------*/
    if ((hcan->State != CAN_STATE_READY) && (hcan->State != CAN_STATE_STOPPED))
    {
        hcan->ErrorCode |= CAN_ERROR_NOT_INITIALIZED;
        return CAN_ERROR;
    }

    /*Exit sleep mode if peripheral is sleeping*/
    if (hcan->Instance->MSR & CAN_MSR_SLAK)
    {
        hcan->Instance->MCR &= ~CAN_MCR_SLEEP;

        tickstart = SYSTICK_GetTick();

        while (hcan->Instance->MSR & CAN_MSR_SLAK)
        {
            if ((SYSTICK_GetTick() - tickstart) > CAN_TIMEOUT_VALUE)
            {
                hcan->ErrorCode |= CAN_ERROR_TIMEOUT;
                hcan->State = CAN_STATE_ERROR;

                return CAN_TIMEOUT;
            }
        }
    }

    /* Leave initialization mode*/
    hcan->Instance->MCR &= ~CAN_MCR_INRQ;

    /* Wait until INAK cleared by hardware */
    tickstart = SYSTICK_GetTick();

    while (hcan->Instance->MSR & CAN_MSR_INAK)
    {
        if ((SYSTICK_GetTick() - tickstart) > CAN_TIMEOUT_VALUE)
        {
            hcan->ErrorCode |= CAN_ERROR_TIMEOUT;
            hcan->State = CAN_STATE_ERROR;

            return CAN_TIMEOUT;
        }
    }

    /* CAN is now operational */
    hcan->State = CAN_STATE_ACTIVE;
    return CAN_OK;
}

/*=========================================================
 * CAN_Stop
 *
 * Enter initialization mode
 *
 * After this function:
 * - CAN stops participating on bus
 * - TX/RX disabled
 * - Registers can be safely reconfigured
 *=========================================================*/
CAN_Status_t CAN_Stop(CAN_Handle_t *hcan)
{
    uint32_t tickstart = SYSTICK_GetTick();

    /* Check NULL handle */
    if (hcan == NULL)
    {
        return CAN_ERROR;
    }

    /* Clear previous error */
    hcan->ErrorCode = CAN_ERROR_NONE;

    /* Check CAN instance */
    if (hcan->Instance == NULL)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /*-----------------------------------------------------
     * Enter initialization mode
     *
     * INRQ = 1
     *----------------------------------------------------*/
    hcan->Instance->MCR |= CAN_MCR_INRQ;

    /* Wait until hardware sets INAK */
    while (!(hcan->Instance->MSR & CAN_MSR_INAK))
    {
        if ((SYSTICK_GetTick() - tickstart) > CAN_TIMEOUT_VALUE)
        {
            hcan->ErrorCode |= CAN_ERROR_TIMEOUT;
            hcan->State = CAN_STATE_ERROR;

            return CAN_TIMEOUT;
        }
    }

    /*-----------------------------------------------------
     * CAN stopped
     *----------------------------------------------------*/
    hcan->State = CAN_STATE_STOPPED;

    return CAN_OK;
}

/*=========================================================
 * CAN_RequestSleep
 *
 * Put CAN peripheral into sleep mode
 *
 * NOTE:
 * - Peripheral stops bus activity
 * - Registers are retained
 *=========================================================*/
CAN_Status_t CAN_RequestSleep(CAN_Handle_t *hcan)
{
    uint32_t tickstart = SYSTICK_GetTick();

    /* Check NULL handle */
    if (hcan == NULL)
    {
        return CAN_ERROR;
    }

    /* Clear previous error */
    hcan->ErrorCode = CAN_ERROR_NONE;

    /* Check instance */
    if (hcan->Instance == NULL)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /*-----------------------------------------------------
     * Request sleep mode
     *
     * SLEEP = 1
     *----------------------------------------------------*/
    hcan->Instance->MCR |= CAN_MCR_SLEEP;

    /* Wait until SLAK set */
    while (!(hcan->Instance->MSR & CAN_MSR_SLAK))
    {
        if ((SYSTICK_GetTick() - tickstart) > CAN_TIMEOUT_VALUE)
        {
            hcan->ErrorCode |= CAN_ERROR_TIMEOUT;
            hcan->State = CAN_STATE_ERROR;

            return CAN_TIMEOUT;
        }
    }

    /* Peripheral is sleeping */
    hcan->State = CAN_STATE_SLEEP;

    return CAN_OK;
}

/*=========================================================
 * CAN_WakeUp
 *
 * Wake CAN peripheral from sleep mode
 *
 * NOTE:
 * This function ONLY leaves sleep mode.
 * CAN still remains in initialization mode
 * until CAN_Start() is called.
 *=========================================================*/
CAN_Status_t CAN_WakeUp(CAN_Handle_t *hcan)
{
    uint32_t tickstart = SYSTICK_GetTick();

    /* Check NULL handle */
    if (hcan == NULL)
    {
        return CAN_ERROR;
    }

    /* Clear previous error */
    hcan->ErrorCode = CAN_ERROR_NONE;

    /* Check instance */
    if (hcan->Instance == NULL)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    /*-----------------------------------------------------
     * Peripheral must be in sleep state
     *----------------------------------------------------*/
    if (hcan->State != CAN_STATE_SLEEP)
    {
        hcan->ErrorCode |= CAN_ERROR_STATE;
        return CAN_ERROR;
    }

    /*-----------------------------------------------------
     * Clear sleep request
     *
     * SLEEP = 0
     *----------------------------------------------------*/
    hcan->Instance->MCR &= ~CAN_MCR_SLEEP;

    /* Wait until SLAK cleared */
    while (hcan->Instance->MSR & CAN_MSR_SLAK)
    {
        if ((SYSTICK_GetTick() - tickstart) > CAN_TIMEOUT_VALUE)
        {
            hcan->ErrorCode |= CAN_ERROR_TIMEOUT;
            hcan->State = CAN_STATE_ERROR;

            return CAN_TIMEOUT;
        }
    }
    /*-----------------------------------------------------
     * Peripheral awake but not started yet
     *----------------------------------------------------*/
    hcan->State = CAN_STATE_STOPPED;

    return CAN_OK;
}

/*=========================================================
 * CAN_Add_TxMessage
 *
 * Add message to Tx mailbox and request transmission
 *
 * NOTE:
 * - User must fill TxFrame structure before calling
 * - This function does NOT check if Tx mailbox is free or not
 *=========================================================*/
CAN_Status_t CAN_Add_TxMessage(CAN_Handle_t *hcan, CAN_TxFrame_t *TxFrame)
{
    if (hcan == NULL || TxFrame == NULL)
    {
        return CAN_ERROR;
    }
    /* Check instance */
    if (hcan->Instance == NULL)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_ERROR;
    }

    // check mailbox availability
    uint8_t available_mailbox = 0xFF; // 0xFF indicates no mailbox available
    if (hcan->Instance->TSR & CAN_TSR_TME0)
    {
        // Maibox[0] is free
        if (TxFrame->IDE == CAN_ID_STANDARD)
        {
            available_mailbox = 0;
            hcan->Instance->sTxMailBox[0].TIR &= ~CAN_TIR_IDE;                      // standard ID
            hcan->Instance->sTxMailBox[0].TIR |= (TxFrame->RTR << CAN_TIR_RTR_Pos); // set RTR bit
            hcan->Instance->sTxMailBox[0].TIR &= ~CAN_TIR_STID;
            hcan->Instance->sTxMailBox[0].TIR |= TxFrame->ID << CAN_TIR_STID_Pos; // set standard ID
        }
        else
        {
            hcan->Instance->sTxMailBox[0].TIR |= CAN_TIR_IDE;                       // extended ID
            hcan->Instance->sTxMailBox[0].TIR |= (TxFrame->RTR << CAN_TIR_RTR_Pos); // set RTR bit
            hcan->Instance->sTxMailBox[0].TIR &= ~CAN_TIR_EXID;
            hcan->Instance->sTxMailBox[0].TIR |= (TxFrame->ID << CAN_TIR_EXID_Pos); // set extended ID
        }
    }
    else if (hcan->Instance->TSR & CAN_TSR_TME1)
    {
        // Mailbox[1] is free
        available_mailbox = 1;
        if (TxFrame->IDE == CAN_ID_STANDARD)
        {
            hcan->Instance->sTxMailBox[1].TIR &= ~CAN_TIR_IDE;                      // standard ID
            hcan->Instance->sTxMailBox[1].TIR |= (TxFrame->RTR << CAN_TIR_RTR_Pos); // set RTR bit
            hcan->Instance->sTxMailBox[1].TIR &= ~CAN_TIR_STID;
            hcan->Instance->sTxMailBox[1].TIR |= TxFrame->ID << CAN_TIR_STID_Pos; // set standard ID
        }
        else
        {
            hcan->Instance->sTxMailBox[1].TIR |= CAN_TIR_IDE;                       // extended ID
            hcan->Instance->sTxMailBox[1].TIR |= (TxFrame->RTR << CAN_TIR_RTR_Pos); // set RTR bit
            hcan->Instance->sTxMailBox[1].TIR &= ~CAN_TIR_EXID;
            hcan->Instance->sTxMailBox[1].TIR |= (TxFrame->ID << CAN_TIR_EXID_Pos); // set extended ID
        }
    }
    else if (hcan->Instance->TSR & CAN_TSR_TME2)
    {
        // Mailbox[2] is free
        available_mailbox = 2;
        if (TxFrame->IDE == CAN_ID_STANDARD)
        {
            hcan->Instance->sTxMailBox[2].TIR &= ~CAN_TIR_IDE;                      // standard ID
            hcan->Instance->sTxMailBox[2].TIR |= (TxFrame->RTR << CAN_TIR_RTR_Pos); // set RTR bit
            hcan->Instance->sTxMailBox[2].TIR &= ~CAN_TIR_STID;
            hcan->Instance->sTxMailBox[2].TIR |= TxFrame->ID << CAN_TIR_STID_Pos; // set standard ID
        }
        else
        {
            hcan->Instance->sTxMailBox[2].TIR |= CAN_TIR_IDE;                       // extended ID
            hcan->Instance->sTxMailBox[2].TIR |= (TxFrame->RTR << CAN_TIR_RTR_Pos); // set RTR bit
            hcan->Instance->sTxMailBox[2].TIR &= ~CAN_TIR_EXID;
            hcan->Instance->sTxMailBox[2].TIR |= (TxFrame->ID << CAN_TIR_EXID_Pos); // set extended ID
        }
    }
    else
    {
        // No mailbox is free
        hcan->ErrorCode |= CAN_ERROR_TX_MAILBOX_FULL;
        return CAN_BUSY;
    }

    // Set DLC and data
    hcan->Instance->sTxMailBox[available_mailbox].TDTR &= ~CAN_TDTR_DLC;
    hcan->Instance->sTxMailBox[available_mailbox].TDTR |= (TxFrame->DLC << CAN_TDTR_DLC_Pos);
    for (uint8_t i = 0; i < TxFrame->DLC; i++)
    {
        if (i < 4)
        {
            hcan->Instance->sTxMailBox[available_mailbox].TDLR &= ~(0xFFU << (8 * i));         // clear previous data
            hcan->Instance->sTxMailBox[available_mailbox].TDLR |= TxFrame->Data[i] << (8 * i); // pack data into TDLR
        }
        else
        {
            hcan->Instance->sTxMailBox[available_mailbox].TDHR &= ~(0xFFU << (8 * (i - 4)));         // clear previous data
            hcan->Instance->sTxMailBox[available_mailbox].TDHR |= TxFrame->Data[i] << (8 * (i - 4)); // pack data into TDHR
        }
    }
    // Request transmission
    hcan->Instance->sTxMailBox[available_mailbox].TIR |= CAN_TIR_TXRQ;
    return CAN_OK;
}

/*CAN get TX mailboxes status*/
CAN_TxMailboxStatus_t CAN_Get_TxMailboxesStatus(CAN_Handle_t *hcan, uint8_t Mailbox)
{
    if (hcan == NULL)
    {
        return CAN_TX_MAILBOX_INVALID;
    }
    // Check instance
    if (hcan->Instance == NULL)
    {
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_TX_MAILBOX_INVALID;
    }

    switch (Mailbox)
    {
    case CAN_TX_MAILBOX_0:
        if (hcan->Instance->TSR & CAN_TSR_RQCP0)
        {
            if (hcan->Instance->TSR & CAN_TSR_TXOK0)
            {
                // transmission successful
                hcan->Instance->TSR |= CAN_TSR_RQCP0; // clear RQCP0 by writing 1
                return CAN_TX_MAILBOX_SUCCESS;
            }
            else
            {
                // check error code
                if (hcan->Instance->TSR & CAN_TSR_TERR0)
                {
                    hcan->ErrorCode |= CAN_ERROR_STATE;
                }
                // check specific error type in ESR
                /*if REC or TEC >= 128 --> error passive*/
                if (hcan->Instance->ESR & CAN_ESR_EPVF)
                {
                    hcan->ErrorCode |= CAN_ERROR_PASSIVE;
                }
                /*if REC or TEC  >= 96 --> warning state*/
                if (hcan->Instance->ESR & CAN_ESR_EWGF)
                {
                    hcan->ErrorCode |= CAN_ERROR_WARNING;
                }
                /*if TEC >= 256 --> bus off*/
                if (hcan->Instance->ESR & CAN_ESR_BOFF)
                {
                    hcan->ErrorCode |= CAN_ERROR_BUS_OFF;
                }

                if (hcan->Instance->ESR & CAN_ESR_LEC_Msk)
                {
                    uint32_t lec = (hcan->Instance->ESR & CAN_ESR_LEC_Msk) >> CAN_ESR_LEC_Pos;
                    switch (lec)
                    {
                    case 0x1:
                        hcan->ErrorCode |= CAN_ERROR_STUFF;
                        break;
                    case 0x2:
                        hcan->ErrorCode |= CAN_ERROR_FORM;
                        break;
                    case 0x3:
                        hcan->ErrorCode |= CAN_ERROR_ACK;
                        break;
                    case 0x4:
                        hcan->ErrorCode |= CAN_ERROR_BIT_RECESSIVE;
                        break;
                    case 0x5:
                        hcan->ErrorCode |= CAN_ERROR_BIT_DOMINANT;
                        break;
                    case 0x6:
                        hcan->ErrorCode |= CAN_ERROR_CRC;
                        break;
                    default:
                        break;
                    }
                }
                return CAN_TX_MAILBOX_FAILED;
            }
        }
        else
        {
            return CAN_TX_MAILBOX_PENDING;
        }
        break;
    /*Mailbox1*/
    case CAN_TX_MAILBOX_1:
        if (hcan->Instance->TSR & CAN_TSR_RQCP1)
        {
            if (hcan->Instance->TSR & CAN_TSR_TXOK1)
            {
                // transmission successful
                hcan->Instance->TSR |= CAN_TSR_RQCP1; // clear RQCP1 by writing 1
                return CAN_TX_MAILBOX_SUCCESS;
            }
            else
            {
                hcan->Instance->TSR |= CAN_TSR_RQCP1; // clear RQCP1 by writing 1
                // check error code
                if (hcan->Instance->TSR & CAN_TSR_TERR1)
                {
                    hcan->ErrorCode |= CAN_ERROR_STATE;
                }
                // check specific error type in ESR
                /*if REC or TEC >= 128 --> error passive*/
                if (hcan->Instance->ESR & CAN_ESR_EPVF)
                {
                    hcan->ErrorCode |= CAN_ERROR_PASSIVE;
                }
                /*if REC or TEC  >= 96 --> warning state*/
                if (hcan->Instance->ESR & CAN_ESR_EWGF)
                {
                    hcan->ErrorCode |= CAN_ERROR_WARNING;
                }
                /*if TEC >= 256 --> bus off*/
                if (hcan->Instance->ESR & CAN_ESR_BOFF)
                {
                    hcan->ErrorCode |= CAN_ERROR_BUS_OFF;
                }

                if (hcan->Instance->ESR & CAN_ESR_LEC_Msk)
                {
                    uint32_t lec = (hcan->Instance->ESR & CAN_ESR_LEC_Msk) >> CAN_ESR_LEC_Pos;
                    switch (lec)
                    {
                    case 0x1:
                        hcan->ErrorCode |= CAN_ERROR_STUFF;
                        break;
                    case 0x2:
                        hcan->ErrorCode |= CAN_ERROR_FORM;
                        break;
                    case 0x3:
                        hcan->ErrorCode |= CAN_ERROR_ACK;
                        break;
                    case 0x4:
                        hcan->ErrorCode |= CAN_ERROR_BIT_RECESSIVE;
                        break;
                    case 0x5:
                        hcan->ErrorCode |= CAN_ERROR_BIT_DOMINANT;
                        break;
                    case 0x6:
                        hcan->ErrorCode |= CAN_ERROR_CRC;
                        break;
                    default:
                        break;
                    }
                }
                return CAN_TX_MAILBOX_FAILED;
            }
        }
        else
        {
            return CAN_TX_MAILBOX_PENDING;
        }
        break;
    /*Mailbox2*/
    case CAN_TX_MAILBOX_2:
        if (hcan->Instance->TSR & CAN_TSR_RQCP2)
        {
            if (hcan->Instance->TSR & CAN_TSR_TXOK2)
            {
                // transmission successful
                hcan->Instance->TSR |= CAN_TSR_RQCP2; // clear RQCP2 by writing 1
                return CAN_TX_MAILBOX_SUCCESS;
            }
            else
            {
                // check error code
                if (hcan->Instance->TSR & CAN_TSR_TERR2)
                {
                    hcan->ErrorCode |= CAN_ERROR_STATE;
                }
                // check specific error type in ESR
                /*if REC or TEC >= 128 --> error passive*/
                if (hcan->Instance->ESR & CAN_ESR_EPVF)
                {
                    hcan->ErrorCode |= CAN_ERROR_PASSIVE;
                }
                /*if REC or TEC  >= 96 --> warning state*/
                if (hcan->Instance->ESR & CAN_ESR_EWGF)
                {
                    hcan->ErrorCode |= CAN_ERROR_WARNING;
                }
                /*if TEC >= 256 --> bus off*/
                if (hcan->Instance->ESR & CAN_ESR_BOFF)
                {
                    hcan->ErrorCode |= CAN_ERROR_BUS_OFF;
                }

                if (hcan->Instance->ESR & CAN_ESR_LEC_Msk)
                {
                    uint32_t lec = (hcan->Instance->ESR & CAN_ESR_LEC_Msk) >> CAN_ESR_LEC_Pos;
                    switch (lec)
                    {
                    case 0x1:
                        hcan->ErrorCode |= CAN_ERROR_STUFF;
                        break;
                    case 0x2:
                        hcan->ErrorCode |= CAN_ERROR_FORM;
                        break;
                    case 0x3:
                        hcan->ErrorCode |= CAN_ERROR_ACK;
                        break;
                    case 0x4:
                        hcan->ErrorCode |= CAN_ERROR_BIT_RECESSIVE;
                        break;
                    case 0x5:
                        hcan->ErrorCode |= CAN_ERROR_BIT_DOMINANT;
                        break;
                    case 0x6:
                        hcan->ErrorCode |= CAN_ERROR_CRC;
                        break;
                    default:
                        break;
                    }
                }
                hcan->Instance->TSR |= CAN_TSR_RQCP2; // clear RQCP2 by writing 1
                return CAN_TX_MAILBOX_FAILED;
            }
        }
        else
        {
            return CAN_TX_MAILBOX_PENDING;
        }
        break;

    default:
        hcan->ErrorCode |= CAN_ERROR_PARAM;
        return CAN_TX_MAILBOX_INVALID;
    }
}
/*---------------------------------------End CAN get status of tx mailboxes---------------------------------------*/

