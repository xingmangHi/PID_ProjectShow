/*
 * Copyright (c) 2023, Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ============ ti_msp_dl_config.h =============
 *  Configured MSPM0 DriverLib module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSPM0G350X
 *  by the SysConfig tool.
 */
#ifndef ti_msp_dl_config_h
#define ti_msp_dl_config_h

#define CONFIG_MSPM0G350X

#if defined(__ti_version__) || defined(__TI_COMPILER_VERSION__)
#define SYSCONFIG_WEAK __attribute__((weak))
#elif defined(__IAR_SYSTEMS_ICC__)
#define SYSCONFIG_WEAK __weak
#elif defined(__GNUC__)
#define SYSCONFIG_WEAK __attribute__((weak))
#endif

#include <ti/devices/msp/msp.h>
#include <ti/driverlib/driverlib.h>
#include <ti/driverlib/m0p/dl_core.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 *  ======== SYSCFG_DL_init ========
 *  Perform all required MSP DL initialization
 *
 *  This function should be called once at a point before any use of
 *  MSP DL.
 */


/* clang-format off */

#define POWER_STARTUP_DELAY                                                (16)


#define GPIO_HFXT_PORT                                                     GPIOA
#define GPIO_HFXIN_PIN                                             DL_GPIO_PIN_5
#define GPIO_HFXIN_IOMUX                                         (IOMUX_PINCM10)
#define GPIO_HFXOUT_PIN                                            DL_GPIO_PIN_6
#define GPIO_HFXOUT_IOMUX                                        (IOMUX_PINCM11)
#define CPUCLK_FREQ                                                     80000000



/* Defines for PWM_MOTOR_1 */
#define PWM_MOTOR_1_INST                                                   TIMG7
#define PWM_MOTOR_1_INST_IRQHandler                             TIMG7_IRQHandler
#define PWM_MOTOR_1_INST_INT_IRQN                               (TIMG7_INT_IRQn)
#define PWM_MOTOR_1_INST_CLK_FREQ                                       10000000
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_1_C1_PORT                                           GPIOA
#define GPIO_PWM_MOTOR_1_C1_PIN                                   DL_GPIO_PIN_24
#define GPIO_PWM_MOTOR_1_C1_IOMUX                                (IOMUX_PINCM54)
#define GPIO_PWM_MOTOR_1_C1_IOMUX_FUNC               IOMUX_PINCM54_PF_TIMG7_CCP1
#define GPIO_PWM_MOTOR_1_C1_IDX                              DL_TIMER_CC_1_INDEX

/* Defines for PWM_MOTOR_2 */
#define PWM_MOTOR_2_INST                                                  TIMG12
#define PWM_MOTOR_2_INST_IRQHandler                            TIMG12_IRQHandler
#define PWM_MOTOR_2_INST_INT_IRQN                              (TIMG12_INT_IRQn)
#define PWM_MOTOR_2_INST_CLK_FREQ                                       10000000
/* GPIO defines for channel 1 */
#define GPIO_PWM_MOTOR_2_C1_PORT                                           GPIOA
#define GPIO_PWM_MOTOR_2_C1_PIN                                   DL_GPIO_PIN_25
#define GPIO_PWM_MOTOR_2_C1_IOMUX                                (IOMUX_PINCM55)
#define GPIO_PWM_MOTOR_2_C1_IOMUX_FUNC              IOMUX_PINCM55_PF_TIMG12_CCP1
#define GPIO_PWM_MOTOR_2_C1_IDX                              DL_TIMER_CC_1_INDEX

/* Defines for PWM_TEST */
#define PWM_TEST_INST                                                      TIMG6
#define PWM_TEST_INST_IRQHandler                                TIMG6_IRQHandler
#define PWM_TEST_INST_INT_IRQN                                  (TIMG6_INT_IRQn)
#define PWM_TEST_INST_CLK_FREQ                                          10000000
/* GPIO defines for channel 1 */
#define GPIO_PWM_TEST_C1_PORT                                              GPIOA
#define GPIO_PWM_TEST_C1_PIN                                      DL_GPIO_PIN_22
#define GPIO_PWM_TEST_C1_IOMUX                                   (IOMUX_PINCM47)
#define GPIO_PWM_TEST_C1_IOMUX_FUNC                  IOMUX_PINCM47_PF_TIMG6_CCP1
#define GPIO_PWM_TEST_C1_IDX                                 DL_TIMER_CC_1_INDEX

