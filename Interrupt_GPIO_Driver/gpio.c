/*
 * gpio.c
 *
 *  Created on: 14 Feb 2020
 *      Author: AbdulRahman
 */
#include "gpio.h"


void GPIOClockSet(unsigned char port)
{
    volatile unsigned long int *reg = RCGCGPIO;
    unsigned long int data = *reg;
    data |= 1 << port;
    *reg = data;
}

void GPIODirModeSet(unsigned long int port, unsigned char pins, gpio_mode_t mode)
{
    volatile unsigned long int * reg    =    (port + GPIOAFSEL);
    unsigned long int data  =    *reg;

    data    &=   ~(pins);
    if (mode == MODE_AF)
        data    |=   (0xff & pins);
    else
        data    |=   (0x00 & pins);

    *reg    =    data;

    reg     =    port + GPIODIR;
    data    =    *reg;
    data    &=   ~(pins);
    if (mode == MODE_IN || mode == MODE_OUT)
    {
    data    |=   (mode & pins);
    }
    *reg    =    data;

    reg     =    port + GPIODEN;
    data    =    *reg;
    data    &=   ~(pins);
    data    |=   (pins);
    *reg    =    data;

}

void GPIOPadSet(unsigned long int port, unsigned char pins, gpio_drive_t str, gpio_pad_t pad)
{
    volatile unsigned long int * reg;
     reg    =    (port + str);

    unsigned long int data  =    *reg;
    data    &=   ~(pins);
    data    |=   (pins);
    *reg    =    data;

    reg     =    (port + pad);

    data    =    *reg;
    data    &=   ~(pins);
    data    |=   (pins);
    *reg    =    data;
}



//write function
void GPIOWrite(unsigned long int port, unsigned char pins, unsigned char data)
{
    unsigned long int *reg  =    (port + GPIODATA);
   unsigned short temp     =    pins<<2;
   port     |=    temp;
    reg     =    (port + GPIODATA);
    *reg    =    data;
}


unsigned char GPIORead(unsigned long int port, unsigned char pins)
{
    unsigned char data;
    unsigned long int *reg  =    (port + GPIODATA);
    unsigned short temp = pins<<2;

    port    |=    temp;
    reg     =     port;
    data    =    *reg;
    return (data & pins);
}




unsigned char GPIOClockGet(unsigned char port)
{
    volatile unsigned long int *reg     =    RCGCGPIO;

    return (*reg & (1 << port));
}

unsigned char GPIODirGet(unsigned long int port, unsigned char pins)
{
    volatile unsigned long int *reg     =    port + GPIODIR;

    return (*reg & pins);
}

unsigned char GPIOModeGet(unsigned long int port, unsigned char pins)
{
    volatile unsigned long int *reg     =    port + GPIOAFSEL;

    return(*reg & pins);
}


unsigned char GPIOPadOpenDrainGet(unsigned long int port, unsigned char pins)
{
    volatile unsigned long int *reg     =    port + GPIOODR;

    return(*reg & pins);
}

unsigned char GPIOPadPullUpGet(unsigned long int port, unsigned char pins)
{
    volatile unsigned long int *reg     =    port + GPIOPUR;

    return(*reg & pins);
}


unsigned char GPIOPadPullDownGet(unsigned long int port, unsigned char pins)
{
    volatile unsigned long int *reg     =    port + GPIOPDR;

    return(*reg & pins);
}

unsigned char GPIOPadDriveStrGet_8mA(unsigned long int port, unsigned char pins)
{
    volatile unsigned long int *reg     =    port + GPIODR8R;

    return(*reg & pins);
}

unsigned char GPIOPadDriveStrGet_4mA(unsigned long int port, unsigned char pins)
{
    volatile unsigned long int *reg     =    port + GPIODR4R;

    return(*reg & pins);
}

unsigned char GPIOPadDriveStrGet_2mA(unsigned long int port, unsigned char pins)
{
    volatile unsigned long int *reg     =    port + GPIODR2R;

    return(*reg & pins);
}


void Gpio_Interrupt_config(unsigned long int port, unsigned char pins,interrupt_sense detect,interrupt_mode mode)
{
    unsigned long int data = 0;
    unsigned long int *reg = (port + GPIOIM);

    //Mask the corresponding port by clearing the IME field in the GPIOIM register
    *reg    &=   ~(pins);

    //determine detect level or edge
    reg     =   port + GPIOIS;
    data    =   *reg;
    data    &=  ~(pins);
    data    |=  (detect & pins);
    *reg    =   data;

    //determine rising,falling or both(change)
    if (mode == Change)
    {
        reg     =   port + GPIOIBE;
        *reg    |=  (pins);
    }

    else if ( (mode == Rising) || (mode == Falling) )
    {
        reg     =   port + GPIOIBE;
        *reg    &=  ~(pins);

        reg     =   port + GPIOIEV;
        data    =   *reg;
        data    &=  ~(pins);
        data    |=  (mode & pins);
        *reg    =   data;
    }

    //Clear GPIORIS
    reg     =   port + GPIORIS;
    *reg    |=  pins;

    //unMask the corresponding port by setting the IME field in the GPIOIM register
    reg     =   port + GPIOIM;
    *reg    |=  (pins);

}

void clear_int_flag(unsigned long int port,unsigned char pins)
{
    unsigned long int*  reg     =    port + GPIOICR;
    *reg    |=   pins;
}
