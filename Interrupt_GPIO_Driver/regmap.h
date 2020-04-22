/*
 * regmap.h
 *
 *  Created on: 14 Feb 2020
 *      Author: AbdulRahman
 */

#ifndef REGMAP_H_
#define REGMAP_H_

#define     RCGCGPIO        0x400FE608

#define     PORTA           0
#define     PORTB           1
#define     PORTC           2
#define     PORTD           3
#define     PORTE           4
#define     PORTF           5

#define     BUS             0               // 0 for APB , 1 for AHB

#if BUS == 0

#define     PORTA_APB       0x40004000
#define     PORTB_APB       0x40005000
#define     PORTC_APB       0x40006000
#define     PORTD_APB       0x40007000
#define     PORTE_APB       0x40024000
#define     PORTF_APB       0x40025000


#elif Bus == 1

#define     PORTA_AHB       0x40058000
#define     PORTB_AHB       0x40059000
#define     PORTC_AHB       0x4005A000
#define     PORTD_AHB       0x4005B000
#define     PORTE_AHB       0x4005C000
#define     PORTF_AHB       0x4005D000

#endif

#define     GPIODATA        0x000
#define     GPIODIR         0x400
#define     GPIOAFSEL       0x420
#define     GPIODR2R        0x500
#define     GPIODR4R        0x504
#define     GPIODR8R        0x508
#define     GPIOODR         0x50C
#define     GPIOPUR         0x510
#define     GPIOPDR         0x514
#define     GPIOSLR         0x518
#define     GPIODEN         0x51C

//interrupt registers
#define     GPIOIS          0x404
#define     GPIOIBE         0x408
#define     GPIOIEV         0x40C
#define     GPIOIM          0x410
#define     GPIORIS         0x414
#define     GPIOMIS         0x418
#define     GPIOICR         0x41C




#endif /* REGMAP_H_ */
