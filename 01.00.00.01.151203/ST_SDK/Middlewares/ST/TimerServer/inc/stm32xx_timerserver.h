/**
  ******************************************************************************
  * @file    stm32xx_timerserver.h
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    01-October-2014
  * @brief   Header for stm32xx_timerserver.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32XX_TIMERSERVER_H
#define __STM32XX_TIMERSERVER_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32xx_timerserver_conf.h"

/** @addtogroup Middlewares
 *  @{
 */

/** @addtogroup ST
 *  @{
 */
 
/** @addtogroup TimerServer
 *  @{
 */

/** @addtogroup STM32XX_TIMERSERVER 
 * @{
 */
 
/** @defgroup STM32XX_TIMERSERVER_Exported_Types
  * @{
  */
/* Exported types ------------------------------------------------------------*/
typedef enum
{
  eTimerMode_SingleShot,
  eTimerMode_Repeated
} eTIMER_TimerMode_t;

typedef enum
{
  eTimerModuleID_BlueNRG_Profile_App,
  eTimerModuleID_BlueNRG_Profile,
  eTimerModuleID_BlueNRG_HCI,
  eTimerModuleID_Interrupt
} eTimerProcessID_t;

typedef enum{
  eTimerID_Successful,
  eTimerID_Failed,
} eReturnStatus_t;

typedef void (*pf_TIMER_TimerCallBack_t)(void);

/**
 * @}
 */

/** @defgroup STM32XX_TIMERSERVER_Exported_Constants
  * @{
  */
/* Exported constants --------------------------------------------------------*/

 /**
  * This value shall reflect the maximum delay there could be in the application between
  * the time the RTC interrupt is generated by the Hardware and the time when the
  * RTC interrupt handler is called
  * This time is measured in number of RTC_SYNCH_PRESCALER ticks
  *
  * A relax timing would be 1ms
  */
#define RTC_HANDLER_MAX_DELAY	APP_RTC_HANDLER_MAX_DELAY	/**< 1ms x 37Khz / (RTC_ASYNCH_PRESCALER+1) */

/**
 * Number of maximum concurrent virtual timers used by the application
 */
#define	MAX_NBR_CONCURRENT_TIMER	8

 /**
  * Preempt priority
  * Priority of the RTC Wakeup interrupt
  */
#define	NVIC_UART_RTC_WAKEUP_IT_PREEMPTPRIORITY		3

 /**
  * Sub priority
  * Priority of the RTC Wakeup interrupt
  */
#define	NVIC_UART_RTC_WAKEUP_IT_SUBPRIORITY		0

 /**
  * Interrupt ID in the NVIC of the RTC Wakeup interrupt handler
  * It shall be type of IRQn_Type
  */
#ifdef STM32L053xx
#define	NVIC_RTC_WAKEUP_HANDLER_ID	RTC_IRQn
#endif

#ifdef STM32F401xE
#define	NVIC_RTC_WAKEUP_HANDLER_ID      RTC_WKUP_IRQn
#endif

 /**
  *  Define a critical section in the Timer server
  *  The Timer server does not support the API to be nested
  *  The  Application shall either:
  *  	a) Ensure this will never happen
  *  	b) Define the critical section
  *  The default implementations is masking all interrupts using the PRIMASK bit
  *  When the application is implementing low latency interrupts that would not support to be masked out,
  *  the critical section may use the basepri_max register to mask out only interrupt that have lower priority than those interrupts
  *  In that case, the application shall not call the Timer interface within these interrupt handlers.
  */
#define TIMER_USE_PRIMASK_AS_CRITICAL_SECTION

/**
 * @}
 */

/* Exported macros -----------------------------------------------------------*/

/** @defgroup STM32XX_TIMERSERVER_Exported_Functions
  * @{
  */
/* Exported functions ------------------------------------------------------- */
 void TIMER_Init(RTC_HandleTypeDef *hrtc);
 eReturnStatus_t TIMER_Create(eTimerProcessID_t eTimerProcessID, uint8_t *pTimerId, eTIMER_TimerMode_t eTimerMode, pf_TIMER_TimerCallBack_t pfTimerCallBack);
 void TIMER_Stop(uint8_t ubTimerID);
 void TIMER_Start(uint8_t ubTimerID, uint32_t timeout_ticks);
 void TIMER_Delete(uint8_t ubTimerID);
 void TIMER_Notification(eTimerProcessID_t eTimerProcessID, uint8_t ubTimerID, pf_TIMER_TimerCallBack_t pfTimerCallBack);
 void TIMER_RTC_Wakeup_Handler(void);

/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */
 
/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /*__STM32XX_TIMERSERVER_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
