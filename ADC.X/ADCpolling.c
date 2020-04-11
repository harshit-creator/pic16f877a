#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic16f877a.h>
#define _XTAL_FREQ 20000000

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

void adc_init();
void adc_conversion();
int main()
{
    adc_init();
    while(1)
    {
        adc_conversion();
    }
    return 0;
}

void adc_init()
{   //fosc/4
    TRISA|=1<<0;
    ADCON0|=(1<<2)|(1<<0);
    ADCON1=0xc0;
}

void adc_conversion()
{
    ADCON0|=(1<<2);
    while(ADCON0&(1<<2));
    unsigned int adc_data=ADRESL;
    adc_data|=ADRESH<<8;   
}