/* Defines for PWM_WS2812 */
#define PWM_WS2812_INST                                                    TIMA1
#define PWM_WS2812_INST_IRQHandler                              TIMA1_IRQHandler
#define PWM_WS2812_INST_INT_IRQN                                (TIMA1_INT_IRQn)
#define PWM_WS2812_INST_CLK_FREQ                                        20000000
/* GPIO defines for channel 0 */
#define GPIO_PWM_WS2812_C0_PORT                                            GPIOA
#define GPIO_PWM_WS2812_C0_PIN                                    DL_GPIO_PIN_28
#define GPIO_PWM_WS2812_C0_IOMUX                                  (IOMUX_PINCM3)
#define GPIO_PWM_WS2812_C0_IOMUX_FUNC                 IOMUX_PINCM3_PF_TIMA1_CCP0
#define GPIO_PWM_WS2812_C0_IDX                               DL_TIMER_CC_0_INDEX



/* Defines for TIMER_SCAN */
#define TIMER_SCAN_INST                                                  (TIMA0)
#define TIMER_SCAN_INST_IRQHandler                              TIMA0_IRQHandler
#define TIMER_SCAN_INST_INT_IRQN                                (TIMA0_INT_IRQn)
#define TIMER_SCAN_INST_LOAD_VALUE                                      (19999U)



/* Defines for UART_0 */
#define UART_0_INST                                                        UART0
#define UART_0_INST_IRQHandler                                  UART0_IRQHandler
#define UART_0_INST_INT_IRQN                                      UART0_INT_IRQn
#define GPIO_UART_0_RX_PORT                                                GPIOA
#define GPIO_UART_0_TX_PORT                                                GPIOA
#define GPIO_UART_0_RX_PIN                                        DL_GPIO_PIN_11
#define GPIO_UART_0_TX_PIN                                        DL_GPIO_PIN_10
#define GPIO_UART_0_IOMUX_RX                                     (IOMUX_PINCM22)
#define GPIO_UART_0_IOMUX_TX                                     (IOMUX_PINCM21)
#define GPIO_UART_0_IOMUX_RX_FUNC                      IOMUX_PINCM22_PF_UART0_RX
#define GPIO_UART_0_IOMUX_TX_FUNC                      IOMUX_PINCM21_PF_UART0_TX
#define UART_0_BAUD_RATE                                                  (9600)
#define UART_0_IBRD_4_MHZ_9600_BAUD                                         (26)
#define UART_0_FBRD_4_MHZ_9600_BAUD                                          (3)





/* Defines for DMA_WS2812 */
#define DMA_WS2812_CHAN_ID                                                   (0)
#define DMA_WS2812_TRIGGER_SEL_SW                            (DMA_SOFTWARE_TRIG)



/* Port definition for Pin Group MDR */
#define MDR_PORT                                                         (GPIOA)

/* Defines for MDR_1: GPIOA.17 with pinCMx 39 on package pin 10 */
#define MDR_MDR_1_PIN                                           (DL_GPIO_PIN_17)
#define MDR_MDR_1_IOMUX                                          (IOMUX_PINCM39)
/* Defines for MDR_2: GPIOA.18 with pinCMx 40 on package pin 11 */
#define MDR_MDR_2_PIN                                           (DL_GPIO_PIN_18)
#define MDR_MDR_2_IOMUX                                          (IOMUX_PINCM40)
/* Defines for MDR_3: GPIOA.16 with pinCMx 38 on package pin 9 */
#define MDR_MDR_3_PIN                                           (DL_GPIO_PIN_16)
#define MDR_MDR_3_IOMUX                                          (IOMUX_PINCM38)
/* Defines for MDR_4: GPIOA.15 with pinCMx 37 on package pin 8 */
#define MDR_MDR_4_PIN                                           (DL_GPIO_PIN_15)
#define MDR_MDR_4_IOMUX                                          (IOMUX_PINCM37)
/* Port definition for Pin Group MOTOR */
#define MOTOR_PORT                                                       (GPIOA)

