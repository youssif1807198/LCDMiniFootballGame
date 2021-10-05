#include "STD_types.h"
#include "BITMATH.h"
#include "MDIO_Interface.h"
#include "HLCD_Interface.h"
#include "avr/delay.h"
#include <stdlib.h>
#include "DrawingArrays.h"
u8 GLOB_U8RacketUp=1;

/* CheckSwitches Functions used to detect if one have pushed switch or not by boolean techniuqe
 *can be achieved more better using interrupt return global variable racketup take 0 when racket is down
 *can  and take 1 when racket is up  */

u8 HLCD_U8_CheckSwitchesMC1 (void)
{
#include "DrawingArrays.h"
	u8 LOC_U8SwitchesPressed;

	LOC_U8SwitchesPressed= 0 | DIO_U8_GetPinValue(PORTA,PA3);
	LOC_U8SwitchesPressed=LOC_U8SwitchesPressed<<1;
	LOC_U8SwitchesPressed=LOC_U8SwitchesPressed|DIO_U8_GetPinValue(PORTA,PA4);

	switch(LOC_U8SwitchesPressed)
	{
	case 0b00000010:
	    HLCD_Void_Set_DDRM_Position(0,1);
	    HLCD_Void_sendChar(' ');
	    HLCD_VoidWriteSpecialChar(Racket,7,1,1);
	    GLOB_U8RacketUp=0;
	break;

	case 0b00000001:
		HLCD_Void_Set_DDRM_Position(1,1);
		HLCD_Void_sendChar(' ');
		HLCD_VoidWriteSpecialChar(Racket,7,0,1);
		GLOB_U8RacketUp=1;
	break;

	}

	return GLOB_U8RacketUp;









}

u8 HLCD_U8_CheckSwitchesMC2 (void)
{
#include "DrawingArrays.h"

	u8 LOC_U8SwitchesPressed;

	LOC_U8SwitchesPressed= 0 | DIO_U8_GetPinValue(PORTA,PA2);
	LOC_U8SwitchesPressed=LOC_U8SwitchesPressed<<1;
	LOC_U8SwitchesPressed=LOC_U8SwitchesPressed|DIO_U8_GetPinValue(PORTA,PA3);

	switch(LOC_U8SwitchesPressed)
	{
	case 0b00000010:
	    HLCD_Void_Set_DDRM_Position(0,14);
	    HLCD_Void_sendChar(' ');
	    HLCD_VoidWriteSpecialChar(Racket,7,1,14);
	    GLOB_U8RacketUp=0;
	break;

	case 0b00000001:
		HLCD_Void_Set_DDRM_Position(1,14);
		HLCD_Void_sendChar(' ');
		HLCD_VoidWriteSpecialChar(Racket,7,0,14);
		GLOB_U8RacketUp=1;
	break;

	}

	return GLOB_U8RacketUp;









}

/* send char function used to write 8bits data on LCD
 *  while sendcommand used to send write commands that do specific job
 *  init used to intialize LCD
 *  send number used to print number on LCD
 *  Send string used to print string on LCD*/

void HLCD_Void_sendChar(u8 Copy_U8_Data)
{
    
	//set Rs and reset Rw
	DIO_Void_SetPinValue(PORTB,PB0,HIGH);
	DIO_Void_SetPinValue(PORTB,PB1,LOW);
	
	
	
	
	//send char
	DIO_Void_SetPortValue(PORTC,Copy_U8_Data);

	//enable
	DIO_Void_SetPinValue(PORTB,PB2,LOW);
	DIO_Void_SetPinValue(PORTB,PB2,HIGH);
	_delay_us(10);
	DIO_Void_SetPinValue(PORTB,PB2,LOW);
	_delay_us(10);

	//delay after writing
	_delay_ms(2);
	
	
	
}

