/*
 * File:   main.c
 * Author: Roberto Fernandez
 *
 * Created on 1 de febrero de 2024, 07:36 AM
 */

//contador del 0 al F
#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000
int value =0;
                    //0 1 2 3 4 5 6 7 8 9 A b C d e F
int display_array[]= {63,6,91,79,102,109,125,7,127,103,119,124,57,94,121,113};

void main(void) {
    ADCON1 = 0B00001111; 
    TRISD = 0;
    TRISEbits.RE0 =0;
    TRISEbits.RE1 =0;
    for(int i=0; i<=15; i++){
        LATD = display_array[i];
        if (i%2 == 0){
            LATEbits.LE0 = 0;
            LATEbits.LE1 = 1;
        }
        else{
            LATEbits.LE0=1;
            LATEbits.LE1=0;
        }
        __delay_ms(500);
    }
    return;
}