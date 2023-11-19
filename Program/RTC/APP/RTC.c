

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include <util/delay.h>
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIM2/TIMER2_interface.h"
#include "../MCAL/GIE/GIE.h"
#include "../HAL/KEYPAD/KYEPAD.h"
#include "../HAL/LCD/LCD.h"

void PressedKey(void);
void SetTime(void);
void Clock(void);
void SendTime(void);

uint8 u8PressedKey=0xff;
uint8 u8Hrs,u8Mins,u8Sec;

void main(void)
{
	DIO_voidInit();
	KPD_voidInit();
	LCD_voidInit();
	TIM2_voidExtClkEnable();
	TIM2_voidInit();
	TIM2_voidSetCallBackOvfInt(Clock);
	TIM2_voidEnableOvfINt();
	TIM2_voidEnable(PRESCALER_128);

	LCD_voidSendString(0,"Welcome Khalil");
	_delay_ms(1000);
	LCD_voidClrScr(0);
	SetTime();
	GIE_voidEnable();
	while(1)
	{
      SendTime();
	}

}

void PressedKey(void)
{
	u8PressedKey=0xff;

	while(u8PressedKey==0xff)
	{
		u8PressedKey=KPD_u8GetPressedKey();
	}
}

void SetTime(void)
{
	uint8 u8Counter_loc=0;

	LCD_voidSendString(0,"Set Hours: ");


	while(u8Counter_loc<2)
	{
		PressedKey();
		if (u8PressedKey >= '0' && u8PressedKey <= '9')
		{
			//pressed key = '1'  //   pressed key ='2'
			 //hrs1   =   0*10      + '1'-'0'= 1  //  hrs2 = 1*10 + '2'-'0' =12
			u8Hrs = u8Hrs*10 +(u8PressedKey-'0');
			LCD_voidSendChar(0,u8PressedKey);
		}

		u8Counter_loc++;
	}

	_delay_ms(1000);
	LCD_voidClrScr(0);
	u8Counter_loc=0;

	LCD_voidSendString(0,"Set Minutes: ");

	while(u8Counter_loc<2)
	{
		PressedKey();
		if (u8PressedKey >= '0' && u8PressedKey <= '9')
		{
			u8Mins = u8Mins*10 +(u8PressedKey-'0');
			LCD_voidSendChar(0,u8PressedKey);
		}

		u8Counter_loc++;
	}
	_delay_ms(1000);
	LCD_voidClrScr(0);
	u8Counter_loc=0;

	LCD_voidSendString(0,"Set Seconds: ");


	while(u8Counter_loc<2)
	{
		PressedKey();
		if (u8PressedKey >= '0' && u8PressedKey <= '9')
		{
			u8Sec = u8Sec*10 +(u8PressedKey-'0');
			LCD_voidSendChar(0,u8PressedKey);
		}

		u8Counter_loc++;
	}
	_delay_ms(1000);
	LCD_voidClrScr(0);
}

void Clock(void)
{
	if (u8Sec<59)
	{
		u8Sec++;
	}
	else
	{
		u8Sec=0;

		if (u8Mins<59)
		{
			u8Mins++;
		}
		else
		{
			u8Mins=0;

			if (u8Hrs<23)
			{
				u8Hrs++;
			}
			else
			{
				u8Hrs=0;
			}
		}
	}
}

void SendTime(void)
{
	SEV_enuDisplay(0,(u8Hrs/10));
	SEV_enuEnable(0);
	_delay_ms(3);
	SEV_enuDisable(0);

	SEV_enuDisplay(1,(u8Hrs%10));
	SEV_enuEnable(1);
	_delay_ms(3);
	SEV_enuDisable(1);

	SEV_enuDisplay(2,(u8Mins/10));
	SEV_enuEnable(2);
	_delay_ms(3);
	SEV_enuDisable(2);

	SEV_enuDisplay(3,(u8Mins%10));
	SEV_enuEnable(3);
	_delay_ms(3);
	SEV_enuDisable(3);


	SEV_enuDisplay(4,(u8Sec/10));
	SEV_enuEnable(4);
	_delay_ms(3);
	SEV_enuDisable(4);

	SEV_enuDisplay(5,(u8Sec%10));
	SEV_enuEnable(5);
	_delay_ms(3);
	SEV_enuDisable(5);


}
