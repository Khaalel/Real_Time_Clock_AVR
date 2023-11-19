/**************************************/
/* Description : LCD c File           */
/* Author      : Moustafa Khalil      */
/* Version     : 0.1V                 */
/* Date        :           06 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/


#include "util/delay.h"
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"


void LCD_voidInit(void)
{
	uint8 u8CntLoc;
	uint8 u8commnad=0;
	for (u8CntLoc =0  ; u8CntLoc <MAX_NUM ; u8CntLoc++)
	{
		/*inilize 8 bit */
		if(lcdarr[u8CntLoc].lcdswconfig.u8mode ==LCD_8_BIT_MODE)
		{
			/*step 1*/
			_delay_ms(30);

			u8commnad=0b00110000 |lcdarr[u8CntLoc].lcdswconfig.u8font <<2
					|lcdarr[u8CntLoc].lcdswconfig.u8line<<3 ;
			/* send command */
			voidWriteCmd(u8CntLoc,u8commnad);
			/*more than 39 micro*/
			_delay_ms(1);
			u8commnad=0b00001000 |lcdarr[u8CntLoc].lcdswconfig.u8display<<2 |
									lcdarr[u8CntLoc].lcdswconfig.u8coursorstate<<1 |
									lcdarr[u8CntLoc].lcdswconfig.u8coursorblink<<0 ;

			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);
			voidWriteCmd(u8CntLoc,0x01);
			_delay_ms(3);
			u8commnad=0b00000100 | lcdarr[u8CntLoc].lcdswconfig.u8direction<<1 |

								lcdarr[u8CntLoc].lcdswconfig.u8shift<<0;


			voidWriteCmd(u8CntLoc,u8commnad);
			/*extra delay*/
			_delay_ms(3);


		}
		else
		{
			/*step 1*/
			_delay_ms(30);
			voidWriteCmd(u8CntLoc,0b00100000);

			voidWriteCmd(u8CntLoc,0b00100000);

			u8commnad=0b00000000 |lcdarr[u8CntLoc].lcdswconfig.u8line<<7 |
			lcdarr[u8CntLoc].lcdswconfig.u8font <<6 ;

			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);

			voidWriteCmd(u8CntLoc,0b00000000);

			u8commnad=0b10000000 |lcdarr[u8CntLoc].lcdswconfig.u8display<<6|
			lcdarr[u8CntLoc].lcdswconfig.u8coursorstate<<5 |
			lcdarr[u8CntLoc].lcdswconfig.u8coursorblink<<4 ;
			voidWriteCmd(u8CntLoc,u8commnad);
			_delay_ms(1);
			voidWriteCmd(u8CntLoc,0b00000000);
			voidWriteCmd(u8CntLoc,0b00010000);
			_delay_ms(3);
			voidWriteCmd(u8CntLoc,0b00000000);

			u8commnad= 0b01000000 | lcdarr[u8CntLoc].lcdswconfig.u8direction<<5 |
					   lcdarr[u8CntLoc].lcdswconfig.u8shift<<4 ;


			voidWriteCmd(u8CntLoc,u8commnad);
			/*extra delay*/
			_delay_ms(3);



		}


	}



}


static void voidWriteCmd(uint8 u8Index , uint8 u8CmdCPy)
 {

	/*RS   0*/
	DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8RS , DIO_LOW);

	/*help*/
	LCDHelp(u8Index,u8CmdCPy);

 }

static void  LCDHelp(uint8 u8Index , uint8 u8dataCmdCPy)
	{
		uint8 u8CntLoc=0;
		/*set to write to lCD */
		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8RW , DIO_LOW);

		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8E , DIO_HIGH);

		if (lcdarr[u8Index].lcdswconfig.u8mode==LCD_8_BIT_MODE)
		{
			for (u8CntLoc =0 ;u8CntLoc<8;u8CntLoc++)
			{
				DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.au8data[u8CntLoc],GET_BIT(u8dataCmdCPy,u8CntLoc));
			}

		}

		else
		{
			for (u8CntLoc =4 ;u8CntLoc<8;u8CntLoc++)
			{
				DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.au8data[u8CntLoc],GET_BIT(u8dataCmdCPy,u8CntLoc));
			}
		}
			/* latch */
		_delay_ms(10);
		DIO_enuWritePin(lcdarr[u8Index].lcdhwconfig.u8E , DIO_LOW);
		/*extra delay*/
		_delay_ms(10);
	}

void LCD_voidSendChar(uint8 u8IndexCpy, uint8 u8CharCpy)

{
	/*RS  1*/
	DIO_enuWritePin(lcdarr[u8IndexCpy].lcdhwconfig.u8RS , DIO_HIGH);


	if (lcdarr[u8IndexCpy].lcdswconfig.u8mode==LCD_8_BIT_MODE)
	{
		LCDHelp(u8IndexCpy,u8CharCpy);
		_delay_ms(1);

	}
	else
	{
		LCDHelp(u8IndexCpy,u8CharCpy);
		_delay_ms(1);
		LCDHelp(u8IndexCpy,u8CharCpy<<4);
		_delay_ms(1);

	}

	}



void LCD_voidSendCommand(uint8 u8IndexCpy, uint8 u8CommandCpy)
{
	if (lcdarr[u8IndexCpy].lcdswconfig.u8mode==LCD_8_BIT_MODE)
		{
			voidWriteCmd(u8IndexCpy,u8CommandCpy);
			_delay_ms(1);

		}
		else
		{
			voidWriteCmd(u8IndexCpy,u8CommandCpy);
			_delay_ms(1);
			voidWriteCmd(u8IndexCpy,u8CommandCpy<<4);
			_delay_ms(1);
		}

}



