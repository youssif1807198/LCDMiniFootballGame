#ifndef _DRAWINGARRAYS_H_
#define _DRAWINGARRAYS_H_
#include "STD_Types.h"

    u8 Start[]="Start";
    u8 Space[]="     ";
    u8 Goal[]="Goal";
u8 LOC_U8FirstHalfRightCenterCircleLeftLCD[]=
{
		0b00011111,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00000011,
		0b00000111,
		0b00001111,
		0b00001111
};

u8 LOC_U8SecondHalfRightCenterCircleLeftLCD[]=
{
		0b00001111,
		0b00001111,
		0b00000111,
		0b00000011,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00011111,

};

u8 LOC_U8FirstHalfLeftCenterCircleLeftLCD[]=
{
		0b00000011,
		0b00000110,
		0b00001100,
		0b00011000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000
};

u8 LOC_U8SecondHalfLeftCenterCircleLeftLCD[]=
{
		0b00010000,
		0b00010000,
		0b00010000,
		0b00010000,
		0b00011000,
		0b00001100,
		0b00000110,
		0b00000011

};

u8 LOC_U8FirstHalfLeftCenterCircleRightLCD[]=
{
		0b00011111,
		0b00000000,
		0b00000000,
		0b00000000,
		0b11011000,
		0b00011100,
		0b00011110,
		0b00011110
};

u8 LOC_U8SecondHalfLeftCenterCircleRightLCD[]=
{
		0b00011110,
		0b00011110,
		0b00011100,
		0b11011000,
		0b00000000,
		0b00000000,
		0b00000000,
		0b00011111
};

u8 LOC_U8FirstHalfRighttCenterCircleRightLCD[]=
{
		0b00011000,
		0b00001100,
		0b00000110,
		0b00000011,
		0b00000001,
		0b00000001,
		0b00000001,
		0b00000001
};


u8 LOC_U8SecondHalfRighttCenterCircleRightLCD[]=
{
		0b00000001,
		0b00000001,
		0b00000001,
		0b00000001,
		0b00000011,
		0b00000110,
		0b00001100,
		0b00011000

};

u8 Ball[]=
	{
	        0b00011111,
			0b00011011,
			0b00011011,
			0b00010101,
			0b00010101,
			0b00010001,
			0b00011011,
			0b00011111
	};


u8 UpperNet[]=
	{
	        0b00011111,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000
	};

u8 LowerNet[]=
	{
		    0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00010000,
			0b00011111
	};
u8 UpperNet_Right[]=
	{
	        0b00011111,
			0b00000001,
			0b00000001,
			0b00000001,
			0b00000001,
			0b00000001,
			0b00000001,
			0b00000001
	};

u8 LowerNet_Right[]=
	{
		    0b00000001,
			0b00000001,
			0b00000001,
			0b00000001,
			0b00000001,
			0b00000001,
			0b00000001,
			0b00011111
	};

u8 Racket_Right[]=
	{
	        0b00011100,
	        0b00011100,
			0b00011100,
			0b00011111,
			0b00011111,
			0b00011100,
			0b00011100,
			0b00011100
	};
u8 Racket[]=
	{
	        0b00000111,
	        0b00000111,
			0b00000111,
			0b00011111,
			0b00011111,
			0b00000111,
			0b00000111,
			0b00000111
	};
#endif
