

/**
 * main.c
 */

#include "gpio.h"
#include "Interrupt.h"


void delayMs(int n);
extern void GPIOF_Handler(void);

int main(void)
{
    //GPIO Configuration
    GPIOClockSet(PORTF);

    //configure red led to be output
    GPIODirModeSet(PORTF_APB,0X02,MODE_OUT);
    GPIOPadSet(PORTF_APB,0X02,Drive_2mA,Pad_PD);

    //configure green led to be output
    GPIODirModeSet(PORTF_APB,0X08,MODE_OUT);
    GPIOPadSet(PORTF_APB,0X08,Drive_2mA,Pad_PD);

    //configure switch to be input
    GPIODirModeSet(PORTF_APB,0X10,MODE_IN);
    GPIOPadSet(PORTF_APB,0X10,Drive_8mA,Pad_PU);


    //Interrupt configuration
    Gpio_Interrupt_config(PORTF_APB,0X10,Edge,Falling);

    //Interrupt Priority
    set_priority(GPIO_PORTF,3);

    //Interrupt Enable
    set_enable(GPIO_PORTF);

    Interrupt_Init(GPIO_PORTF,GPIOF_Handler);

    while(1)
    {
        //Write output
        //if (GPIORead(PORTF_APB,0x10) == 0)
        //{
            GPIOWrite(PORTF_APB,0X02,0x02);
            delayMs(500);
            GPIOWrite(PORTF_APB,0X02,0x00);
            delayMs(500);
        //}

        //else
          //  GPIOWrite(PORTF_APB,0X02,0x00);

    }

	return 0;
}


void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} /* do nothing for 1 ms */
}


void GPIOF_Handler(void)
{
    clear_int_flag(PORTF_APB,0x10);
 int i;

    for (i = 0; i < 3; i++)
    {
    GPIOWrite(PORTF_APB,0X02,0x00);
    delayMs(500);
    GPIOWrite(PORTF_APB,0X08,0x08);
    delayMs(500);
    GPIOWrite(PORTF_APB,0X08,0x00);
      //  delayMs(500);
    }


}
