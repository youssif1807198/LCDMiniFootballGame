
#include "BITMATH.h"
#include"STD_Types.h"
#include "MDIO_Private.h"

volatile AVR_ATmega32 * AVR_Ptr = 0x30;



void DIO_Void_PinDirections (u8 Copy_U8_Port, u8 Copy_U8_Pin , u8 Copy_U8_Direction)
{
	if(Copy_U8_Direction ==0)
	{
		switch(Copy_U8_Port)
		{
			case 0:
			CLEAR_BIT(AVR_Ptr -> DDRA_REG,Copy_U8_Pin);break;
			case 1:			
			CLEAR_BIT(AVR_Ptr -> DDRB_REG,Copy_U8_Pin);break;
			case 2:
			CLEAR_BIT(AVR_Ptr -> DDRC_REG,Copy_U8_Pin);break;
			case 3:
			CLEAR_BIT(AVR_Ptr -> DDRD_REG,Copy_U8_Pin);break;
			
			
		}
		
		
		
		
		
	}
	else if(Copy_U8_Direction==1)
	{
		
		switch(Copy_U8_Port)
		{
			case 0:
			SET_BIT(AVR_Ptr ->DDRA_REG,Copy_U8_Pin);break;
			case 1:			
			SET_BIT(AVR_Ptr ->DDRB_REG,Copy_U8_Pin);break;
			case 2:
			SET_BIT(AVR_Ptr ->DDRC_REG,Copy_U8_Pin);break;
			case 3:
			SET_BIT(AVR_Ptr ->DDRD_REG,Copy_U8_Pin);break;
			
			
		}
		
		
		
		
		
		
	}
		
}

u8 DIO_U8_GetPinValue (u8 Copy_U8_Port, u8 Copy_U8_Pin)
{
	u8 LOC_U8_ReturnName ;
	switch(Copy_U8_Port)
	{
		case 0:
		LOC_U8_ReturnName=GET_BIT(AVR_Ptr ->PINA_REG,Copy_U8_Pin);break;
		case 1:
		LOC_U8_ReturnName=GET_BIT(AVR_Ptr ->PINB_REG,Copy_U8_Pin);break;
		case 2:
		LOC_U8_ReturnName=GET_BIT(AVR_Ptr ->PINC_REG,Copy_U8_Pin);break;
		case 3:
		LOC_U8_ReturnName=GET_BIT(AVR_Ptr ->PIND_REG,Copy_U8_Pin);break;
		
		
	}
	
	return LOC_U8_ReturnName;
	
}

void DIO_Void_SetPortValue(u8 Copy_U8_PORT,u8 Copy_U8_Value)
{
	switch(Copy_U8_PORT)
	{
		case 0: AVR_Ptr ->PORTA_REG = Copy_U8_Value;break;
		
		case 1: AVR_Ptr ->PORTB_REG = Copy_U8_Value;break;
		
		case 2: AVR_Ptr ->PORTC_REG = Copy_U8_Value;break;
		
		case 3: AVR_Ptr ->PORTD_REG = Copy_U8_Value;break;

		
		
		
		
		
	}
}

void DIO_Void_SetPinValue(u8 Copy_U8_PORT,u8 Copy_U8_Pin,u8 Copy_U8_Value)
{
	if(Copy_U8_Value==1)
	{
		switch(Copy_U8_PORT)
		{
			case 0:SET_BIT(AVR_Ptr ->PORTA_REG,Copy_U8_Pin);break;
			
			case 1:SET_BIT(AVR_Ptr ->PORTB_REG,Copy_U8_Pin);break;
			
			case 2:SET_BIT(AVR_Ptr ->PORTC_REG,Copy_U8_Pin);break;
			
			case 3:SET_BIT(AVR_Ptr ->PORTD_REG,Copy_U8_Pin);break;
			
			
			
		}
		
		
	}
	
	else if(Copy_U8_Value==0)
	{
		switch(Copy_U8_PORT)
		{
			case 0:CLEAR_BIT(AVR_Ptr ->PORTA_REG,Copy_U8_Pin);break;
			
			case 1:CLEAR_BIT(AVR_Ptr ->PORTB_REG,Copy_U8_Pin);break;
			
			case 2:CLEAR_BIT(AVR_Ptr ->PORTC_REG,Copy_U8_Pin);break;
			
			case 3:CLEAR_BIT(AVR_Ptr ->PORTD_REG,Copy_U8_Pin);break;
			
			
			
		}
		
		
		
		
		
	}
	
	
	
	
}	
	
void DIO_Void_PortDirection(u8 Copy_U8_Port,u8 Copy_U8_Direction)
{


			switch(Copy_U8_Port)
		         {
			case 0:
			AVR_Ptr ->DDRA_REG=Copy_U8_Direction;break;
			case 1:			
			AVR_Ptr ->DDRB_REG=Copy_U8_Direction;break;
			case 2:
			AVR_Ptr ->DDRC_REG=Copy_U8_Direction;break;
			case 3:
			AVR_Ptr ->DDRD_REG=Copy_U8_Direction;break;
			
			
		         }
	
			
			
			
			
			
		
		

	
	
	
	
	
}
	
	
	

	
	
	
	
	
	

