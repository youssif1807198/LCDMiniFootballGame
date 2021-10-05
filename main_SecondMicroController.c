

#include "HLCD_Interface.h"
#include "MDIO_Interface.h"
#include <avr/delay.h>
extern u8 LOC_U8RacketUp;
void  main(void)
{
#include "DrawingArrays.h"
	HLCD_Void_Init();
	u8 LOC_U8CurrentBallLocation;

	DIO_Void_PinDirections (PORTA, 2 , 0);
	DIO_Void_PinDirections (PORTA, 3 , 0);
	DIO_Void_PinDirections (PORTA, 4 , 0);
	DIO_Void_PinDirections (PORTD, 0 , 0);
	DIO_Void_PinDirections (PORTD, 7 , 1);
	DIO_Void_SetPinValue(PORTA,2,1);
	DIO_Void_SetPinValue(PORTA,3,1);
	DIO_Void_SetPinValue(PORTA,4,1);
	DIO_Void_SetPinValue (PORTD, 0 , 1);
	DIO_Void_SetPinValue (PORTD, 7 , 1);


	HLCD_Void_Set_DDRM_Position(0,5);
	HLCD_Void_SendString(Start);
	while (DIO_U8_GetPinValue (PORTA, PA4))
	{

	}
	LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
	HLCD_Void_Set_DDRM_Position(0,5);
	HLCD_Void_SendString(Space);
	LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
	reset:HLCD_Void_sendCommand(0b00000001);
	HLCD_Void_DrawPlayGroundRightLCD();
	LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();


	while(1)
	{
		LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();

		while (DIO_U8_GetPinValue (PORTD, PD0)==0)
		{
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
		}
		DIO_Void_SetPinValue(PORTD,7,1);



		LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
		LOC_U8CurrentBallLocation = HLCD_U8_BounceBallRightOnRightLCD();
		if (LOC_U8CurrentBallLocation==13 && LOC_U8RacketUp==0)
		{
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_VoidWriteSpecialCharRealPosition(Ball,0,14);
			_delay_ms(200);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_Void_Set_DDRM_Position(0,14);
			HLCD_Void_sendChar(' ');
			_delay_ms(200);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_VoidWriteSpecialCharRealPosition(Ball,0,15);
			_delay_ms(200);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_Void_Set_DDRM_Position(0,15);
			HLCD_Void_sendChar(' ');
			HLCD_Void_sendCommand(0b00000001);
			HLCD_Void_Set_DDRM_Position(0,4);
			HLCD_Void_SendString("Goal^_^");

			_delay_ms(1000);
			HLCD_Void_Set_DDRM_Position(0,4);
			HLCD_Void_SendString(Space);
			HLCD_Void_DrawPlayGroundRightLCD();
			_delay_ms(100);
			HLCD_U8_BounceBallLeftOnRightLCD();
			DIO_Void_SetPinValue(PORTD,7,0);
			DIO_Void_SetPinValue (PORTD, 0 , 1);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();


		}

		else if (LOC_U8CurrentBallLocation==77 && LOC_U8RacketUp==1)
		{
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_VoidWriteSpecialCharRealPosition(Ball,0,78);
			_delay_ms(200);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_Void_Set_DDRM_Position(0,78);
			HLCD_Void_sendChar(' ');
			_delay_ms(200);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_VoidWriteSpecialCharRealPosition(Ball,0,79);
			_delay_ms(200);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_Void_Set_DDRM_Position(0,79);
			HLCD_Void_sendChar(' ');
			HLCD_Void_sendCommand(0b00000001);
			HLCD_Void_Set_DDRM_Position(0,4);
			HLCD_Void_SendString("Goal^_^");
			_delay_ms(1000);

			HLCD_Void_Set_DDRM_Position(0,4);
			HLCD_Void_SendString(Space);
			HLCD_Void_DrawPlayGroundRightLCD();
			_delay_ms(100);
			HLCD_U8_BounceBallLeftOnRightLCD();
			DIO_Void_SetPinValue(PORTD,7,0);
			DIO_Void_SetPinValue (PORTD, 0 , 1);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();

		}
		else
		{
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
			HLCD_U8_BounceBallLeftOnRightLCD();
			DIO_Void_SetPinValue(PORTD,7,0);
			DIO_Void_SetPinValue (PORTD, 0 , 1);
			LOC_U8RacketUp = HLCD_U8_CheckSwitchesMC2 ();
		}

	}

}
