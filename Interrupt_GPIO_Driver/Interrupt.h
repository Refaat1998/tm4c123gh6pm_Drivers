/*
 * Interrupt.h
 *
 *  Created on: Apr 16, 2020
 *      Author: abdel
 */

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

typedef enum {GPIO_PORTA = 0, GPIO_PORTB= 1, GPIO_PORTC = 2, GPIO_PORTD = 3, GPIO_PORTE = 4, UART0 = 5, UART1 = 6,GPIO_PORTF = 30, UART2 = 33,
I2C2 = 68} Interrupt_number;
void set_enable(Interrupt_number number );
void set_priority(Interrupt_number number,unsigned char value);
void clear_enable(Interrupt_number number);
void Interrupt_Init(Interrupt_number number,void (*Handler)(void));
void Default_Handler (void);
void set_pending(Interrupt_number number);
void clear_pending(Interrupt_number number);
unsigned long int get_active(Interrupt_number number);
unsigned long int get_pending(Interrupt_number number);

#endif /* INTERRUPT_H_ */
