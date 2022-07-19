/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  PORT_Program.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
/********************************************************************************/
/* Author  : BESHO																															*/
/* Version : V01																																*/
/* Date    : 17 JUL 2022																												*/
/********************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_Int.h"
#include "DIO_Private.h"
#include "PORT_Config.h"

extern Port_ConfigType PortCfgArr[];
static volatile GPIOA_Type* BaseAddrArr[6] = {DIOA,DIOB,
                                              DIOC,DIOD,
                                              DIOE,DIOF};
void PORT_Init(void)
{
    u8 CfgArrIndex;
    Port_IdType PortId;
    Port_ChIdType ChannelId;
    u8 ChannelPosInPort;
    volatile GPIOA_Type* BaseAddr;


    for (CfgArrIndex = 0; CfgArrIndex < PORT_NUM_OF_ACTIVATED_CH; ++CfgArrIndex)
    {
        /*get channelID from CfgIndex*/
        ChannelId = PortCfgArr[CfgArrIndex].Channel;

        /*get Channel Position in PortGroup using ChannelId */
        ChannelPosInPort = ChannelId % 8;

        /*get PORTId using ChannelId*/
        PortId = (Port_IdType)(ChannelId / 8);

        /*get baseAddress using PortId*/
        BaseAddr = BaseAddrArr[PortId];

        /* unlock the port channel */
        BaseAddr->LOCK = 0x00;
        SET_BIT((*BaseAddr).CR, ChannelPosInPort);


        /* set channel direction */
        BaseAddr->DIR |= PortCfgArr[CfgArrIndex].Dir << ChannelPosInPort;


        if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_DIO)
        {
            SET_BIT(BaseAddr->AFSEL, ChannelPosInPort);
        }
        else
        {
            CLR_BIT(BaseAddr->AFSEL, ChannelPosInPort);
        }

        /* set channel mode */
        BaseAddr->PCTL |= ( PortCfgArr[CfgArrIndex].Mode << (ChannelPosInPort*4) );


        /* set Interrupt configuration */
        if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntDisable)
        {
            CLR_BIT(BaseAddr->IM, ChannelPosInPort);
        }
        else
        {
            SET_BIT(BaseAddr->IM, ChannelPosInPort);

            if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntBothEdges)
            {
                SET_BIT(BaseAddr->IBE, ChannelPosInPort);
                CLR_BIT(BaseAddr->IEV, ChannelPosInPort);
            }
            else if(PortCfgArr[CfgArrIndex].Interrupt == Port_IntRisingEdge)
            {
                CLR_BIT(BaseAddr->IBE, ChannelPosInPort);
                SET_BIT(BaseAddr->IEV, ChannelPosInPort);
            }
            else
            {
                CLR_BIT(BaseAddr->IBE, ChannelPosInPort);
                CLR_BIT(BaseAddr->IEV, ChannelPosInPort);
            }
        }


        /* set Internal Attachment configuration */
        if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_OpenDrain)
        {
            SET_BIT(BaseAddr->ODR, ChannelPosInPort);
            CLR_BIT(BaseAddr->PUR, ChannelPosInPort);
            CLR_BIT(BaseAddr->PDR, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_PullUpRes)
        {
            CLR_BIT(BaseAddr->ODR, ChannelPosInPort);
            SET_BIT(BaseAddr->PUR, ChannelPosInPort);
            CLR_BIT(BaseAddr->PDR, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].AttachedRes == Port_InternalAttach_PullDownRes)
        {
            CLR_BIT(BaseAddr->ODR, ChannelPosInPort);
            CLR_BIT(BaseAddr->PUR, ChannelPosInPort);
            SET_BIT(BaseAddr->PDR, ChannelPosInPort);
        }
        else
        {
            //DO NOTHING
        }


        /* set current strength configuration */
        if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_2mA)
        {
            SET_BIT(BaseAddr->DR2R, ChannelPosInPort);
            CLR_BIT(BaseAddr->DR4R, ChannelPosInPort);
            CLR_BIT(BaseAddr->DR8R, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_4mA)
        {
            CLR_BIT(BaseAddr->DR2R, ChannelPosInPort);
            SET_BIT(BaseAddr->DR4R, ChannelPosInPort);
            CLR_BIT(BaseAddr->DR8R, ChannelPosInPort);
        }
        else if(PortCfgArr[CfgArrIndex].CurrentDrive == Port_CurrDrive_8mA)
        {
            CLR_BIT(BaseAddr->DR2R, ChannelPosInPort);
            CLR_BIT(BaseAddr->DR4R, ChannelPosInPort);
            SET_BIT(BaseAddr->DR8R, ChannelPosInPort);
        }
        else
        {
            CLR_BIT(BaseAddr->DR2R, ChannelPosInPort);
            CLR_BIT(BaseAddr->DR4R, ChannelPosInPort);
            CLR_BIT(BaseAddr->DR8R, ChannelPosInPort);
        }


        /*Check if analog functionality is required*/
        if(PortCfgArr[CfgArrIndex].Mode != Port_Mode_AIN )
        {
            /* enable digital and disable ADC  */
            SET_BIT(BaseAddr->DEN, ChannelPosInPort);
            CLR_BIT(BaseAddr->AMSEL, ChannelPosInPort);
            CLR_BIT(BaseAddr->ADCCTL, ChannelPosInPort);


        }
        else
        {
            /* disable digital and enable ADC */
            CLR_BIT(BaseAddr->DEN, ChannelPosInPort);
            SET_BIT(BaseAddr->AMSEL, ChannelPosInPort);
            SET_BIT(BaseAddr->ADCCTL, ChannelPosInPort);

        }

        /* check if the port needed to be locked or not */
        BaseAddr->CR |= PortCfgArr[CfgArrIndex].LockStatus << ChannelPosInPort;
        BaseAddr->LOCK = 0x01;
    }

}
