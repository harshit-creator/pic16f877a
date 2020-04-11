#include<stdio.h>
#include<xc.h>
#include<stdlib.h>
#include<string.h>

#define _XTAL_FREQ 20000000
#define R1 RC0
#define R2 RC1
#define R3 RC2
#define R4 RC3
#define C1 RC4
#define C2 RC5
#define C3 RC6
#define LED1 RC7
#define LED2 RD2
#define LED3 RB0
#define LED4 RB1
#define LED5 RB2
#define LED6 RB3
#define LED7 RB4
#define LED8 RB5
#define LED9 RB6
#define LED10 RB7
#define LED11 RD0
#define LED12 RD1


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

void keypad(void);

int main(void)
{
    TRISC=0x00;
    TRISB=0x00;
    TRISD=0x00;
    PORTB=0x00;
    PORTC&=0<<7;
    PORTD=0x00;
    while(1)
    {    
        keypad();
    }
   return 0;
}

void keypad()
{
    TRISC=0xff;
    R1=0;
    R2=R3=R4=1;
    if(C1==0)
    {
        LED1=1;
        __delay_ms(500);
        LED1=0;
    }
    else if(C2==0)
    {
        LED2=1;
        __delay_ms(500);
        LED2=0;
    }
    else if(C3==0)
    {
        LED3=1;
        __delay_ms(500);
        LED3=0;
    }
    R2=0;
    R1=R3=R4=1;
    if(C1==0)
    {
        LED4=1;
        __delay_ms(500);
        LED4=0;
    }
    else if(C2==0)
    {
        LED5=1;
        __delay_ms(500);
        LED5=0;
    }
    else if(C3==0)
    {
        LED6=1;
        __delay_ms(500);
        LED6=0;
    }
    R3=0;
    R1=R2=R4=1;
    if(C1==0)
    {
        LED7=1;
        __delay_ms(500);
        LED7=0;
    }
    else if(C2==0)
    {
        LED8=1;
        __delay_ms(500);
        LED8=0;
    }
    else if(C3==0)
    {
        LED9=1;
        __delay_ms(500);
        LED9=0;
    } 
    R4=0;
    R1=R2=R3=1;
    if(C1==0)
    {
        LED10=1;
        __delay_ms(500);
        LED10=0;
    }
    else if(C2==0)
    {
        LED11=1;
        __delay_ms(500);
        LED11=0;
    }
    else if(C3==0)
    {
        LED12=1;
        __delay_ms(500);
        LED12=0;
    } 
}