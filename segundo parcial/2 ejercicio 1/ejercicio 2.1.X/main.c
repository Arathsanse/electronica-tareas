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
#define col1 PORTAbits.RA0
#define col2 PORTAbits.RA1
#define col3 PORTAbits.RA2
#define col4 PORTAbits.RA3
#define ren1 LATBbits.LB0
#define ren2 LATBbits.LB2
#define ren3 LATBbits.LB4
#define ren4 LATBbits.LB6

int value =0;
                    //0  1 2  3  4   5   6   7  8   9   A   b   C  d  e  F  Vacio
int display_array[]= {63,6,91,79,102,109,125,7,127,103,119,124,57,94,121,113,0};

void main(void) {
    ADCON1 = 0X0F; 
    TRISAbits.RA0 = 1; // RA0 se configura como puerto de entrada
    TRISAbits.RA1 = 1;
    TRISAbits.RA2 = 1;
    TRISAbits.RA3 = 1;
    TRISB = 0; // RB se configura como puerto de salida
    TRISD = 0;
    while(1){
        ren1=1;
        if(col1 == 1 ){LATD = display_array[10];}
        if(col2 == 1 ){LATD = display_array[1];}
        if(col3 == 1 ){LATD = display_array[2];}
        if(col4 == 1 ){LATD = display_array[3];}
        __delay_ms(.25);
        ren1=0;
        
        ren2=1;
        if(col1 == 1 ){LATD = display_array[11];}
        if(col2 == 1 ){LATD = display_array[4];}
        if(col3 == 1 ){LATD = display_array[5];}
        if(col4 == 1 ){LATD = display_array[6];}
        __delay_ms(.25);
        ren2=0;
        
        ren3=1;
        if(col1 == 1 ){LATD = display_array[12];}
        if(col2 == 1 ){LATD = display_array[7];}
        if(col3 == 1 ){LATD = display_array[8];}
        if(col4 == 1 ){LATD = display_array[9];}
        __delay_ms(.25);
        ren3=0;
        
        ren4=1;
        if(col1 == 1 ){LATD = display_array[13];}
        if(col2 == 1 ){LATD = display_array[14];}
        if(col3 == 1 ){LATD = display_array[0];}
        if(col4 == 1 ){LATD = display_array[15];}
        __delay_ms(.25);
        ren4=0;
        
        LATD = display_array[16];
    }
}