void HLCD_Void_sendCommand(u8 Copy_U8_Command)
{
	
    
	//Reset Rs and Rw
	DIO_Void_SetPinValue(PORTB,PB0,LOW);
	DIO_Void_SetPinValue(PORTB,PB1,LOW);
	
	
	
	
	//send command
	DIO_Void_SetPortValue(PORTC,Copy_U8_Command);

	//enable
	DIO_Void_SetPinValue(PORTB,PB2,LOW);

	DIO_Void_SetPinValue(PORTB,PB2,HIGH);
	_delay_us(10);

	DIO_Void_SetPinValue(PORTB,PB2,LOW);

	//delay after writing
	_delay_ms(2);
	
	
	
}

void HLCD_Void_Init(void)
{
	

	 /*set direction for portc as output
	to be used as DATA buses*/
	 DIO_Void_PortDirection(PORTC,0b11111111);

	
	/* set directon for port b B0 for Rs 
	,B1 for R/W ,B2 for enable */
	DIO_Void_PinDirections (PORTB, PB0 , Output);
	DIO_Void_PinDirections (PORTB, PB1 , Output);
	DIO_Void_PinDirections (PORTB, PB2 , Output);
	 /*delay until vd rises 4.5v*/
	_delay_ms(40);
	
	 /*Function Set*/
	HLCD_Void_sendCommand(0b00111000);
	
	 /*Delay for 50 microseconds after
	Function Set */
	_delay_us(50);
	
/* Display on/off */
	HLCD_Void_sendCommand(0b00001100);

	/*delay after display on/off*/
	_delay_us(100);

	 /*Display clear*/
	HLCD_Void_sendCommand(0b00000001);
	
	/* Delay for 4 miliseconds after 
	Display clear*/
	_delay_ms(4);
	
	/*Entry mode set*/
	//HLCD_Void_sendCommand(0b00000111);

	_delay_ms(4);


	
	
	
}

void HLCD_Void_SendNumber(u32 Copy_U32_Number)
{
	u32 LOC_U32_Reverse = 1;

	if(!Copy_U32_Number)
	{
		HLCD_Void_sendChar('0');


	}
	else
	{
	while(Copy_U32_Number >0)
	{

		LOC_U32_Reverse = (LOC_U32_Reverse*10)+(Copy_U32_Number%10);
		Copy_U32_Number /= 10;


	}
	while(LOC_U32_Reverse>1)
	{
	u32	LOC_U32_NumberToSend = LOC_U32_Reverse%10 ;
	HLCD_Void_sendChar(LOC_U32_NumberToSend+'0');
	LOC_U32_Reverse/=10;



	}
	}








}

void HLCD_Void_SendString(u8 * Copy_U8_Ptr)
{
    for(u32 i = 0; Copy_U8_Ptr[i] != '\0' ; i++)
    {
    	HLCD_Void_sendChar(Copy_U8_Ptr[i]);
    }






}

void HLCD_Void_DrawDal(void)
{
	// Set CGRAM address

	HLCD_Void_sendCommand(0b01000000);
	HLCD_Void_sendChar(0b00000100);
	HLCD_Void_sendChar(0b00000010);
	HLCD_Void_sendChar(0b00000001);
	HLCD_Void_sendChar(0b00000001);
	HLCD_Void_sendChar(0b00000001);
	HLCD_Void_sendChar(0b00000001);
	HLCD_Void_sendChar(0b00011111);

	//set DDRAM
	HLCD_Void_sendCommand(0b10000000);






}

/*WriteSpecialChar function used to draw designed pattern array on LCD
 *   by defining row and coulmn where pattern will be printed
 *   while WriteSpecialChar function used to do same thing
 *   except they use actual position of char to print on LCD the selected pattern */

