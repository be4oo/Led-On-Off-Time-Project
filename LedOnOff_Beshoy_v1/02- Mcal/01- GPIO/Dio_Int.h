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
/* Date    : 14 AGU 2022														*/
/********************************************************************************/


#ifndef DIO_INT_H
#define DIO_INT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
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
typedef enum
{
    DIO_PortA,
    DIO_PortB,
    DIO_PortC,
    DIO_PortD,
    DIO_PortE,
    DIO_PortF
}DIO_PortType;


typedef enum
{
	DIO_Pin0,
	DIO_Pin1,
	DIO_Pin2,
	DIO_Pin3,
	DIO_Pin4,
	DIO_Pin5,
	DIO_Pin6,
	DIO_Pin7
}DIO_PinNo;

typedef enum
{
    DIO_LevelLow	=0,
    DIO_LevelHigh	=1
}DIO_LevelType;


typedef enum
{
    DIO_PinIn	=0,
    DIO_PinOut	=1
}DIO_PinType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void DIO_RCGEnablePorts(void);
void DIO_SetPin(DIO_PortType PortId, DIO_PinNo PinId, DIO_PinType PinDi);
void DIO_WriteChannel(DIO_PortType PortId, DIO_PinNo PinId, DIO_LevelType Level);
DIO_LevelType Dio_ReadChannel(DIO_PortType PortId, DIO_PinNo PinId);
u8 DIO_ReadPort(DIO_PortType PortId);
void DIO_WritePort(DIO_PortType PortId, u8 Value);
void DIO_FlipChannel(DIO_PortType PortId, DIO_PinNo PinId);


 
#endif  /* DIO_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO_INT_H
 *********************************************************************************************************************/
