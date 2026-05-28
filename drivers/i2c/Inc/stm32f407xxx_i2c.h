#ifndef __STM32F407XXX_I2C_H
#define __STM32F407XXX_I2C_H

#include "stm32f407xxx.h"

/* =========================================================
 * I2C_CR1
 * ========================================================= */
#define I2C_CR1_PE_Pos                         0U
#define I2C_CR1_PE                             (1U << I2C_CR1_PE_Pos)

#define I2C_CR1_SMBUS_Pos                     1U
#define I2C_CR1_SMBUS                         (1U << I2C_CR1_SMBUS_Pos)

#define I2C_CR1_SMBTYPE_Pos                   3U
#define I2C_CR1_SMBTYPE                       (1U << I2C_CR1_SMBTYPE_Pos)

#define I2C_CR1_ENARP_Pos                     4U
#define I2C_CR1_ENARP                         (1U << I2C_CR1_ENARP_Pos)

#define I2C_CR1_ENPEC_Pos                     5U
#define I2C_CR1_ENPEC                         (1U << I2C_CR1_ENPEC_Pos)

#define I2C_CR1_ENGC_Pos                      6U
#define I2C_CR1_ENGC                          (1U << I2C_CR1_ENGC_Pos)

#define I2C_CR1_NOSTRETCH_Pos                 7U
#define I2C_CR1_NOSTRETCH                     (1U << I2C_CR1_NOSTRETCH_Pos)

#define I2C_CR1_START_Pos                     8U
#define I2C_CR1_START                         (1U << I2C_CR1_START_Pos)

#define I2C_CR1_STOP_Pos                      9U
#define I2C_CR1_STOP                          (1U << I2C_CR1_STOP_Pos)

#define I2C_CR1_ACK_Pos                       10U
#define I2C_CR1_ACK                           (1U << I2C_CR1_ACK_Pos)

#define I2C_CR1_POS_Pos                       11U
#define I2C_CR1_POS                           (1U << I2C_CR1_POS_Pos)

#define I2C_CR1_PEC_Pos                       12U
#define I2C_CR1_PEC                           (1U << I2C_CR1_PEC_Pos)

#define I2C_CR1_ALERT_Pos                     13U
#define I2C_CR1_ALERT                         (1U << I2C_CR1_ALERT_Pos)

#define I2C_CR1_SWRST_Pos                     15U
#define I2C_CR1_SWRST                         (1U << I2C_CR1_SWRST_Pos)

/* =========================================================
 * I2C_CR2
 * ========================================================= */
#define I2C_CR2_FREQ_Pos                      0U
#define I2C_CR2_FREQ_Msk                      (0x3FU << I2C_CR2_FREQ_Pos)

#define I2C_CR2_ITERREN_Pos                   8U
#define I2C_CR2_ITERREN                       (1U << I2C_CR2_ITERREN_Pos)

#define I2C_CR2_ITEVTEN_Pos                   9U
#define I2C_CR2_ITEVTEN                       (1U << I2C_CR2_ITEVTEN_Pos)

#define I2C_CR2_ITBUFEN_Pos                   10U
#define I2C_CR2_ITBUFEN                       (1U << I2C_CR2_ITBUFEN_Pos)

#define I2C_CR2_DMAEN_Pos                     11U
#define I2C_CR2_DMAEN                         (1U << I2C_CR2_DMAEN_Pos)

#define I2C_CR2_LAST_Pos                      12U
#define I2C_CR2_LAST                          (1U << I2C_CR2_LAST_Pos)

/* =========================================================
 * I2C_OAR1
 * ========================================================= */
#define I2C_OAR1_ADD0_Pos                     0U
#define I2C_OAR1_ADD0                         (1U << I2C_OAR1_ADD0_Pos)

#define I2C_OAR1_ADD71_Pos                    1U
#define I2C_OAR1_ADD71_Msk                    (0x7FU << I2C_OAR1_ADD71_Pos)

#define I2C_OAR1_ADD98_Pos                    8U
#define I2C_OAR1_ADD98_Msk                    (0x3U << I2C_OAR1_ADD98_Pos)

