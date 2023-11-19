/**************************************/
/* Description : KYEPAD config c File */
/* Author      : Moustafa Khalil      */
/* Version     : 0.1V                 */
/* Date        : 		   07 Aug 2023*/
/* History     : 0.1V Initial Creation*/
/**************************************/


#include "../../MCAL/DIO/DIO_interface.h"

#ifndef KYEPAD_CFG_H
#define KYEPAD_CFG_H


/*input*/
#define KPD_ROW0    DIO_PIN_NUM_D0
#define KPD_ROW1    DIO_PIN_NUM_D1
#define KPD_ROW2    DIO_PIN_NUM_D2
#define KPD_ROW3    DIO_PIN_NUM_D3

/*output*/
#define KPD_COL0    DIO_PIN_NUM_D4
#define KPD_COL1    DIO_PIN_NUM_D5
#define KPD_COL2    DIO_PIN_NUM_D6
#define KPD_COL3    DIO_PIN_NUM_D7



#define KPD_BUTTONS    {\
						{'7' , '8',  '9',  '/'},\
						{'4' , '5',  '6',  '*'},\
						{'1' , '2',  '3',  '-'},\
						{'c' , '0',	 '=',  '+'}\
							}






#endif
