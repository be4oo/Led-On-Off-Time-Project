/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  STK_Program.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V02																*/
/* Date    : 17 JUL 2022														*/
/********************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_Int.h"
#include "STK_Private.h"
#include "STK_Config.h"


/* Define Callback Global Variable */
void (*MSTK_Callback) (void);

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;






void STK_Init(void)
{
	/* Counter enable */
	SET_BIT(STCTRL,ENABLE);
	/* Interrupt enable */
	SET_BIT(STCTRL,TICKINT);
	CLR_BIT(STCTRL,CLKSOURCE);
	//SYS[0] = 0x00000003;
}
/*

STCTRL	

STRELOAD

STCURRENT


*/
//0x0001387F

/*
void STK_SetBusyWait(u32 Ticks)
{
	// We Should clear (Disable) the TICKINT (interrupt bit) 
	//CLR_BIT(STCTRL,TICKINT);
	STCTRL = 0x00;
	//STK_LOAD
	// Clear reg 
	STRELOAD &= ~((0xFFFF)<<0);
	// write on reg (load time)
	STRELOAD |= (Ticks<<0);
	// START 
	SET_BIT(STCTRL, ENABLE);
	SET_BIT(STCTRL, CLKSOURCE);
	//u8 BusyFlag = GET_BIT(SYS->STK_CTRL,COUNTFLAG);
	while(GET_BIT(STCTRL,COUNTFLAG) == 0)
	{
		//when the Local_u8Flag = 1 then the counting ends
	// waiting until reach 0 to get out the func 
	}
	// STOP TIMER 
	STRELOAD = 0;
	STCURRENT  = 0;
	
}
*/

void STK_SetWait1mSec(void)
{
	// We Should clear (Disable) the TICKINT (interrupt bit) 
	//CLR_BIT(STCTRL,TICKINT);
	STCTRL = 0x00;
	//STK_LOAD
	// Clear reg 
	STRELOAD &= ~((0xFFFFFF)<<0);
	// write on reg (load time)
	STRELOAD = 0x0001387F;		// setting 1ms/(1/80MHz) --> 80000
	// START 
	SET_BIT(STCTRL, ENABLE);
	SET_BIT(STCTRL, CLKSOURCE);
	//u8 BusyFlag = GET_BIT(SYS->STK_CTRL,COUNTFLAG);
	while(GET_BIT(STCTRL,COUNTFLAG) == 0)
	{
		//when the Local_u8Flag = 1 then the counting ends
	// waiting until reach 0 to get out the func 
	}
	// STOP TIMER 
	STRELOAD = 0;
	STCURRENT  = 0;
	
}

void STK_SetWait(u32 Time)
{
	//Time * 200 = sec
	u32 i = Time*200;
	while(i!=0)
	{
		STK_SetWait1mSec();
		i--;
	}
	
	//2000>>>>>>10
	//1000>>>>>>5
	//200>>>>>>>1 sec
	
}

void STK_SetIntervalSingle(u32 Ticks, void (*Copy_ptr)(void))
{
	/* Clear reg */
	STRELOAD &= ~((0xFFFFFF)<<0);
	/* write on reg (load time) */
	STRELOAD |= (Ticks<<0);
	/* enable of interrupt and enable systick */
	MSTK_Callback = Copy_ptr;

	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;

	/* Enable STK Interrupt */
	SET_BIT(STCTRL,TICKINT);
}

void SysTick_Handler(void)
{

	u8 Local_u8Temporary;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
			/* Disable STK Interrupt */
			CLR_BIT(STCTRL, 1);

			/* Stop Timer */
			SET_BIT(STCTRL, 0);
			STRELOAD = 0;
			STCURRENT  = 0;
	}

	/* Callback notification */
	MSTK_Callback();

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(STCTRL,COUNTFLAG);
}










/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