void HLCD_VoidWriteSpecialChar(u8 *Copy_U8Pattern,u8 Copy_U8PatternNumber,u8 Copy_U8Row,u8 Copy_U8Position)
{
	HLCD_U8_CheckSwitchesMC1();

	u8 Local_U8CGRAMAddress = 0;
	u8 Local_U8Iterator;
	/*Calculate the CGRAM Address*/
	Local_U8CGRAMAddress = Copy_U8PatternNumber *8;
	/*Send CGRAM Address Command to LCD*/
	HLCD_Void_sendCommand(Local_U8CGRAMAddress +64);
	HLCD_U8_CheckSwitchesMC1();

	/*WRITE The Pattern in the CGRAM*/
	for(Local_U8Iterator=0; Local_U8Iterator<8; Local_U8Iterator++)
	{
		HLCD_U8_CheckSwitchesMC1();

		HLCD_Void_sendChar(Copy_U8Pattern[Local_U8Iterator]) ;
	}
	HLCD_U8_CheckSwitchesMC1();

	/*Return to the DDRAM*/
	HLCD_Void_Set_DDRM_Position (Copy_U8Row , Copy_U8Position );
	/*Display The Pattern */
	HLCD_Void_sendChar(Copy_U8PatternNumber);
	HLCD_U8_CheckSwitchesMC1();

}

void HLCD_VoidWriteSpecialCharRealPosition(u8 *Copy_U8Pattern,u8 Copy_U8PatternNumber,u8 Copy_U8Position)
{
	HLCD_U8_CheckSwitchesMC1();

	u8 Local_U8CGRAMAddress = 0;
	u8 Local_U8Iterator;
	/*Calculate the CGRAM Address*/
	Local_U8CGRAMAddress = Copy_U8PatternNumber *8;
	/*Send CGRAM Address Command to LCD*/
	HLCD_Void_sendCommand(Local_U8CGRAMAddress +64);
	HLCD_U8_CheckSwitchesMC1();

	/*WRITE The Pattern in the CGRAM*/
	for(Local_U8Iterator=0; Local_U8Iterator<8; Local_U8Iterator++)
	{
		HLCD_U8_CheckSwitchesMC1();

		HLCD_Void_sendChar(Copy_U8Pattern[Local_U8Iterator]) ;
	}
	HLCD_U8_CheckSwitchesMC1();

	/*Return to the DDRAM*/
	HLCD_Void_sendCommand(128+Copy_U8Position);

	/*Display The Pattern */
	HLCD_Void_sendChar(Copy_U8PatternNumber);
	HLCD_U8_CheckSwitchesMC1();

}

void HLCD_Void_Set_DDRM_Position(u8 Copy_U8_Row, u8 Copy_U8_Column)
{
	if(Copy_U8_Row==0 && Copy_U8_Column<40 )
	{
		HLCD_Void_sendCommand(128+Copy_U8_Column);

	}
	else if (Copy_U8_Row==1 && Copy_U8_Column>=0 && Copy_U8_Column<=40)
	{

		HLCD_Void_sendCommand(128+Copy_U8_Column+64);


	}




}

/* draw play ground draws centre circle
 * and draws racket and net for right and Left LCD*/

void HLCD_Void_DrawPlayGroundLeftLCD(void)
{

	// draw center circle at left LCD
	    HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfRightCenterCircleLeftLCD,4,0,15);
		HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfRightCenterCircleLeftLCD,1,1,15);
		HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfLeftCenterCircleLeftLCD,2,0,14);
		HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfLeftCenterCircleLeftLCD,3,1,14);
    // draw football net
		HLCD_VoidWriteSpecialChar(UpperNet,5,0,0);
		HLCD_VoidWriteSpecialChar(LowerNet,6,1,0);
	// draw ball racket
		HLCD_VoidWriteSpecialChar(Racket,7,0,1);


}

void HLCD_Void_DrawPlayGroundRightLCD(void)
{

	// draw center circle at right LCD
		HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfLeftCenterCircleRightLCD,4,0,0);
		HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfLeftCenterCircleRightLCD,1,1,0);
		HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfRighttCenterCircleRightLCD,2,0,1);
		HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfRighttCenterCircleRightLCD,3,1,1);
    // draw football net
		HLCD_VoidWriteSpecialChar(UpperNet,5,0,15);
		HLCD_VoidWriteSpecialChar(LowerNet,6,1,15);
	// draw ball racket
		HLCD_VoidWriteSpecialChar(Racket,7,0,14);


}