#define I2C_OAR1_ADDMODE_Pos                  15U
#define I2C_OAR1_ADDMODE                      (1U << I2C_OAR1_ADDMODE_Pos)

/* =========================================================
 * I2C_OAR2
 * ========================================================= */
#define I2C_OAR2_ENDUAL_Pos                   0U
#define I2C_OAR2_ENDUAL                       (1U << I2C_OAR2_ENDUAL_Pos)

#define I2C_OAR2_ADD2_Pos                     1U
#define I2C_OAR2_ADD2_Msk                     (0x7FU << I2C_OAR2_ADD2_Pos)

/* =========================================================
 * I2C_DR
 * ========================================================= */
#define I2C_DR_DR_Pos                         0U
#define I2C_DR_DR_Msk                         (0xFFU << I2C_DR_DR_Pos)

/* =========================================================
 * I2C_SR1
 * ========================================================= */
#define I2C_SR1_SB_Pos                        0U
#define I2C_SR1_SB                            (1U << I2C_SR1_SB_Pos)

#define I2C_SR1_ADDR_Pos                      1U
#define I2C_SR1_ADDR                          (1U << I2C_SR1_ADDR_Pos)

#define I2C_SR1_BTF_Pos                       2U
#define I2C_SR1_BTF                           (1U << I2C_SR1_BTF_Pos)

#define I2C_SR1_ADD10_Pos                     3U
#define I2C_SR1_ADD10                         (1U << I2C_SR1_ADD10_Pos)

#define I2C_SR1_STOPF_Pos                     4U
#define I2C_SR1_STOPF                         (1U << I2C_SR1_STOPF_Pos)

#define I2C_SR1_RXNE_Pos                      6U
#define I2C_SR1_RXNE                          (1U << I2C_SR1_RXNE_Pos)

#define I2C_SR1_TXE_Pos                       7U
#define I2C_SR1_TXE                           (1U << I2C_SR1_TXE_Pos)

#define I2C_SR1_BERR_Pos                      8U
#define I2C_SR1_BERR                          (1U << I2C_SR1_BERR_Pos)

#define I2C_SR1_ARLO_Pos                      9U
#define I2C_SR1_ARLO                          (1U << I2C_SR1_ARLO_Pos)

#define I2C_SR1_AF_Pos                        10U
#define I2C_SR1_AF                            (1U << I2C_SR1_AF_Pos)

#define I2C_SR1_OVR_Pos                       11U
#define I2C_SR1_OVR                           (1U << I2C_SR1_OVR_Pos)

#define I2C_SR1_PECERR_Pos                    12U
#define I2C_SR1_PECERR                        (1U << I2C_SR1_PECERR_Pos)

#define I2C_SR1_TIMEOUT_Pos                   14U
#define I2C_SR1_TIMEOUT                       (1U << I2C_SR1_TIMEOUT_Pos)

#define I2C_SR1_SMBALERT_Pos                  15U
#define I2C_SR1_SMBALERT                      (1U << I2C_SR1_SMBALERT_Pos)

/* =========================================================
 * I2C_SR2
 * ========================================================= */
#define I2C_SR2_MSL_Pos                       0U
#define I2C_SR2_MSL                           (1U << I2C_SR2_MSL_Pos)

#define I2C_SR2_BUSY_Pos                      1U
#define I2C_SR2_BUSY                          (1U << I2C_SR2_BUSY_Pos)

#define I2C_SR2_TRA_Pos                       2U
#define I2C_SR2_TRA                           (1U << I2C_SR2_TRA_Pos)

#define I2C_SR2_GENCALL_Pos                   4U
#define I2C_SR2_GENCALL                       (1U << I2C_SR2_GENCALL_Pos)

#define I2C_SR2_SMBDEFAULT_Pos                5U
#define I2C_SR2_SMBDEFAULT                    (1U << I2C_SR2_SMBDEFAULT_Pos)

#define I2C_SR2_SMBHOST_Pos                   6U
#define I2C_SR2_SMBHOST                       (1U << I2C_SR2_SMBHOST_Pos)

#define I2C_SR2_DUALF_Pos                     7U
#define I2C_SR2_DUALF                         (1U << I2C_SR2_DUALF_Pos)

