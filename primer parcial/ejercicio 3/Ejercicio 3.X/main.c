/*
 * File:   main.c
 * Author: Roberto Fernandez
 *
 * Created on 31 de enero de 2024, 07:28 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000 
#define btnSum PORTAbits.RA0
#define btnRes PORTAbits.RA1
#define btnDel PORTAbits.RA2

int sumValue = 0;

void main(void) {
    ADCON1 = 0X0F; //CONFIGURA EL MIRCO A DIGITAL
    TRISB = 0; //TODO  el puerto B es salida TODO
    TRISAbits.RA0 = 1; //Bit RA0 se configura como puerto de entrada
    TRISAbits.RA1 = 1;
    TRISAbits.RA2 = 1;
    
    while(1){ //bucle infinito
        if(btnSum == 1 ){ //condicion de lectura del puerto RA0
            sumValue += 1; // sumValue = sumValue + 1 
            if(sumValue == 255){
                sumValue =0;
            }
            while(btnSum == 1);
        }
        else if (btnRes == 1){
            sumValue -= 1;
            if(sumValue == 0){
                sumValue =255;
            }
            while(btnRes == 1);
        }
        else if (btnDel == 1){
            sumValue = 0;
            while(btnDel == 1);
        }
        LATB = sumValue; // MANDA el valor sumValue a la salida del micro
    }
    return;
}
