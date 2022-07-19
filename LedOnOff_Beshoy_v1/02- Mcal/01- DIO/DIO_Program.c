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
/* Date    : 17 JUL 2022														*/
/********************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Int.h"
#include "DIO_Private.h"
//#include "DIO_Config.h"

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
* \Syntax          : void MDIO_voidRCGEnablePort(u8 u8PortToEnable)        
* \Description     : RCG func to enable GPIO Port                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : u8PortToEnable   the port you want to enable                     
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
* \Syntax          : void DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType Level)        
* \Description     : TO write on pin                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId, Level                   
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_WriteChannel(DIO_ChannelType ChannelId, DIO_LevelType Level)
{
    DIO_PortType PortId = ChannelId / 8;
    DIO_ChannelType PinNo = ChannelId % 8;

    /* Write the input value in the corresponding ChannelId */
    switch(PortId)
    {
    case DIO_PortA :ASSIGN_BIT(DIOA->DATA, PinNo, Level);	break;
    case DIO_PortB :ASSIGN_BIT(DIOB->DATA, PinNo, Level);	break;
    case DIO_PortC :ASSIGN_BIT(DIOC->DATA, PinNo, Level);	break;
    case DIO_PortD :ASSIGN_BIT(DIOD->DATA, PinNo, Level);	break;
    case DIO_PortE :ASSIGN_BIT(DIOE->DATA, PinNo, Level);	break;
    case DIO_PortF :ASSIGN_BIT(DIOF->DATA, PinNo, Level);	break;
    default :	break;
    }
}

/******************************************************************************
* \Syntax          : DIO_levelType Dio_ReadChannel(DIO_ChannelType ChannelId)        
* \Description     : TO Read from pin                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId                  
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
DIO_LevelType Dio_ReadChannel(DIO_ChannelType ChannelId)
{
    DIO_LevelType PinValue;
    DIO_PortType PortId = ChannelId / 8;
    DIO_ChannelType PinNO = ChannelId % 8;

    /* return the value of the Channel */
    switch(PortId)
    {
    case DIO_PortA :PinValue = GET_BIT(DIOA->DATA, PinNO);	break;
    case DIO_PortB :PinValue = GET_BIT(DIOB->DATA, PinNO);	break;
    case DIO_PortC :PinValue = GET_BIT(DIOC->DATA, PinNO);	break;
    case DIO_PortD :PinValue = GET_BIT(DIOD->DATA, PinNO);	break;
    case DIO_PortE :PinValue = GET_BIT(DIOE->DATA, PinNO);  break;
    case DIO_PortF :PinValue = GET_BIT(DIOF->DATA, PinNO);	break;
    default :	break;
    }
    return PinValue;

}

/******************************************************************************
* \Syntax          : u8 DIO_ReadPort(DIO_PortType PortId)        
* \Description     : TO Read from Port                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId                  
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
u8 DIO_ReadPort(DIO_PortType PortId)
{
	u8 PortValue;
	
	/* return the value of the Port */
    switch(PortId)
    {
    case DIO_PortA :PortValue = DIOA->DATA;	break;
    case DIO_PortB :PortValue = DIOB->DATA;	break;
    case DIO_PortC :PortValue = DIOC->DATA;	break;
    case DIO_PortD :PortValue = DIOD->DATA;	break;
    case DIO_PortE :PortValue = DIOE->DATA;  break;
    case DIO_PortF :PortValue = DIOF->DATA;	break;
    default :	break;
    }
    return PortValue;
}

/******************************************************************************
* \Syntax          : void DIO_WritePort(DIO_PortType PortId, u8 Value)        
* \Description     : TO write on Port                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PortId, Value                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_WritePort(DIO_PortType PortId, u8 Value)
{
	
	/* write the value on the Port */
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
* \Syntax          : void DIO_FlipChannel( DIO_ChannelType ChannelId)        
* \Description     : to Toggle the channel value                              
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ChannelId                 
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void DIO_FlipChannel( DIO_ChannelType ChannelId)
{
    DIO_PortType PortId = ChannelId / 8;
    DIO_ChannelType PinNo = ChannelId % 8;

    /* Toggle the channel value */
    switch(PortId)
    {
    case DIO_PortA :TOG_BIT(DIOA->DATA, PinNo);	break;
    case DIO_PortB :TOG_BIT(DIOB->DATA, PinNo);	break;
    case DIO_PortC :TOG_BIT(DIOC->DATA, PinNo);	break;
    case DIO_PortD :TOG_BIT(DIOD->DATA, PinNo);	break;
    case DIO_PortE :TOG_BIT(DIOE->DATA, PinNo);	break;
    case DIO_PortF :TOG_BIT(DIOF->DATA, PinNo);	break;
    default :	break;
    }


}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
