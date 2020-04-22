/*
 * RegMap_Interrupt.h
 *
 *  Created on: Apr 16, 2020
 *      Author: abdel
 */

#ifndef REGMAP_INTERRUPT_H_
#define REGMAP_INTERRUPT_H_



#define     SET_ENABLE_BASE     0xE000E000
#define     EN0                 0x100
#define     DIS0                0x180
#define     PRI0                0x400
#define     PEND0               0x200
#define     UNPEND0             0x280
#define     ACTIVE0             0x300
#define     VTABLE              0xD08



#define     NUM_INTERRUPTS      155




#endif /* REGMAP_INTERRUPT_H_ */
