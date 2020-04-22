/*
 * gpio.h
 *
 *  Created on: 14 Feb 2020
 *      Author: AbdulRahman
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "regmap.h"

typedef enum {MODE_IN = 0x00, MODE_OUT = 0xff, MODE_AF = 0x3} gpio_mode_t;
//typedef enum {PORTA, PORTB, PORTC} gpio_port_t;
typedef enum {AHB, APB} gpio_bus_t;
typedef enum {Drive_2mA, Drive_4mA, Drive_8mA, Drive_8mA_Selw} gpio_drive_t;
typedef enum {Pad_PU,Pad_PD,PAD_NPU_NPD,PAD_OD} gpio_pad_t;


//Functions prototype

void GPIOBusSet(unsigned long int port,gpio_bus_t bus);
gpio_bus_t GPIOBusGet(unsigned long int port);

void GPIOClockSet(unsigned char port);
void GPIOClockRst(unsigned long int port);
char GPIOClockGet(unsigned long int port);

void GPIODirModeSet(unsigned long int port, unsigned char pins, gpio_mode_t Mode);
unsigned char GPIODirGet(unsigned long int port, unsigned char pins);
unsigned char GPIOModeGet(unsigned long int port, unsigned char pins);

void GPIOPadSet(unsigned long int port, unsigned char pins, gpio_drive_t str, gpio_pad_t pad);
unsigned char GPIOPadDriveStrGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadOpenDrainGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadPullUpGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadPullDownGet(unsigned long int port, unsigned char pins);

unsigned char GPIORead(unsigned long int port, unsigned char pins);
void GPIOWrite(unsigned long int port, unsigned char pins, unsigned char data);

#endif /* GPIO_H_ */
