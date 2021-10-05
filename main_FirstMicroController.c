
#include "HLCD_Interface.h"
#include "MDIO_Interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <avr/delay.h>
extern 	u8 GLOB_U8RacketUp;


void  main(void)
{
#include "DrawingArrays.h"

	HLCD_Void_Init();

	u8 LOC_U8BallLocation;




	DIO_Void_PinDirections(PORTA,PA2,0);
	DIO_Void_PinDirections(PORTA,PA3,0);
	DIO_Void_PinDirections(PORTA,PA4,0);

	DIO_Void_SetPinValue(PORTA,PA2,1);
	DIO_Void_SetPinValue(PORTA,PA3,1);
	DIO_Void_SetPinValue(PORTA,PA4,1);

	DIO_Void_PinDirections(PORTD,PD0,1);
	DIO_Void_PinDirections(PORTD,PD7,0);


	DIO_Void_SetPinValue(PORTD,PD0,HIGH);
	DIO_Void_SetPinValue(PORTD,PD7,HIGH);











	//print start on LCD
	HLCD_Void_Set_DDRM_Position(0,5);
	HLCD_Void_SendString(Start);



	while(DIO_U8_GetPinValue(PORTA,PA2))
	{


	}

	GLOB_U8RacketUp=HLCD_U8_CheckSwitchesMC1();


	HLCD_Void_Set_DDRM_Position(0,5);
	HLCD_Void_SendString(Space);

	GLOB_U8RacketUp=HLCD_U8_CheckSwitchesMC1();


	reset :HLCD_Void_sendCommand(0B00000001);
	HLCD_Void_DrawPlayGroundLeftLCD();
	GLOB_U8RacketUp=HLCD_U8_CheckSwitchesMC1();

	LOC_U8BallLocation=HLCD_U8_BounceBallRightOnLeftLCD();

	GLOB_U8RacketUp=HLCD_U8_CheckSwitchesMC1();


	DIO_Void_SetPinValue(PORTD,PD0,LOW);

	while((DIO_U8_GetPinValue(PORTD,PD7)==0))
	{
		GLOB_U8RacketUp=HLCD_U8_CheckSwitchesMC1();


	}


	while (1)
	{
		while((DIO_U8_GetPinValue(PORTD,PD7)==0))
			{
			GLOB_U8RacketUp=HLCD_U8_CheckSwitchesMC1();

			}

		DIO_Void_SetPinValue(PORTD,PD0,HIGH);

		LOC_U8BallLocation=HLCD_U8_BounceBallLeftOnLeftLCD();
		GLOB_U8RacketUp=HLCD_U8_CheckSwitchesMC1();
HLCD_Void_SendNumber(GLOB_U8RacketUp);


		if(LOC_U8BallLocation==1 && GLOB_U8RacketUp==0)
		{
						HLCD_Void_sendCommand(128+2);
						HLCD_Void_sendChar(' ');

			                    HLCD_VoidWriteSpecialCharRealPosition(Ball,0,1);
								HLCD_U8_CheckSwitchesMC1();
								_delay_ms(200);
							    HLCD_U8_CheckSwitchesMC1();
							 	HLCD_Void_sendCommand(128+1);
								HLCD_Void_sendChar(' ');

								  HLCD_VoidWriteSpecialCharRealPosition(Ball,0,0);
						          HLCD_U8_CheckSwitchesMC1();
								  _delay_ms(200);
								  HLCD_U8_CheckSwitchesMC1();
								  HLCD_Void_sendCommand(128+0);
								  HLCD_Void_sendChar(' ');

                                HLCD_Void_sendCommand(0b00000001);
								HLCD_Void_sendCommand(128+4);
								HLCD_Void_SendString("GOAL ^_^");

								_delay_ms(1000);
								goto reset;


		}

		else if(LOC_U8BallLocation==66 && GLOB_U8RacketUp==1)
		{

			HLCD_Void_sendCommand(128+67);
			HLCD_Void_sendChar(' ');

			HLCD_VoidWriteSpecialCharRealPosition(Ball,0,66);
			HLCD_U8_CheckSwitchesMC1();
			_delay_ms(200);
		    HLCD_U8_CheckSwitchesMC1();
		    HLCD_Void_sendCommand(128+66);
		    HLCD_Void_sendChar(' ');


			HLCD_VoidWriteSpecialCharRealPosition(Ball,0,65);
			HLCD_U8_CheckSwitchesMC1();
			_delay_ms(200);
		    HLCD_U8_CheckSwitchesMC1();
		    HLCD_Void_sendCommand(128+65);
		    HLCD_Void_sendChar(' ');

            HLCD_Void_sendCommand(0b00000001);
		    HLCD_Void_sendCommand(128+4);
			HLCD_Void_SendString("GOAL ^_^");

			_delay_ms(1000);

			goto reset;



		}

		else
		{

			HLCD_U8_BounceBallRightOnLeftLCD();
			DIO_Void_SetPinValue(PORTD,PD0,LOW);
			DIO_Void_SetPinValue (PORTD,PD7, HIGH);
			/*_delay_ms(1000);*/

		}



	}




}

