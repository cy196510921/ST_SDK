/**
  ******************************************************************************
  * @file    stm32xx_timerserver_conf.h
  * @author  MCD Application Team
  * @version V1.0
  * @date    14-April-2014
  * @brief   Header for stm32xx_timerserver.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

#ifndef __STM32xx_TIMERSERVER_CONF_H
#define __STM32xx_TIMERSERVER_CONF_H

#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes ------------------------------------------------------------------*/
#ifdef USE_STM32F4XX_NUCLEO
  #include "stm32f4xx_hal.h"
#endif /* USE_STM32F4XX_NUCLEO */

#ifdef USE_STM32L0XX_NUCLEO
#include "stm32l0xx_hal.h"
#endif /* USE_STM32L0XX_NUCLEO */   

#include "stm32xx_hal_timerserver_rtc.h"
#include "stm32xx_hal_timerserver_exti.h"

/** @addtogroup Middlewares
 *  @{
 */

/** @addtogroup ST
 *  @{
 */
 
/** @addtogroup TimerServer
 *  @{
 */

/** @defgroup STM32XX_TIMERSERVER_CONF
 * @{
 */
  
/* Exported constants --------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/

/** @defgroup STM32XX_TIMERSERVER_CONF_Exported_Macros
  * @{
  */

/* Exported macros -----------------------------------------------------------*/
#ifdef USE_STM32L0XX_NUCLEO
#define TIMERSERVER_TICK_VALUE	55	/** tick timer value is us */

/**
 * This value shall reflect the maximum delay there could be in the application between
 * the time the RTC interrupt is generated by the Hardware and the time when the
 * RTC interrupt handler is called
 * This time is measured in number of RTC_SYNCH_PRESCALER ticks
 *
 * A relax timing would be 1ms
 *
 * The value below are calculated for RTCCLK coming from LSI (37Khz)
 */
#define APP_RTC_HANDLER_MAX_DELAY	19	/**< 1ms x 37Khz / (RTC_ASYNCH_PRESCALER+1) */
#endif

#ifdef USE_STM32F4XX_NUCLEO
#define TIMERSERVER_TICK_VALUE	63	/** tick timer value is us */

/**
 * This value shall reflect the maximum delay there could be in the application between
 * the time the RTC interrupt is generated by the Hardware and the time when the
 * RTC interrupt handler is called
 * This time is measured in number of RTC_SYNCH_PRESCALER ticks
 *
 * A relax timing would be 1ms
 *
 * The value below are calculated for RTCCLK coming from LSI (32Khz)
 */
#define APP_RTC_HANDLER_MAX_DELAY	16	/**< 1ms x 32Khz / (RTC_ASYNCH_PRESCALER+1) */
#endif

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

#endif /* __STM32xx_TIMERSERVER_CONF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
