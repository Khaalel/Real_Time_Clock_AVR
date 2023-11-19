/**************************************/
/* Description : EXTINT0 header File  */
/* Author      : ahmed saeed          */
/* Version     : 0.1V                 */
/* Date        : 13:29:02  12 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/




#ifndef EXTINT0_H
#define EXTINT0_H





#define EXTINT0_LOW_LEVEL            0
#define EXTINT0_ON_CHANGE            1
#define EXTINT0_FALLING_EDGE         2
#define EXTINT0_RISING_EDGE          3



void EXTINT0_voidEnable(void);
void EXTINT0_voidDisable(void);
void EXTINT0_voidInit(void);
void EXTINT0_voidChangeSense(uint8 u8SenseStateCpy);
void EXTINT0_voidSEtCallBack(pf pfCallBack);








#endif
