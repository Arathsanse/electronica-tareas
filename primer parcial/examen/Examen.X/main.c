/*
 * File:   main.c
 * Author: Santana
 *
 * Created on 11 de febrero de 2024, 09:25 PM
 */


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000
#define btnP1 PORTAbits.RA0
#define btnP2 PORTBbits.RB0
#define btnP3 PORTCbits.RC0
#define ledP1 PORTAbits.RA4
#define ledP2 PORTBbits.RB4
#define ledP3 PORTCbits.RC6
int i = 0;
int scP1 = -1;
int scP2 = -1;
int scP3 = -1;
                    //0  1 2  3  4   5   6   7  8   9   A   b   C  d  e   F
int display_array[]= {63,6,91,79,102,109,125,7,127,103,119,124,57,94,121,113};

void main(void) {
    ADCON1 = 0B00001111; 
    TRISD = 0;
    TRISAbits.RA0 = 1; //Bit RA0 se configura como puerto de entrada
    TRISBbits.RB0 = 1;
    TRISCbits.RC0 = 1;
    TRISAbits.RA4 = 0; //Bit RA0 se configura como puerto de entrada
    TRISBbits.RB4 = 0;
    TRISCbits.RC6 = 0;
    while(1){
        i = 0;
        scP1=-1;
        scP2=-1;
        scP3=-1;
        while(scP1==-1){
            if(i>15){
                i=0;
            }
            LATD = display_array[i];
            __delay_ms(100);
            if(btnP1== 1 ){ //condicion de lectura del puerto RA0
                scP1 = i;
                __delay_ms (5000);
                while(btnP1 == 1);
            }
            i+=1;
        }
        i = 0;
        while(scP2==-1){
            if(i>15){
                i=0;
            }
            LATD = display_array[i];
            __delay_ms(100);
            if(btnP2== 1 ){ //condicion de lectura del puerto RA0
                scP2 = i;
                __delay_ms (5000);
                while(btnP2 == 1);
            }
            i+=1;
        }
        i = 0;
        while(scP3==-1){
            if(i>15){
                i=0;
            }
            LATD = display_array[i];
            __delay_ms(100);
            if(btnP3== 1 ){ //condicion de lectura del puerto RA0
                scP3 = i;
                __delay_ms (5000);
                while(btnP3 == 1);
            }
            i+=1;
        }
        if(scP1>=scP2 && scP1>=scP3){
            LATAbits.LA4=1;
        }
        if(scP2>=scP1 && scP2>=scP3){
            LATBbits.LB4=1;
        }
        if(scP3>=scP2 && scP3>=scP1){
            LATCbits.LC6=1;
        }
        __delay_ms(10000);
        LATAbits.LA4=0;
        LATBbits.LB4=0;
        LATCbits.LC6=0;
    }
    return;
}