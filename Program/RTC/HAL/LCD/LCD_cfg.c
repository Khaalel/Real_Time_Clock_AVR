/***************************************/
/* Description : LCD config header File*/
/* Author      : Moustafa Khalil      */
/* Version     : 0.1V                  */
/* Date        :           06 Aug 2023 */
/* History     : 0.1V Initial Creation */
/***************************************/
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include"LCD_cfg.h"
#include"LCD_priv.h"

lcdconfig lcdarr[MAX_NUM]=
{

		{
				{

				LCD_4_BIT_MODE,LCD_TWO_LINE,LCD_FONT_5X7,LCD_COURSOR_ON,
				LCD_COURSOR_BLINK_OFF,LCD_SHIFT_OFF,LCD_DISPLAY_ON,LCD_LTR
		},
		{           /* RS*/         /* E*/      /* RW*/
				DIO_PIN_NUM_A0 ,DIO_PIN_NUM_A1,DIO_PIN_NUM_A2 ,

				{
						0,0,0,0,
						DIO_PIN_NUM_A4,DIO_PIN_NUM_A5,
						DIO_PIN_NUM_A6,DIO_PIN_NUM_A7

				}
		}

		}


};






