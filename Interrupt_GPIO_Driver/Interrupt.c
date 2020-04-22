/*
 * Interrupt.c
 *
 *  Created on: Apr 16, 2020
 *      Author: abdel
 */

#include "RegMap_Interrupt.h"
#include "Interrupt.h"

extern void (* g_pfnVectors[])(void);

#pragma DATA_ALIGN(g_pfnRAMVectors, 1024)
#pragma DATA_SECTION(g_pfnRAMVectors, ".vtable")

static void (*g_pfnRAMVectors[NUM_INTERRUPTS])(void);


void set_priority(Interrupt_number number,unsigned char value)
{
    volatile unsigned long int* reg = SET_ENABLE_BASE + PRI0 + 4 * (number / 4);
    *reg |= (value << ( 5 + (8 * ( number % 4 ) ) ) );

}



void set_enable(Interrupt_number number )
{
    unsigned long int* reg = SET_ENABLE_BASE + EN0 + 4*(number/32);
    *reg    |=   (1  << (number % 32));
}


void clear_enable(Interrupt_number number)
{
    unsigned long int* reg = SET_ENABLE_BASE + DIS0 + 4*(number/32);
    *reg    |=   (1  << (number % 32));
}


void Interrupt_Init(Interrupt_number number,void (*Handler)(void))
{
    unsigned long int* reg  =   SET_ENABLE_BASE +  VTABLE;
    int i = 0;

    for( i = 0; i < NUM_INTERRUPTS; i++)
       {
          g_pfnRAMVectors[i]    =    g_pfnVectors[i];
       }
    *reg = (unsigned long int)g_pfnRAMVectors;

    g_pfnRAMVectors[number + 16]     =   Handler ;
}


void Default_Handler()
{
    while(1);
}

void set_pending(Interrupt_number number)
{
    unsigned long int* reg  =   SET_ENABLE_BASE +  PEND0 + 4*(number/32);
    *reg    |=   (1  << (number % 32));

}


void clear_pending(Interrupt_number number)
{
    unsigned long int* reg  =   SET_ENABLE_BASE +  UNPEND0 + 4*(number/32);
    *reg    |=   (1  << (number % 32));
}

unsigned long int get_active(Interrupt_number number)
{
    unsigned long int* reg  =   SET_ENABLE_BASE +  ACTIVE0 + 4*(number/32);
    return(*reg & (1  << (number % 32 ) ) );

}

unsigned long int get_pending(Interrupt_number number)
{
    unsigned long int* reg  =   SET_ENABLE_BASE +  PEND0 + 4*(number/32);
    return(*reg & (1  << (number % 32 ) ) );

}