/* Defines for MOTOR_A: GPIOA.26 with pinCMx 59 on package pin 30 */
// pins affected by this interrupt request:["MOTOR_A","MOTOR_B"]
#define MOTOR_INT_IRQN                                          (GPIOA_INT_IRQn)
#define MOTOR_INT_IIDX                          (DL_INTERRUPT_GROUP1_IIDX_GPIOA)
#define MOTOR_MOTOR_A_IIDX                                  (DL_GPIO_IIDX_DIO26)
#define MOTOR_MOTOR_A_PIN                                       (DL_GPIO_PIN_26)
#define MOTOR_MOTOR_A_IOMUX                                      (IOMUX_PINCM59)
/* Defines for MOTOR_B: GPIOA.27 with pinCMx 60 on package pin 31 */
#define MOTOR_MOTOR_B_IIDX                                  (DL_GPIO_IIDX_DIO27)
#define MOTOR_MOTOR_B_PIN                                       (DL_GPIO_PIN_27)
#define MOTOR_MOTOR_B_IOMUX                                      (IOMUX_PINCM60)
/* Port definition for Pin Group KEY */
#define KEY_PORT                                                         (GPIOB)

/* Defines for KEY_UP: GPIOB.24 with pinCMx 52 on package pin 23 */
#define KEY_KEY_UP_PIN                                          (DL_GPIO_PIN_24)
#define KEY_KEY_UP_IOMUX                                         (IOMUX_PINCM52)
/* Defines for KEY_DOWN: GPIOB.9 with pinCMx 26 on package pin 61 */
#define KEY_KEY_DOWN_PIN                                         (DL_GPIO_PIN_9)
#define KEY_KEY_DOWN_IOMUX                                       (IOMUX_PINCM26)
/* Defines for KEY_LEFT: GPIOB.8 with pinCMx 25 on package pin 60 */
#define KEY_KEY_LEFT_PIN                                         (DL_GPIO_PIN_8)
#define KEY_KEY_LEFT_IOMUX                                       (IOMUX_PINCM25)
/* Defines for KEY_RIGHT: GPIOB.20 with pinCMx 48 on package pin 19 */
#define KEY_KEY_RIGHT_PIN                                       (DL_GPIO_PIN_20)
#define KEY_KEY_RIGHT_IOMUX                                      (IOMUX_PINCM48)
/* Port definition for Pin Group OLED_A */
#define OLED_A_PORT                                                      (GPIOA)

/* Defines for SPI_PICO: GPIOA.9 with pinCMx 20 on package pin 55 */
#define OLED_A_SPI_PICO_PIN                                      (DL_GPIO_PIN_9)
#define OLED_A_SPI_PICO_IOMUX                                    (IOMUX_PINCM20)
/* Defines for SPI_CS0: GPIOA.8 with pinCMx 19 on package pin 54 */
#define OLED_A_SPI_CS0_PIN                                       (DL_GPIO_PIN_8)
#define OLED_A_SPI_CS0_IOMUX                                     (IOMUX_PINCM19)
/* Port definition for Pin Group OLED_B */
#define OLED_B_PORT                                                      (GPIOB)

/* Defines for SPI_SCK: GPIOB.18 with pinCMx 44 on package pin 15 */
#define OLED_B_SPI_SCK_PIN                                      (DL_GPIO_PIN_18)
#define OLED_B_SPI_SCK_IOMUX                                     (IOMUX_PINCM44)
/* Defines for SPI_PIN1: GPIOB.2 with pinCMx 15 on package pin 50 */
#define OLED_B_SPI_PIN1_PIN                                      (DL_GPIO_PIN_2)
#define OLED_B_SPI_PIN1_IOMUX                                    (IOMUX_PINCM15)
/* Defines for SPI_PIN2: GPIOB.3 with pinCMx 16 on package pin 51 */
#define OLED_B_SPI_PIN2_PIN                                      (DL_GPIO_PIN_3)
#define OLED_B_SPI_PIN2_IOMUX                                    (IOMUX_PINCM16)



/* clang-format on */

void SYSCFG_DL_init(void);
void SYSCFG_DL_initPower(void);
void SYSCFG_DL_GPIO_init(void);
void SYSCFG_DL_SYSCTL_init(void);
void SYSCFG_DL_PWM_MOTOR_1_init(void);
void SYSCFG_DL_PWM_MOTOR_2_init(void);
void SYSCFG_DL_PWM_TEST_init(void);
void SYSCFG_DL_PWM_WS2812_init(void);
void SYSCFG_DL_TIMER_SCAN_init(void);
void SYSCFG_DL_UART_0_init(void);
void SYSCFG_DL_DMA_init(void);

void SYSCFG_DL_SYSTICK_init(void);

bool SYSCFG_DL_saveConfiguration(void);
bool SYSCFG_DL_restoreConfiguration(void);

#ifdef __cplusplus
}
#endif

#endif /* ti_msp_dl_config_h */
