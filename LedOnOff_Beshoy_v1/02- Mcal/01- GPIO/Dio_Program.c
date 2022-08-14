/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio_Program.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
/********************************************************************************/
/* Author  : BESHO																*/
/* Version : V02																*/
/* Date    : 14 AGU 2022														*/
/********************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio_Int.h"
#include "Dio_Private.h"
#include "Dio_Config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : DIO_RCGEnablePorts(void)       
* \Description     : RCG func to enable GPIO Port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) :                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_RCGEnablePorts(void)
{
	SET_BIT(RCGCGPIO , RCGPortA);
	SET_BIT(RCGCGPIO , RCGPortB);
	SET_BIT(RCGCGPIO , RCGPortC);
	SET_BIT(RCGCGPIO , RCGPortD);
	SET_BIT(RCGCGPIO , RCGPortE);
	SET_BIT(RCGCGPIO , RCGPortF);
}

/******************************************************************************
* \Syntax          : DIO_SetPin(DIO_PortType PortId, DIO_PinNo PinId, DIO_PinType PinDi)       
* \Description     : func to set pin Dirction                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (DIO_PortType PortId, DIO_PinNo PinId, DIO_PinType PinDi)                  
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/

void DIO_SetPin(DIO_PortType PortId, DIO_PinNo PinId, DIO_PinType PinDi)
{
	switch(PortId)
	{
		case DIO_PortA : 
					SET_BIT(DIOA->DEN , PinId);
					if(PinDi == DIO_PinOut)
						SET_BIT(DIOA->DIR , PinId);
					else
						CLR_BIT(DIOA->DIR , PinId);
					break;
		case DIO_PortB :
					SET_BIT(DIOB->DEN , PinId);
					if(PinDi == DIO_PinOut)
						SET_BIT(DIOB->DIR , PinId);
					else
						CLR_BIT(DIOB->DIR , PinId);
					break;
		case DIO_PortC :
					SET_BIT(DIOC->DEN , PinId);
					if(PinDi == DIO_PinOut)
						SET_BIT(DIOC->DIR , PinId);
					else
						CLR_BIT(DIOC->DIR , PinId);
					break;
		case DIO_PortD :
					SET_BIT(DIOD->DEN , PinId);
					if(PinDi == DIO_PinOut)
						SET_BIT(DIOD->DIR , PinId);
					else
						CLR_BIT(DIOD->DIR , PinId);
					break;
		case DIO_PortE :
					SET_BIT(DIOE->DEN , PinId);
					if(PinDi == DIO_PinOut)
						SET_BIT(DIOE->DIR , PinId);
					else
						CLR_BIT(DIOE->DIR , PinId);
					break;
		case DIO_PortF :
					SET_BIT(DIOF->DEN , PinId);
					if(PinDi == DIO_PinOut)
						SET_BIT(DIOF->DIR , PinId);
					else
						CLR_BIT(DIOF->DIR , PinId);
					break;
					
			
	}
}

/******************************************************************************
* \Syntax          : void DIO_WriteChannel(DIO_PortType PortId, DIO_PinNo PinId, DIO_LevelType Level)        
* \Description     : func to set pin value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (DIO_PortType PortId, DIO_PinNo PinId, DIO_LevelType Level)                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_WriteChannel(DIO_PortType PortId, DIO_PinNo PinId, DIO_LevelType Level)
{
	switch(PortId)
	{
		case DIO_PortA : 
					
					if(Level == DIO_LevelHigh)
						SET_BIT(DIOA->DATA , PinId);
					else
						CLR_BIT(DIOA->DATA , PinId);
					break;
		case DIO_PortB :
					
					if(Level == DIO_LevelHigh)
						SET_BIT(DIOB->DATA , PinId);
					else
						CLR_BIT(DIOB->DATA , PinId);
					break;
		case DIO_PortC :
					if(Level == DIO_LevelHigh)
						SET_BIT(DIOC->DATA , PinId);
					else
						CLR_BIT(DIOC->DATA , PinId);
					break;
		case DIO_PortD :
					if(Level == DIO_LevelHigh)
						SET_BIT(DIOD->DATA , PinId);
					else
						CLR_BIT(DIOD->DATA , PinId);
					break;
		case DIO_PortE :
					if(Level == DIO_LevelHigh)
						SET_BIT(DIOE->DATA , PinId);
					else
						CLR_BIT(DIOE->DATA , PinId);
					break;
		case DIO_PortF :
					if(Level == DIO_LevelHigh)
						SET_BIT(DIOF->DATA , PinId);
					else
						CLR_BIT(DIOF->DATA , PinId);
					break;
		
		
	}
}
/******************************************************************************
* \Syntax          : Dio_ReadChannel(DIO_PortType PortId, DIO_PinNo PinId)        
* \Description     : func to read pin value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (DIO_PortType PortId, DIO_PinNo PinId)                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
DIO_LevelType Dio_ReadChannel(DIO_PortType PortId, DIO_PinNo PinId)
{
	DIO_LevelType PinValue;
	switch(PortId)
	{
		case DIO_PortA :PinValue = GET_BIT(DIOA->DATA , PinId); break;
		case DIO_PortB :PinValue = GET_BIT(DIOB->DATA , PinId); break;
		case DIO_PortC :PinValue = GET_BIT(DIOC->DATA , PinId); break;
		case DIO_PortD :PinValue = GET_BIT(DIOD->DATA , PinId); break;
		case DIO_PortE :PinValue = GET_BIT(DIOE->DATA , PinId); break;
		case DIO_PortF :PinValue = GET_BIT(DIOF->DATA , PinId); break;
		default :	break;
	}
	return PinValue;
}

/******************************************************************************
* \Syntax          : u8 DIO_ReadPort(DIO_PortType PortId)       
* \Description     : func to read port value                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (DIO_PortType PortId)                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
u8 DIO_ReadPort(DIO_PortType PortId)
{
	u8 PortValue;
	switch(PortId)
    {
    case DIO_PortA :PortValue = DIOA->DATA;	break;
    case DIO_PortB :PortValue = DIOB->DATA;	break;
    case DIO_PortC :PortValue = DIOC->DATA;	break;
    case DIO_PortD :PortValue = DIOD->DATA;	break;
    case DIO_PortE :PortValue = DIOE->DATA; break;
    case DIO_PortF :PortValue = DIOF->DATA;	break;
    default :	break;
    }
    return PortValue;
}

/******************************************************************************
* \Syntax          : DIO_WritePort(DIO_PortType PortId, u8 Value)      
* \Description     : func to Write on port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : (DIO_PortType PortId, u8 Value)                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_WritePort(DIO_PortType PortId, u8 Value)
{
	switch(PortId)
    {
    case DIO_PortA :DIOA->DATA = Value;	break;
    case DIO_PortB :DIOB->DATA = Value;	break;
    case DIO_PortC :DIOC->DATA = Value;	break;
    case DIO_PortD :DIOD->DATA = Value;	break;
    case DIO_PortE :DIOE->DATA = Value; break;
    case DIO_PortF :DIOF->DATA = Value;	break;
    default :	break;
	}
}

/******************************************************************************
* \Syntax          : void DIO_FlipChannel(DIO_PortType PortId, DIO_PinNo PinId)        
* \Description     : to Toggle the channel value                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : DIO_PortType PortId, DIO_PinNo PinId                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_FlipChannel(DIO_PortType PortId, DIO_PinNo PinId)
{
	switch(PortId)
    {
    case DIO_PortA :TOG_BIT(DIOA->DATA, PinId);	break;
    case DIO_PortB :TOG_BIT(DIOB->DATA, PinId);	break;
    case DIO_PortC :TOG_BIT(DIOC->DATA, PinId);	break;
    case DIO_PortD :TOG_BIT(DIOD->DATA, PinId);	break;
    case DIO_PortE :TOG_BIT(DIOE->DATA, PinId);	break;
    case DIO_PortF :TOG_BIT(DIOF->DATA, PinId);	break;
    default :	break;
    }
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
