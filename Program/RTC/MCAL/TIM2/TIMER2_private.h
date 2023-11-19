/*****************************************************************/
/* Author  : ahmed saeed                                         */
/* Layer   : MCAL                                                */
/* SWC     : TIMER2                                              */
/* Version : 1.0                                                 */
/* Date    : 16 Aug 2023                                         */
/*****************************************************************/

#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_

#define TIM2_NORMAL       10
#define TIM2_CTC          20
#define TIM2_FAST_PWM     30
#define TIM2_PHASE_PWM    40

/* non pwm modes */
#define TIM2_TOGL_OC0        0
#define TIM2_SET_OC0         1
#define TIM2_CLR_OC0         2

/*  pwm modes */
#define TIM2_FAST_INVERT_OC0           3
#define TIM2_FAST_NONINVERT_OC0        4

#define TIM2_PHASE_INVERT_OC0           5
#define TIM2_PHASE_NONINVERT_OC0        6

#define TIM2_DISCONNECT                 7




#define ASSR        *((volatile  uint8*) 0x42)
#define OCR2        *((volatile  uint8*) 0x43)
#define TCNT2       *((volatile  uint8*) 0x44)
#define TCCR2       *((volatile  uint8*) 0x45)
#define SFIOR       *((volatile  uint8*) 0x50)
#define TIFR        *((volatile  uint8*) 0x58)
#define TIMSK       *((volatile  uint8*) 0x59)





#endif
