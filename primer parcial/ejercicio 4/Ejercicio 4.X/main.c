/*
 * File:   main.c
 * Author: Roberto Fernandez
 *
 * Created on 31 de enero de 2024, 07:28 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000 

int sumValue = 0;

void main(void) {
    ADCON1 = 0X0F; //CONFIGURA EL MIRCO A DIGITAL
    TRISB = 0; //TODO  el puerto B es salida TODO
    TRISD = 1;// PUERTO A ES ENTRADA
    
    while(1){ //bucle infinito
        if (PORTDbits.RD0==1){
            LATBbits.LATB0=1;
        }
        if (PORTDbits.RD1==1){
            LATBbits.LATB1=1;
        }
        if (PORTDbits.RD2==1){
            LATBbits.LATB2=1;
        }
        if (PORTDbits.RD3==1){
            LATBbits.LATB3=1;
        }
        if (PORTDbits.RD4==1){
            LATBbits.LATB4=1;
        }
        if (PORTDbits.RD5==1){
            LATBbits.LATB5=1;
        }
        if (PORTDbits.RD6==1){
            LATBbits.LATB6=1;
        }
        if (PORTDbits.RD7==1){
            LATBbits.LATB7=1;
        }
        if (PORTDbits.RD0==0){
            LATBbits.LATB0=0;
        }
        if (PORTDbits.RD1==0){
            LATBbits.LATB1=0;
        }
        if (PORTDbits.RD2==0){
            LATBbits.LATB2=0;
        }
        if (PORTDbits.RD3==0){
            LATBbits.LATB3=0;
        }
        if (PORTDbits.RD4==0){
            LATBbits.LATB4=0;
        }
        if (PORTDbits.RD5==0){
            LATBbits.LATB5=0;
        }
        if (PORTDbits.RD6==0){
            LATBbits.LATB6=0;
        }
        if (PORTDbits.RD7==0){
            LATBbits.LATB7=0;
        }
    }
    return;
}
