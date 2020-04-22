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
typedef enum {Drive_2mA = GPIODR2R, Drive_4mA = GPIODR4R, Drive_8mA = GPIODR8R, Drive_8mA_Selw = GPIOSLR} gpio_drive_t;
typedef enum {Pad_PU = GPIOPUR,Pad_PD = GPIOPDR,PAD_OD = GPIOODR} gpio_pad_t;


//Interrupt modes
typedef enum {Level = 0xff,Edge = 0x00}interrupt_sense;
typedef enum {Rising = 0xff ,Falling = 0x00 ,Change = 0x03} interrupt_mode;

//Functions prototype

void GPIOBusSet(unsigned long int port,gpio_bus_t bus);
gpio_bus_t GPIOBusGet(unsigned long int port);

void GPIOClockSet(unsigned char port);
void GPIOClockRst(unsigned long int port);
unsigned char GPIOClockGet(unsigned char port);

void GPIODirModeSet(unsigned long int port, unsigned char pins, gpio_mode_t Mode);
unsigned char GPIODirGet(unsigned long int port, unsigned char pins);
unsigned char GPIOModeGet(unsigned long int port, unsigned char pins);

void GPIOPadSet(unsigned long int port, unsigned char pins, gpio_drive_t str, gpio_pad_t pad);
unsigned char GPIOPadDriveStrGet_8mA(unsigned long int port, unsigned char pins);
unsigned char GPIOPadDriveStrGet_4mA(unsigned long int port, unsigned char pins);
unsigned char GPIOPadDriveStrGet_2mA(unsigned long int port, unsigned char pins);
unsigned char GPIOPadOpenDrainGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadPullUpGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadPullDownGet(unsigned long int port, unsigned char pins);

unsigned char GPIORead(unsigned long int port, unsigned char pins);
void GPIOWrite(unsigned long int port, unsigned char pins, unsigned char data);

void clear_int_flag(unsigned long int port,unsigned char pins);
//Interrupt Functions prototypes
void Gpio_Interrupt_config(unsigned long int port, unsigned char pins,interrupt_sense detect,interrupt_mode mode);

#endif /* GPIO_H_ */