void LCD_voidSendString(uint8 u8IndexCpy, uint8* pau8CharCpy)
{
	uint8 u8CntLoc=0;
	while(pau8CharCpy[u8CntLoc]!= '\0')
			{
				LCD_voidSendChar(u8IndexCpy,pau8CharCpy[u8CntLoc])	;
				u8CntLoc++;
			}
}

void LCD_voidClrScr(uint8 u8IndexCpy)
	{
		LCD_voidSendCommand(u8IndexCpy,0x01);
	}

void LCD_voidSendNumber(uint8 u8IndexCpy,uint16 u16NumberCpy )
{
				//514
			uint16 u16NumRange = 1;
			//514/1=514  ==> 514/10=51 ==> 5
			while((u16NumberCpy/u16NumRange) >= 10)
			{
				//range=10 ==> 100>
				u16NumRange =u16NumRange*10;
			}

			while(u16NumRange != 0)
			{
				LCD_voidSendChar(0, ((u16NumberCpy/u16NumRange) + '0') );

				u16NumberCpy = u16NumberCpy % u16NumRange;
				u16NumRange =u16NumRange/ 10;
			}
}

//void LCD_voidSendHexString(uint8 u8IndexCpy, uint8* pau8ArrCpy,uint8 u8arrIndx)
//{
//	uint8 u8CntLoc=u8arrIndx;
//	while(pau8ArrCpy[u8CntLoc]!= '\0')
//			{
//				LCD_voidSendChar(u8IndexCpy,pau8ArrCpy[u8CntLoc])	;
//				u8CntLoc--;
//			}
//}

//void LCD_voidDisplayHex(uint8 u8IndexCpy,uint16 u16decimal_NumberCpy )
//{
//	uint8 u8arrhexa_Number[100];
//	uint8 u8arrIndex=1;
//	uint8 u8temp;
//	while (u16decimal_NumberCpy != 0) {
//	        u8temp = u16decimal_NumberCpy % 16;
//
//	        // converting decimal number
//	        // in to a hexa decimal
//	        // number
//	        if (u8temp < 10)
//	            u8temp = u8temp + 48;
//	        else
//	            u8temp = u8temp + 55;
//	        u8arrhexa_Number[u8arrIndex++] = u8temp;
//	        u16decimal_NumberCpy = u16decimal_NumberCpy / 16;
//	    }
//
//	u8arrhexa_Number[0] = '\0';

//LCD_voidSendHexString(u8IndexCpy,u8arrhexa_Number,u8arrIndex);
//}

void LCD_voidMoveCourser(uint8 u8IndexCpy,uint8 u8RowCPy,uint8 u8ColmCpy)
{
    uint8 u8AddressLoc=0;

    if (u8RowCPy == 0)
    {
        u8AddressLoc = 0x00 + u8ColmCpy;
    }
    else
    {
        u8AddressLoc = 0x40 + u8ColmCpy;
    }

    SET_BIT(u8AddressLoc,7);

    LCD_voidSendCommand(u8IndexCpy,u8AddressLoc);
}

/*void CLCD_voidSendHexaNumber(sint32 Copy_s32Number)
{
	//Define Variables/
	char Local_ch8HexaTable[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
									'A', 'B', 'C', 'D', 'E', 'F'};
	uint8 Local_u8HexaDigits[8];
	sint8 Local_s8PrintCounter;
	uint8 Local_u8ReverseCounter;
	uint8 Local_u8LeastFourBits;
	uint8 Local_u8PrintTemp;

	//Load the Hexadecimal digits into array of characters/
	for(Local_u8ReverseCounter = 0u; Local_u8ReverseCounter < 8u; Local_u8ReverseCounter++)
	{
		//Get the least for bits of the number/
		Local_u8LeastFourBits = Copy_s32Number & 0x0f;
		Copy_s32Number = Copy_s32Number >> 4;

		Local_u8HexaDigits[Local_u8ReverseCounter] = Local_u8LeastFourBits;
	}

	//Print 0x before Hexadecimal representation/
	CLCD_u8SendString("0x");

	//Print the hexadecimal number from array of hexadecimal table/
	for(Local_s8PrintCounter = 7; Local_s8PrintCounter >= 0; Local_s8PrintCounter--)
	{
		Local_u8PrintTemp = Local_u8HexaDigits[Local_s8PrintCounter];
		CLCD_voidSendData(Local_ch8HexaTable[Local_u8PrintTemp]);
	}
}
*/



/*void HLCD_voidSendNumbers (uint8 A_uint8LCDIndex , sint32 A_sint32Number)
{
    uint32 local_uint32Temp = 1;
    if (A_sint32Number != 0)
    {
        if (A_sint32Number < 0)
        {
            HLCD_voidSendData(A_uint8LCDIndex , '-');
            A_sint32Number = -(A_sint32Number);
        }
        while (A_sint32Number != 0)
        {
            local_uint32Temp = (local_uint32Temp*10) + (A_sint32Number%10);
            A_sint32Number = A_sint32Number/10;
        }
        while (local_uint32Temp !=1)
        {
            HLCD_voidSendOneNumber(A_uint8LCDIndex , local_uint32Temp%10);
            local_uint32Temp = local_uint32Temp/10;
        }
    }
    else
    {
        HLCD_voidSendOneNumber(A_uint8LCDIndex , 0);
    }

}*/
