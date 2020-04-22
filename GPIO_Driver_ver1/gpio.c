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
    volatile unsigned long int * reg = (port + GPIOAFSEL);
    unsigned long int data = *reg;

    data &= ~(pins);
    if (mode == MODE_AF)
        data |= (0xff & pins);
    else
        data |= (0x00 & pins);

    *reg = data;
    reg = port + GPIODIR;
    data = *reg;
    data &= ~(pins);
    if (mode == MODE_IN || mode == MODE_OUT)
    {
    data |= (mode & pins);
    }
    *reg = data;
    reg = port + GPIODEN;
    data = *reg;
    data &= ~(pins);
    data |= (pins);
    *reg = data;

}

void GPIOPadSet(unsigned long int port, unsigned char pins, gpio_drive_t str, gpio_pad_t pad)
{
    volatile unsigned long int * reg;
    if (str == Drive_2mA)
     reg = (port + GPIODR2R);

    else if (str == Drive_4mA)
      reg = (port + GPIODR4R);

    else if (str == Drive_8mA)
       reg = (port + GPIODR8R);


    unsigned long int data = *reg;
    data &= ~(pins);
    data |= (pins);
    *reg = data;

    if (pad == Pad_PU)
        reg = (port + GPIOPUR);

    else if (pad == Pad_PD)
         reg = (port + GPIOPDR);

    else if (pad == Drive_8mA)
          reg = (port + GPIODR8R);

    data = *reg;
    data &= ~(pins);
    data |= (pins);
    *reg = data;
    //else if (pad == PAD_NPU_NPD)
}


//read function

//write function
void GPIOWrite(unsigned long int port, unsigned char pins, unsigned char data)
{
    unsigned long int *reg = (port + GPIODATA);
    unsigned short temp = pins<<2;
    port = port >> 10;
    port= port <<10;
    //reg = port;
    port |=  temp;
    reg = port;
    *reg = data;
}


unsigned char GPIORead(unsigned long int port, unsigned char pins)
{
    unsigned char data;
    unsigned long int *reg = (port + GPIODATA);
    unsigned short temp = pins<<2;
    port = port >> 10;
    port= port <<10;
    port |=  temp;
    reg = port;
    data = *reg;
    return data;
}


unsigned char GPIOPadDriveStrGet(unsigned long int port, unsigned char pins)
{
  unsigned char data;
  unsigned long int *reg = (port + )
}
