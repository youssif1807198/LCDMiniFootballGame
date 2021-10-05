
#ifndef _HLCD_INTERFACE_H_
#define _HLCD_INTERFACE_H_ 
#include "STD_TYPES.h"




void HLCD_Void_sendChar(u8 Copy_U8_Data);
void HLCD_Void_sendCommand(u8 Copy_U8_Command);
void HLCD_Void_Init(void);
void HLCD_Void_SendNumber(u32 Copy_U32_Number);
void HLCD_Void_SendString(u8 * Copy_U8_Ptr);
void HLCD_Void_DrawDal(void);
void HLCD_VoidWriteSpecialChar(u8 *Copy_U8Pattern,u8 Copy_U8PatternNumber,u8 Copy_U8Row,u8 Copy_U8Position);
void HLCD_VoidWriteSpecialCharRealPosition(u8 *Copy_U8Pattern,u8 Copy_U8PatternNumber,u8 Copy_U8Position);
void HLCD_Void_Set_DDRM_Position(u8 Copy_U8_Row, u8 Copy_U8_Column);
void HLCD_Void_DrawPlayGroundLeftLCD(void);
void HLCD_Void_DrawPlayGroundRightLCD(void);
u8 HLCD_U8_BounceBallRightOnLeftLCD(void);
u8 HLCD_U8_BounceBallLeftOnLeftLCD(void);
u8 HLCD_U8_BounceBallLeftOnRightLCD(void);
u8 HLCD_U8_BounceBallRightOnRightLCD(void);
u8 HLCD_U8_CheckSwitchesMC1 (void);
u8 HLCD_U8_CheckSwitchesMC2 (void);













#endif
