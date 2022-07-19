/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Int
 *       Module:  DIO
 *
 *  Description:  the interface of gpio driver     
 *  
 *********************************************************************************************************************/
/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V02																*/
/* Date    : 17 JUL 2022														*/
/********************************************************************************/


#ifndef DIO_INT_H
#define DIO_INT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*	to enable the port from RCG 	*/
#define RCGPortA					0
#define RCGPortB					1
#define RCGPortC					2
#define RCGPortD					3
#define RCGPortE					4
#define RCGPortF					5


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/*		DIO_ChanneltType 			*/
typedef enum
{
    DIO_ChannelA0,
    DIO_ChannelA1,
    DIO_ChannelA2,
    DIO_ChannelA3,
    DIO_ChannelA4,
    DIO_ChannelA5,
    DIO_ChannelA6,
    DIO_ChannelA7,
	
    DIO_ChannelB0,
    DIO_ChannelB1,
    DIO_ChannelB2,
    DIO_ChannelB3,
    DIO_ChannelB4,
    DIO_ChannelB5,
    DIO_ChannelB6,
    DIO_ChannelB7,
	
	
    DIO_ChannelC0,
    DIO_ChannelC1,
    DIO_ChannelC2,
    DIO_ChannelC3,
    DIO_ChannelC4,
    DIO_ChannelC5,
    DIO_ChannelC6,
    DIO_ChannelC7,
	
	
    DIO_ChannelD0,
    DIO_ChannelD1,
    DIO_ChannelD2,
    DIO_ChannelD3,
    DIO_ChannelD4,
    DIO_ChannelD5,
    DIO_ChannelD6,
    DIO_ChannelD7,
	
    DIO_ChannelE0,
    DIO_ChannelE1,
    DIO_ChannelE2,
    DIO_ChannelE3,
    DIO_ChannelE4,
    DIO_ChannelE5,
    DIO_ChannelE6,			//not exist
    DIO_ChannelE7,			//not exist
	
    DIO_ChannelF0,
    DIO_ChannelF1,
    DIO_ChannelF2,
    DIO_ChannelF3,
    DIO_ChannelF4

}DIO_ChannelType;

/*		DIO_PortType				*/
typedef enum
{
    DIO_PortA,
    DIO_PortB,
    DIO_PortC,
    DIO_PortD,
    DIO_PortE,
    DIO_PortF
}DIO_PortType;

/*		DIO_LevelType				*/
typedef enum
{
    DIO_LevelLow	=0,
    DIO_LevelHigh	=1
}DIO_LevelType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void DIO_RCGEnablePorts(void);

void DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType Level);
DIO_LevelType DIO_ReadChannel(DIO_ChannelType ChannelId);
u8 DIO_ReadPort(DIO_PortType PortId);
void DIO_FlipChannel(DIO_ChannelType ChannelId);
void DIO_WritePort(DIO_PortType PortId, u8 Value);


 
#endif  /* DIO_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO_INT_H
 *********************************************************************************************************************/
