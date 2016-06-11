#ifndef __INIT_H
#define __INIT_H

/* Includes ------------------------------------------------------------------*/
#include  "libraries.h"
#include <string.h>
		
void BSP_Init(void);
void GPIO_Configuration(void);
void FSMC_Configuration(void);
void Timx_Configuration(void);
void NVIC_Configuration(void);
void COMx_Configuration(void);
void I2C1_Configuration(void);
void RadioState_Init(void);


//void GlobleValue_Init(void);

#endif 
