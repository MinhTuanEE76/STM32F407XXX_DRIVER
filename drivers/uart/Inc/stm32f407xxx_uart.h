#ifndef __STM32F407XXX_UART_H
#define __STM32F407XXX_UART_H

#include "stm32f407xxx.h"


/* ============================================================
 * USART_SR
 * Status Register
 * ============================================================
 */
#define USART_SR_PE                     (1U << 0)
#define USART_SR_FE                     (1U << 1)
#define USART_SR_NE                     (1U << 2)
#define USART_SR_ORE                    (1U << 3)
#define USART_SR_IDLE                   (1U << 4)
#define USART_SR_RXNE                   (1U << 5)
#define USART_SR_TC                     (1U << 6)
#define USART_SR_TXE                    (1U << 7)
#define USART_SR_LBD                    (1U << 8)
#define USART_SR_CTS                    (1U << 9)

/* ============================================================
 * USART_DR
 * Data Register
 * ============================================================
 */
#define USART_DR_DR                     (0x1FFU << 0)

/* ============================================================
 * USART_BRR
 * Baud Rate Register
 * ============================================================
 */
#define USART_BRR_DIV_FRACTION          (0xFU << 0)
#define USART_BRR_DIV_MANTISSA          (0xFFFU << 4)

/* ============================================================
 * USART_CR1
 * Control Register 1
 * ============================================================
 */
#define USART_CR1_SBK                   (1U << 0)
#define USART_CR1_RWU                   (1U << 1)
#define USART_CR1_RE                    (1U << 2)
#define USART_CR1_TE                    (1U << 3)
#define USART_CR1_IDLEIE                (1U << 4)
#define USART_CR1_RXNEIE                (1U << 5)
#define USART_CR1_TCIE                  (1U << 6)
#define USART_CR1_TXEIE                 (1U << 7)
#define USART_CR1_PEIE                  (1U << 8)
#define USART_CR1_PS                    (1U << 9)
#define USART_CR1_PCE                   (1U << 10)
#define USART_CR1_WAKE                  (1U << 11)
#define USART_CR1_M                     (1U << 12)
#define USART_CR1_UE                    (1U << 13)
#define USART_CR1_OVER8                 (1U << 15)

/* ============================================================
 * USART_CR2
 * Control Register 2
 * ============================================================
 */
#define USART_CR2_ADD                   (0xFU << 0)

#define USART_CR2_LBDL                  (1U << 5)
#define USART_CR2_LBDIE                 (1U << 6)

#define USART_CR2_LBCL                  (1U << 8)
#define USART_CR2_CPHA                  (1U << 9)
#define USART_CR2_CPOL                  (1U << 10)
#define USART_CR2_CLKEN                 (1U << 11)

#define USART_CR2_STOP                  (0x3U << 12)

#define USART_CR2_LINEN                 (1U << 14)

/* ============================================================
 * USART_CR3
 * Control Register 3
 * ============================================================
 */
#define USART_CR3_EIE                   (1U << 0)
#define USART_CR3_IREN                  (1U << 1)
#define USART_CR3_IRLP                  (1U << 2)
#define USART_CR3_HDSEL                 (1U << 3)
#define USART_CR3_NACK                  (1U << 4)
#define USART_CR3_SCEN                  (1U << 5)
#define USART_CR3_DMAR                  (1U << 6)
#define USART_CR3_DMAT                  (1U << 7)
#define USART_CR3_RTSE                  (1U << 8)
#define USART_CR3_CTSE                  (1U << 9)
#define USART_CR3_CTSIE                 (1U << 10)
#define USART_CR3_ONEBIT                (1U << 11)

/* ============================================================
 * USART_GTPR
 * Guard Time and Prescaler Register
 * ============================================================
 */
#define USART_GTPR_PSC                  (0xFFU << 0)
#define USAR

#define USART_BAUDRATE_9600                    9600U
#define USART_BAUDRATE_19200                   19200U
#define USART_BAUDRATE_38400                   38400U
#define USART_BAUDRATE_57600                   57600U
#define USART_BAUDRATE_115200                  115200U

#define USART_WORD_LENGTH_8BITS                   0U
#define USART_WORD_LENGTH_9BITS                   1U

#define USART_PARITY_NONE                         0U
#define USART_PARITY_ODD                          1U
#define USART_PARITY_EVEN                         2U

#define USART_MODE_TX                             0U
#define USART_MODE_RX                             1U
#define USART_MODE_TX_RX                          2U

#define USART_OVERSAMPLING_16                     0U
#define USART_OVERSAMPLING_8                      1U

#define USART_STOPBITS_1                         0U
#define USART_STOPBITS_0_5                       1U
#define USART_STOPBITS_2                         2U
#define USART_STOPBITS_1_5                       3U


#define USART_TX_BUSY                                1U
#define USART_RX_BUSY                                1U
#define USART_TX_READY                               0U
#define USART_RX_READY                               0U


/*typedef struct config usart */
typedef struct{
    uint32_t Baudrate;
    uint8_t WordLength;                //This bit determines the word length 0: 8bit data ; 1: 9bit data
    uint8_t Parity;                    //0: no parity ; 1: even parity ; 2: odd parity
    uint8_t StopBits;                  //0: 1 stop bit 
    uint8_t Mode;   
    uint8_t OverSampling;              //0: oversampling by 16 ; 1: oversampling by 8                   
} USART_Config_t;

/*
    Baudrate -> BRR
    Wordlength -> M in CR1
    Mode -> TE,RE in CR1
    Parity -> PS, PCE in CR1
    Oversampling -> OVER8 in CR1

*/
typedef struct
{
    USART_Reg_TypeDef_t *Instance;

    USART_Config_t *Config;

    uint8_t *pTxBuffer;
    uint8_t *pRxBuffer;

    uint32_t TxLen;
    uint32_t RxLen;

    volatile uint8_t TxState;
    volatile uint8_t RxState;

    void (*TxCompleteCallback)(void);
    void (*RxCompleteCallback)(void);

} USART_Handle_t;

/*--------------------------------Function Prototype---------------------------------*/
void USART_Init(USART_Handle_t *huart);
void USART_Transmit_Polling(USART_Handle_t *huart,uint8_t *pTxBuffer,uint32_t Len);
void USART_Receive_Polling(USART_Handle_t *huart,uint8_t *pRxBuffer, uint32_t Len);

void USART_Transmit_IT(USART_Handle_t *huart,uint8_t *pTxBuffer,uint32_t Len);
void USART_Receive_IT(USART_Handle_t *huart,uint8_t *pRxBuffer, uint32_t Len);

void USART_IRQHandler(USART_Handle_t *huart);

#endif

