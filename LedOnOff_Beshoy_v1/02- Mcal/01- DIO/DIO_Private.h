/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Private
 *       Module:  -
 *
 *  Description:  addresses of the Dio driver    
 *  
 *********************************************************************************************************************/
/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V02																*/
/* Date    : 17 JUL 2022														*/
/********************************************************************************/


#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/***************************************************
					AHB
#define GPIOA_BASE_ADDRESS				 0x40058000
#define GPIOB_BASE_ADDRESS				 0x40059000
#define GPIOC_BASE_ADDRESS				 0x4005A000
#define GPIOD_BASE_ADDRESS				 0x4005B000
#define GPIOE_BASE_ADDRESS				 0x4005C000
#define GPIOF_BASE_ADDRESS				 0x4005D000
****************************************************/


// the register to enable gpio ports
#define RCGCGPIO			*((volatile u32 *)(0x400FE000 + 0x608))

/*					APB								*/
#define DIOA				 ((GPIOA_Type*)0x40004000)
#define DIOB				 ((GPIOA_Type*)0x40005000)
#define DIOC				 ((GPIOA_Type*)0x40006000)
#define DIOD				 ((GPIOA_Type*)0x40007000)
#define DIOE				 ((GPIOA_Type*)0x40024000)
#define DIOF				 ((GPIOA_Type*)0x40025000)


typedef struct {                           /* GPIOA Structure                                                       */
	u32 RESERVED[255];
	volatile u32 DATA;                              /* GPIO Data      ***********                                                       */
	volatile u32 DIR;                               /* GPIO Direction          *********                                              */
	volatile u32 IS;                                /* GPIO Interrupt Sense                                                  */
	volatile u32 IBE;                               /* GPIO Interrupt Both Edges                                             */
	volatile u32 IEV;                               /* GPIO Interrupt Event                                                  */
	volatile u32 IM;                                /* GPIO Interrupt Mask                                                   */
	volatile u32 RIS;                               /* GPIO Raw Interrupt Status                                             */
	volatile u32 MIS;                               /* GPIO Masked Interrupt Status                                          */
	volatile u32 ICR;                               /* GPIO Interrupt Clear                                                  */
	volatile u32 AFSEL;                             /* GPIO Alternate Function Select                                        */
	u32 RESERVED1[55];
	volatile u32 DR2R;                              /* GPIO 2-mA Drive Select                                                */
	volatile u32 DR4R;                              /* GPIO 4-mA Drive Select                                                */
	volatile u32 DR8R;                              /* GPIO 8-mA Drive Select                                                */
	volatile u32 ODR;                               /* GPIO Open Drain Select                                                */
	volatile u32 PUR;                               /* GPIO Pull-Up Select                                                   */
	volatile u32 PDR;                               /* GPIO Pull-Down Select                                                 */
	volatile u32 SLR;                               /* GPIO Slew Rate Control Select                                         */
	volatile u32 DEN;                               /* GPIO Digital Enable              ***********                                     */
	volatile u32 LOCK;                              /* GPIO Lock                                                             */
	volatile u32 CR;                                /* GPIO Commit                                                           */
	volatile u32 AMSEL;                             /* GPIO Analog Mode Select                                               */
	volatile u32 PCTL;                              /* GPIO Port Control                                                     */
	volatile u32 ADCCTL;                            /* GPIO ADC Control                                                      */
	volatile u32 DMACTL;                            /* GPIO DMA Control                                                      */
} GPIOA_Type;


//MSTK -> CTRL = 0;

/*
DIOA->DATA=0x3FC;
DIOB->DATA=0x3FC;
DIOC->DATA=0x3FC;
DIOD->DATA=0x3FC;
DIOE->DATA=0x3FC;
DIOF->DATA=0x3FC;
*/

// portA
/*
#define DIOA_GPIODATA							*((volatile u32 *)(DIOA_BASE_ADDRESS + 0x3FC))
*/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* DIO_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO_PRIVATE_H
 *********************************************************************************************************************/