/*Bouncing function used to bounceball on LCD like it collides to LCD frame
 * HLCD_U8_BounceBallRightOnLeftLCD bouncess ball towrards right on left LCD
 * HLCD_U8_BounceBallLeftOnLeftLCD bouncess ball towrards left on left LCD
 * HLCD_U8_BounceBallRightOnRightLCD bouncess ball towrards right on right LCD
 *HLCD_U8_BounceBallLeftOnRightLCD bouncess ball towrards left on right LCD */

u8 HLCD_U8_BounceBallRightOnLeftLCD(void)
{
#include "DrawingArrays.h"

	HLCD_U8_CheckSwitchesMC1();


	    u8 LOC_U8seed=1;
	    u8 LOC_U8HeadsDownward[]={64,65,1};
	    s8 LOC_U8HeadsUpwards[]={1,-64,-63};
	    u8  LOC_U8ArrayIndex;
	    u8 LOC_U8CurrentBallLocation=2;

	    srand(LOC_U8seed);
	    LOC_U8ArrayIndex= (rand() %(2 - 0 + 1)) + 0;





	    HLCD_U8_CheckSwitchesMC1();

				  while(LOC_U8CurrentBallLocation!= 15 && LOC_U8CurrentBallLocation!= 79)
				{
					    HLCD_U8_CheckSwitchesMC1();

					  if(LOC_U8CurrentBallLocation>=64 &&LOC_U8CurrentBallLocation<=79)
					  {
						    HLCD_U8_CheckSwitchesMC1();


					LOC_U8CurrentBallLocation+=LOC_U8HeadsUpwards[LOC_U8ArrayIndex];
					HLCD_VoidWriteSpecialCharRealPosition(Ball,0,LOC_U8CurrentBallLocation);

					HLCD_U8_CheckSwitchesMC1();
					_delay_ms(200);
				    HLCD_U8_CheckSwitchesMC1();

					HLCD_Void_sendCommand(128+LOC_U8CurrentBallLocation);
					HLCD_Void_sendChar(' ');
				    HLCD_U8_CheckSwitchesMC1();


					  }
					    HLCD_U8_CheckSwitchesMC1();

					LOC_U8CurrentBallLocation+=LOC_U8HeadsDownward[LOC_U8ArrayIndex];
					HLCD_VoidWriteSpecialCharRealPosition(Ball,0,LOC_U8CurrentBallLocation);
				    HLCD_U8_CheckSwitchesMC1();
					_delay_ms(200);
				    HLCD_U8_CheckSwitchesMC1();
					HLCD_Void_sendCommand(128+LOC_U8CurrentBallLocation);
					HLCD_Void_sendChar(' ');
				    HLCD_U8_CheckSwitchesMC1();


					LOC_U8seed++;
				}
				  HLCD_U8_CheckSwitchesMC1();

				  // draw center circle at left LCD after ball write on it after exiting
				  HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfRightCenterCircleLeftLCD,4,0,15);
				  HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfRightCenterCircleLeftLCD,1,1,15);
				  HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfLeftCenterCircleLeftLCD,2,0,14);
				  HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfLeftCenterCircleLeftLCD,3,1,14);

				  HLCD_U8_CheckSwitchesMC1();


				  return LOC_U8CurrentBallLocation;

}

