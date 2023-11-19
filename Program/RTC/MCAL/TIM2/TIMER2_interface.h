/*****************************************************************/
/* Author  : ahmed saeed                                         */
/* Layer   : MCAL                                                */
/* SWC     : TIMER2                                              */
/* Version : 1.0                                                 */
/* Date    : 16 Aug 2023                                         */
/*****************************************************************/
#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_


#define PRESCALER_0   			0
#define PRESCALER_1    			1
#define PRESCALER_8	   		 	2
#define PRESCALER_32   			3
#define PRESCALER_64 	 		4
#define PRESCALER_128   	 	5
#define PRESCALER_256       	6
#define PRESCALER_1024  	 	7

void TIM2_voidInit(void);
void TIM2_voidEnable(uint8 u8PreScaler);
void TIM2_voidDisable(void);
void TIM2_voidEnableOvfINt(void);
void TIM2_voidDisableOvfINt(void);
void TIM2_voidEnableComparINt(void);
void TIM2_voidDisableCompareINt(void);
void TIM2_voidSetCallBackOvfInt(pf pfOvfcallBack);
void TIM2_voidSetCallBackCompareInt(pf pfComcallBack);
void TIM2_voidSetTCNTValue(uint8 u8TcntReg);
void TIM2_voidSetOCRValue(uint8 u8OcrReg);
void TIM2_voidExtClkEnable(void);
void TIM2_voidExtClkDisable(void);
uint8 TIM2_u8ReadTcntReg(void);

void TIM2_voidChangMode(uint8 u8Mode);









#endif
