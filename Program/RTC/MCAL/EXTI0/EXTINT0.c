/**************************************/
/* Description : EXTINT0 c File       */
/* Author      : ahmed saeed          */
/* Version     : 0.1V                 */
/* Date        : 13:29:02  12 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/
#include"../../LIB/STD_Types.h"
#include"../../LIB/BIT_Math.h"

#include "EXTINT0.h"
#include "EXTINT0_priv.h"
#include "EXTINT0_cfg.h"

pf EXTINT_pfCall;
void EXTINT0_voidEnable(void)
{
	SET_BIT(GICR ,6);
}
void EXTINT0_voidDisable(void)
{
	CLR_BIT(GICR ,6);
}
void EXTINT0_voidInit(void)
{
#if EXTINT_SENSE_MODE == EXTINT0_LOW_LEVEL

	CLR_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXTINT_SENSE_MODE == EXTINT0_ON_CHANGE
	SET_BIT(MCUCR,0);
	CLR_BIT(MCUCR,1);
#elif EXTINT_SENSE_MODE == EXTINT0_FALLING_EDGE
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#elif EXTINT_SENSE_MODE == EXTINT0_RISING_EDGE
	SET_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#else    // default as falling
	CLR_BIT(MCUCR,0);
	SET_BIT(MCUCR,1);
#endif

}
void EXTINT0_voidChangeSense(uint8 u8SenseStateCpy)
{

	switch(u8SenseStateCpy)
	{
	case EXTINT0_LOW_LEVEL  :
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;
	case EXTINT0_ON_CHANGE  :
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
		break;

	case EXTINT0_FALLING_EDGE :
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	case EXTINT0_RISING_EDGE :
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;
	default :
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
		break;



	}
}

void EXTINT0_voidSEtCallBack(pf pfCallBack)
{
	EXTINT_pfCall =pfCallBack;
}

void __vector_1(void)   __attribute__ ((signal,used)); // for optimize

void __vector_1(void)
{
	EXTINT_pfCall();
}
