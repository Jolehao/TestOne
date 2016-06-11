#ifndef __LIBRARIES_H
#define __LIBRARIES_H

#include "stm32f2xx.h"
#include "stm32f2xx_rcc.h"
#include "stm32f2xx_tim.h"
#include "stm32f2xx_gpio.h"
#include "stm32f2xx_fsmc.h"
#include "stm32f2xx_usart.h"
#include "stm32f2xx_i2c.h"
#include "RTC.h"
#include "misc.h"
#include "common.h"

#include <stdint.h>

#ifdef  USE_FULL_ASSERT
    #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
    void assert_failed(uint8_t* file, uint32_t line);
#else
    #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */
#endif
