/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STK_Int
 *       Module:  GPT
 *
 *  Description:  the interface of STK driver     
 *  
 *********************************************************************************************************************/
/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V01																*/
/* Date    : 17 JUL 2022														*/
/********************************************************************************/


#ifndef STK_INT_H
#define STK_INT_H

#include "STD_TYPES.h"

#define ENABLE 					0
#define TICKINT					1
#define CLKSOURCE				2
#define COUNTFLAG				16

#define MSTK_SINGLE_INTERVAL    0
#define MSTK_PERIOD_INTERVAL    1




void STK_Init(void);


void STK_SetWait1mSec(void);

void STK_SetWait(u32 Time);

void STK_SetIntervalSingle(u32 Ticks, void (*Copy_ptr)(void));






















#endif  /* STK_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: GPT_INT_H
 *********************************************************************************************************************/
