#ifndef _MDIO_INTERFACE_H_
#define _MDIO_INTERFACE_H_
#include "STD_Types.h"

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7


#define	DDRA_REG 0
#define	DDRB_REG 1
#define	DDRC_REG 2
#define	DDRD_REG 3

#define	PORTA_REG 0
#define	PORTB_REG 1
#define	PORTC_REG 2
#define	PORTD_REG 3

#define	PINA_REG 0
#define	PINB_REG 1
#define	PINC_REG 2
#define	PIND_REG 3


#define	Input  0
#define	Output 1

#define LOW  0
#define HIGH 1

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3



void DIO_Void_PinDirections (u8 Copy_U8_Port, u8 Copy_U8_Pin , u8 Copy_U8_Direction);
u8 DIO_U8_GetPinValue (u8 Copy_U8_Port, u8 Copy_U8_Pin);
void DIO_Void_SetPortValue(u8 Copy_U8_PORT,u8 Copy_U8_Value);
void DIO_Void_SetPinValue(u8 Copy_U8_PORT,u8 Copy_U8_Pin,u8 Copy_U8_Value);
void DIO_Void_PortDirection(u8 Copy_U8_Port,u8 Copy_U8_Direction);


#endif
