#ifndef _BITMATH_H_
#define _BITMATH_H_

#define SET_BIT(var,bit) var=var|(1<<bit) //function to set bit
#define CLEAR_BIT(var,bit) var=var & ~(1<<bit)//function to clear bit
#define TOGGLE_BIT(var,bit) var=var ^ (1<<bit)//function to toggle bit
#define GET_BIT(var,bit)   (var>>bit) & 1 //function to get bit 

#endif
