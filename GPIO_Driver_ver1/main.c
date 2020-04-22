

/**
 * main.c
 */

#include "gpio.h"

int main(void)
{
    unsigned char test = 0;
    GPIOClockSet(PORTF);
    GPIODirModeSet(PORTF_APB,0X02,MODE_OUT);
    GPIOPadSet(PORTF_APB,0X02,Drive_2mA,Pad_PD);
    GPIOWrite(PORTF_APB,0X02,0x02);
    test = GPIORead(PORTF_APB, 0x02);

	return 0;
}

