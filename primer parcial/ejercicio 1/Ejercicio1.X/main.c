/*
 * File:   main.c
 * Author: Santana
 *
 * Created on 25 de enero de 2024, 08:07 AM
 */


#include <xc.h>
#include "config.h"

#define _XTAL_FREQ 2000000 //Frecuencia del cristal de 20 MHz


void main(void) {
    ADCON1 = 0X0F; //CONFIGURA EL MIRCO A DIGITAL
    TRISB = 0; //TODO  el puerto B es salida TODO
    
    while(1){ //bucle infinito
        LATBbits.LB0=1;//ENCIENDE 
        __delay_ms(500);
        LATBbits.LB1=1;//ENCIENDE 
        __delay_ms(500);
        LATBbits.LB2=1;//ENCIENDE 
        __delay_ms(500);
        LATBbits.LB3=1;//ENCIENDE 
        __delay_ms(500);
        LATBbits.LB4=1;//ENCIENDE 
        __delay_ms(500);
        LATBbits.LB5=1;//ENCIENDE 
        __delay_ms(500);
        LATBbits.LB6=1;//ENCIENDE 
        __delay_ms(500);
        LATBbits.LB7=1;//ENCIENDE 
        __delay_ms(500);
        
        //apagar
        LATBbits.LB0=0;
        __delay_ms(500);
        LATBbits.LB1=0;
        __delay_ms(500);
        LATBbits.LB2=0;
        __delay_ms(500);
        LATBbits.LB3=0; 
        __delay_ms(500);
        LATBbits.LB4=0;
        __delay_ms(500);
        LATBbits.LB5=0; 
        __delay_ms(500);
        LATBbits.LB6=0; 
        __delay_ms(500);
        LATBbits.LB7=0; 
        __delay_ms(500);
    }
    return;
}