u8 HLCD_U8_BounceBallLeftOnLeftLCD(void)
{
#include "DrawingArrays.h"
    HLCD_U8_CheckSwitchesMC1();


	    u8 LOC_U8seed=1;
	    s8 LOC_U8HeadsDownward[]={64,63,-1};
	    s8 LOC_U8HeadsUpwards[]={-1,-64,-65};
	    u8  LOC_U8ArrayIndex;
	    u8 LOC_U8CurrentBallLocation=15;
	    HLCD_U8_CheckSwitchesMC1();

	    srand(LOC_U8seed);
	    LOC_U8ArrayIndex= (rand() %(2 - 0 + 1)) + 0;





	    HLCD_U8_CheckSwitchesMC1();

				  while(LOC_U8CurrentBallLocation!= 2 && LOC_U8CurrentBallLocation!= 66)
				{
					    HLCD_U8_CheckSwitchesMC1();

					  if(LOC_U8CurrentBallLocation==13 || LOC_U8CurrentBallLocation==77)
					  {
						  // draw center circle at left LCD after ball write on it after entering
						    HLCD_U8_CheckSwitchesMC1();
					      HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfRightCenterCircleLeftLCD,4,0,15);
						  HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfRightCenterCircleLeftLCD,1,1,15);
						  HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfLeftCenterCircleLeftLCD,2,0,14);
						  HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfLeftCenterCircleLeftLCD,3,1,14);
						    HLCD_U8_CheckSwitchesMC1();


					  }
					  if(LOC_U8CurrentBallLocation>=64 &&LOC_U8CurrentBallLocation<=79)
					  {
						    HLCD_U8_CheckSwitchesMC1();

					LOC_U8CurrentBallLocation+=LOC_U8HeadsUpwards[LOC_U8ArrayIndex];
					HLCD_VoidWriteSpecialCharRealPosition(Ball,0,LOC_U8CurrentBallLocation);

					HLCD_U8_CheckSwitchesMC1();
					_delay_ms(200);
				    HLCD_U8_CheckSwitchesMC1();

				    HLCD_Void_sendCommand(128+LOC_U8CurrentBallLocation);
					HLCD_Void_sendChar(' ');
				    HLCD_U8_CheckSwitchesMC1();

					  }
					    HLCD_U8_CheckSwitchesMC1();





					LOC_U8CurrentBallLocation+=LOC_U8HeadsDownward[LOC_U8ArrayIndex];
					HLCD_VoidWriteSpecialCharRealPosition(Ball,0,LOC_U8CurrentBallLocation);

					HLCD_U8_CheckSwitchesMC1();
					_delay_ms(200);
				    HLCD_U8_CheckSwitchesMC1();

				    HLCD_Void_sendCommand(128+LOC_U8CurrentBallLocation);
					HLCD_Void_sendChar(' ');
				    HLCD_U8_CheckSwitchesMC1();






					LOC_U8seed++;
				}
				    HLCD_U8_CheckSwitchesMC1();



				  return LOC_U8CurrentBallLocation;

}

u8 HLCD_U8_BounceBallRightOnRightLCD(void)
{
#include "DrawingArrays.h"
    HLCD_U8_CheckSwitchesMC2();

	    u8 LOC_U8seed=1;
	    u8 LOC_U8HeadsDownward[]={64,65,1};
	    s8 LOC_U8HeadsUpwards[]={1,-64,-63};
	    u8  LOC_U8ArrayIndex;
	    u8 LOC_U8CurrentBallLocation=0;
	    HLCD_U8_CheckSwitchesMC2();

	    srand(LOC_U8seed);
	    LOC_U8ArrayIndex= (rand() %(2 - 0 + 1)) + 0;
	    HLCD_U8_CheckSwitchesMC2();





	    HLCD_U8_CheckSwitchesMC2();

				  while(LOC_U8CurrentBallLocation!= 13 && LOC_U8CurrentBallLocation!= 77)
				{
					    HLCD_U8_CheckSwitchesMC2();

					  if(LOC_U8CurrentBallLocation==2 || LOC_U8CurrentBallLocation==66)
					  {
						    HLCD_U8_CheckSwitchesMC2();
						  // draw center circle at left LCD after ball write on it after entering
					      HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfLeftCenterCircleRightLCD,4,0,0);
						  HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfLeftCenterCircleRightLCD,1,1,0);
						  HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfRighttCenterCircleRightLCD,2,0,1);
						  HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfRighttCenterCircleRightLCD,3,1,1);
						    HLCD_U8_CheckSwitchesMC2();


					  }
					  if(LOC_U8CurrentBallLocation>=64 &&LOC_U8CurrentBallLocation<=79)
					  {
						    HLCD_U8_CheckSwitchesMC2();

					LOC_U8CurrentBallLocation+=LOC_U8HeadsUpwards[LOC_U8ArrayIndex];
					HLCD_VoidWriteSpecialCharRealPosition(Ball,0,LOC_U8CurrentBallLocation);

					HLCD_U8_CheckSwitchesMC2();
					_delay_ms(200);
				    HLCD_U8_CheckSwitchesMC1();

				    HLCD_Void_sendCommand(128+LOC_U8CurrentBallLocation);
					HLCD_Void_sendChar(' ');

					  }
					    HLCD_U8_CheckSwitchesMC2();





					LOC_U8CurrentBallLocation+=LOC_U8HeadsDownward[LOC_U8ArrayIndex];
					HLCD_VoidWriteSpecialCharRealPosition(Ball,0,LOC_U8CurrentBallLocation);

					HLCD_U8_CheckSwitchesMC2();
					_delay_ms(200);
				    HLCD_U8_CheckSwitchesMC1();

				    HLCD_Void_sendCommand(128+LOC_U8CurrentBallLocation);
					HLCD_Void_sendChar(' ');





				    HLCD_U8_CheckSwitchesMC2();

					LOC_U8seed++;
				}
				    HLCD_U8_CheckSwitchesMC2();



				  return LOC_U8CurrentBallLocation;

}