#define I2C_SR2_PEC_Pos                       8U
#define I2C_SR2_PEC_Msk                       (0xFFU << I2C_SR2_PEC_Pos)

/* =========================================================
 * I2C_CCR
 * ========================================================= */
#define I2C_CCR_CCR_Pos                       0U
#define I2C_CCR_CCR_Msk                       (0xFFFU << I2C_CCR_CCR_Pos)

#define I2C_CCR_DUTY_Pos                      14U
#define I2C_CCR_DUTY                          (1U << I2C_CCR_DUTY_Pos)

#define I2C_CCR_FS_Pos                        15U
#define I2C_CCR_FS                            (1U << I2C_CCR_FS_Pos)

/* =========================================================
 * I2C_TRISE
 * ========================================================= */
#define I2C_TRISE_TRISE_Pos                   0U
#define I2C_TRISE_TRISE_Msk                   (0x3FU << I2C_TRISE_TRISE_Pos)

/* =========================================================
 * I2C_FLTR
 * ========================================================= */
#define I2C_FLTR_DNF_Pos                      0U
#define I2C_FLTR_DNF_Msk                      (0xFU << I2C_FLTR_DNF_Pos)

#define I2C_FLTR_ANOFF_Pos                    4U
#define I2C_FLTR_ANOFF                        (1U << I2C_FLTR_ANOFF_Pos)

#define I2C_MODE_STANDARD              0U
#define I2C_MODE_FAST                  1U

#define I2C_CLOCK_SPEED_50KHz     50000U
#define I2C_CLOCK_SPEED_100KHz    100000U
#define I2C_CLOCK_SPEED_150kHz    150000U
#define I2C_CLOCK_SPEED_200kHz    200000U
#define I2C_CLOCK_SPEED_250kHz    250000U
#define I2C_CLOCK_SPEED_300kHz    300000U
#define I2C_CLOCK_SPEED_350kHz    350000U
#define I2C_CLOCK_SPEED_400kHz    400000U

#define I2C_ADDRESSINGMODE_7BIT   0U
#define I2C_ADDRESSINGMODE_10BIT  1U

#define I2C_DUTY_CYCLE_2     0U
#define I2C_DUTY_CYCLE_16_9  1U


typedef enum{
    I2C_OK = 0U,
    I2C_ERROR,
    I2C_BUSY,
    I2C_TIMEOUT
} I2C_Status_t;

/*> Define struct for init I2C */
typedef struct{
    uint32_t ClockSpeed;         /* Specifies the clock frequency. */
    uint16_t OwnAddress1;        /* Specifies the first device own address. */
    uint16_t OwnAddress2;        /* Specifies the second device own address (not used in 7-bit addressing mode). */
    uint16_t DualAddressMode;    /* Specifies whether dual addressing mode is enabled or disabled. */
    uint16_t GeneralCallMode;    /* Specifies whether general call mode is enabled or disabled. */
    uint16_t NoStretchMode;      /* Specifies whether clock stretching is enabled or disabled. */
    uint8_t  Mode;               /* Specifies whether the I2C in standard mode (100 kHz) or fast mode (400 kHz). */
    uint8_t  AddressingMode;     /* Specifies the addressing mode (7-bit or 10-bit). */
    uint8_t  FastModeDutyCycle;  /* Specifies the duty cycle to be used in fast mode. */
} I2C_Config_t;

typedef struct{
    I2C_Reg_TypeDef_t *Instance;    /* Register base address. */
    I2C_Config_t Init;              /* I2C communication parameters. */
} I2C_Handle_t;


/*< Function prototypes */
I2C_Status_t I2C_Init(I2C_Handle_t *hi2c);
I2C_Status_t I2C_Start(I2C_Handle_t *hi2c);
I2C_Status_t I2C_Stop(I2C_Handle_t *hi2c);

I2C_Status_t I2C_Master_Transmit(I2C_Handle_t *hi2c, uint8_t DevAddress,
                                 uint8_t *pData, uint16_t Size, uint32_t Timeout);  

I2C_Status_t I2C_Master_Receive(I2C_Handle_t *hi2c, uint8_t DevAddress,
                                uint8_t *pData, uint16_t Size, uint32_t Timeout);

#endif // __STM32F407XXX_I2C_H  