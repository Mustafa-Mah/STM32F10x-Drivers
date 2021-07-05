/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   13 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _AFIO_PRIVATE_H_
#define _AFIO_PRIVATE_H_

/*  Registers struct  */
typedef struct
{
    volatile u32 EVCR;
    volatile u32 MAPR;
    volatile u32 EXTICR[4];
    volatile u32 MAPR2;
} AFIO_t;

#define AFIO                    ((volatile AFIO_t*)0x40010000)

// Ports
#define AFIO_PORTA              0b0000
#define AFIO_PORTB              0b0001
#define AFIO_PORTC              0b0010
#define AFIO_PORTD              0b0011
#define AFIO_PORTE              0b0100
#define AFIO_PORTF              0b0101
#define AFIO_PORTG              0b0110

#endif // _AFIO_PRIVATE_H_