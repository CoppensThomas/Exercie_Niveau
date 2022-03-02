/*
 * File:   main.c
 * Author: Thoma
 *
 * Created on 2 mars 2022, 09:48
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#define XTAL_Freq 20000000
void main(void) {
    TRISA = 0b00001111; //RA0 to RA3 pin input
    TRISB = 0b00000000; //RB4 and RB5 pin output
    TRISC = 0b00000000; //RC3 and RC4 pin output
    
    PORTB = 0b00000000; //LED OFF
    
    SSPSTAT = 0b11000000; //Status register
    SSPCON = 0b00101000; //Control register
    SSPCON2 = 0b00000000; //COntrol register
    SSPADD = 49; // (freq Quartz/4*freq com)-1
         
    while(1)
    {
        
    }
    return;
}
