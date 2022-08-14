#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_Int.h"
#include "STK_Int.h"

void Besho(void);
//u32 ms = 8000;

// in sec
u8 LightTime = 2;

u8 DimTime = 1;


int main(void)
		{
			
			
			DIO_RCGEnablePorts();
			
			
			STK_Init();
			
			DIO_SetPin(DIO_PortF, DIO_Pin0, DIO_PinOut);
			
			
			

				
			
	
	while(1)
	{
		
		
		DIO_WriteChannel(DIO_PortF, DIO_Pin0, DIO_LevelHigh);
		STK_SetWait(LightTime);
		DIO_WriteChannel(DIO_PortF, DIO_Pin0, DIO_LevelLow);
		STK_SetWait(DimTime);
		
		
		/*
		STK_SetIntervalSingle(8000*200*LightTime,Besho);
		
		STK_SetIntervalSingle(8000*200*DimTime,Besho);
		*/
		
	}
		
	return 0;
}
		
/*
void Besho(void)
{
	
	DIO_FlipChannel(DIO_ChannelF0);
	
	
}
*/