u8 HLCD_U8_BounceBallLeftOnRightLCD(void)
{
#include "DrawingArrays.h"
    HLCD_U8_CheckSwitchesMC2();

	    u8 LOC_U8seed=1;
	    s8 LOC_U8HeadsDownward[]={64,63,-1};
	    s8 LOC_U8HeadsUpwards[]={-1,-64,-65};
	    u8  LOC_U8ArrayIndex;
	    u8 LOC_U8CurrentBallLocation=13;
	    HLCD_U8_CheckSwitchesMC2();

	    srand(LOC_U8seed);
	    LOC_U8ArrayIndex= (rand() %(2 - 0 + 1)) + 0;
	    HLCD_U8_CheckSwitchesMC2();






				  while(LOC_U8CurrentBallLocation!= 0 && LOC_U8CurrentBallLocation!= 64)
				{
					    HLCD_U8_CheckSwitchesMC2();


					  if(LOC_U8CurrentBallLocation>=64 &&LOC_U8CurrentBallLocation<=79)
					  {
						    HLCD_U8_CheckSwitchesMC2();

					LOC_U8CurrentBallLocation+=LOC_U8HeadsUpwards[LOC_U8ArrayIndex];
					HLCD_VoidWriteSpecialCharRealPosition(Ball,0,LOC_U8CurrentBallLocation);

					HLCD_U8_CheckSwitchesMC2();
					_delay_ms(200);
				    HLCD_U8_CheckSwitchesMC2();

				    HLCD_Void_sendCommand(128+LOC_U8CurrentBallLocation);
					HLCD_Void_sendChar(' ');
				    HLCD_U8_CheckSwitchesMC2();

					  }
					    HLCD_U8_CheckSwitchesMC2();





					LOC_U8CurrentBallLocation+=LOC_U8HeadsDownward[LOC_U8ArrayIndex];
					HLCD_VoidWriteSpecialCharRealPosition(Ball,0,LOC_U8CurrentBallLocation);

					HLCD_U8_CheckSwitchesMC2();
					_delay_ms(200);
				    HLCD_U8_CheckSwitchesMC2();

				    HLCD_Void_sendCommand(128+LOC_U8CurrentBallLocation);
					HLCD_Void_sendChar(' ');
				    HLCD_U8_CheckSwitchesMC2();






					LOC_U8seed++;
				}
				    HLCD_U8_CheckSwitchesMC2();

				  // draw center circle at left LCD after ball write on it after entering
				  HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfLeftCenterCircleRightLCD,4,0,0);
				  HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfLeftCenterCircleRightLCD,1,1,0);
				  HLCD_VoidWriteSpecialChar(LOC_U8FirstHalfRighttCenterCircleRightLCD,2,0,1);
				  HLCD_VoidWriteSpecialChar(LOC_U8SecondHalfRighttCenterCircleRightLCD,3,1,1);
				    HLCD_U8_CheckSwitchesMC2();


				    HLCD_U8_CheckSwitchesMC2();

				  return LOC_U8CurrentBallLocation;

}
