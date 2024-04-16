#include <xc.h>
#include <pic18f4550.h>
#include "config.h"
#include"LCD-XC4.h"
#define _XTAL_FREQ 20000000
void tecladito();
int teclado[4];
int cont;
int par;

void main(void) {
    ADCON1 = 0B00001111; 
    TRISD = 0B11110000; 
    TRISA = 0B11111100; 
    mOPEN_LCD;
    mLCD_HOME;
    mLCD_CLEAR;
    LATAbits.LA0=1;
    while(1){
        if(PORTAbits.RA2==1)
        {
        while(PORTAbits.RA2==1); 
           
            par=cont/2;
                    if(cont-2*par==0)
                    {
                        LATAbits.LA1=1;
                        LATAbits.LA0=0;
                    }
                    if(cont-2*par==1){
                        LATAbits.LA1=0;
                        LATAbits.LA0=1;
                    }
            
                    cont++;
            
            
            
        }
        if(PORTAbits.RA3==1)
        {
             
            
            text_display("teclear contra");
            mCURSOR_LINE2;
            text_display("espere");
            __delay_ms(300);
            while(teclado[0]!=1 | teclado[1]!=2 | teclado[2]!=3 | teclado[3]!=4)
            {
                mLCD_CLEAR;
                tecladito();
                if(teclado[0]!=1 | teclado[1]!=2 | teclado[2]!=3 | teclado[3]!=4)
                {
                    text_display("cont incorrecta");
                    mCURSOR_LINE2;
                    text_display("repita");
                    LATAbits.LA0=1;
                    LATAbits.LA1=0;
                    __delay_ms(150);
                    teclado[0]=0;
                    teclado[1]=0;
                    teclado[2]=0;
                    teclado[3]=0;
                    
                }
            }
            mLCD_CLEAR;
            teclado[0]=0;
            teclado[1]=0;
            teclado[2]=0;
            teclado[3]=0;
            LATAbits.LA0=0;
            LATAbits.LA1=1;
        }
        if(PORTAbits.RA4 ==1)
        {
           LATAbits.LA1=0;
           LATAbits.LA0=1;
        }
        
    }
    
    
    
    __delay_ms(1000);
    return;
}
void tecladito(){
    int contador = 0;
    while(contador<4)
    {
        
        __delay_ms(10);
        LATDbits.LD0 = 1;
        LATDbits.LD1 = 0;
        LATDbits.LD2 = 0;
        LATDbits.LD3 = 0;
        
        if(PORTDbits.RD7==1)
        {
            while(PORTDbits.RD5==1);
            teclado[contador]=3;
            contador++;
            
            
            
        }
        if(PORTDbits.RD6==1)
        {
           while(PORTDbits.RD6==1);
           teclado[contador]=2;
           contador++;
            
        }
        if(PORTDbits.RD5==1)
        {
            teclado[contador]=1;
            while(PORTDbits.RD5==1);
            contador++;
        }
        if(PORTDbits.RD4==1)
        {
           
            contador++;
        }
        __delay_ms(10);
        LATDbits.LD0 = 0;
        LATDbits.LD1 = 1;
        LATDbits.LD2 = 0;
        LATDbits.LD3 = 0;
        if(PORTDbits.RD7==1)
        {
            teclado[contador]=6;
            contador++;
        }
        if(PORTDbits.RD6==1)
        {
            teclado[contador]=5;
            contador++;
        }
        if(PORTDbits.RD5==1)
        {
            while(PORTDbits.RD5==1);
            teclado[contador]=4;
            contador++;
        }
        if(PORTDbits.RD4==1)
        {
            
           contador++;
        }
        __delay_ms(10);
        LATDbits.LD0 = 0;
        LATDbits.LD1 = 0;
        LATDbits.LD2 = 1;
        LATDbits.LD3 = 0;
        if(PORTDbits.RD7==1)
        {
            teclado[contador]=9;
            contador++;
        }
        if(PORTDbits.RD6==1)
        {
            teclado[contador]=8;
            contador++;
        }
        if(PORTDbits.RD5==1)
        {
           teclado[contador]=7;
            contador++;
        }
        if(PORTDbits.RD4==1)
        {
            
           contador++;
        }
        __delay_ms(10);
        LATDbits.LD0 = 0;
        LATDbits.LD1 = 0;
        LATDbits.LD2 = 0;
        LATDbits.LD3 = 1;
        if(PORTDbits.RD7==1)
        {
            
            contador++;
        }
        if(PORTDbits.RD6==1)
        {
           teclado[contador]=0;
            contador++;
        }
        if(PORTDbits.RD5==1)
        {
           
            contador++;
        }
        if(PORTDbits.RD4==1)
        {
            contador++;
        }
        if(PORTAbits.RA2==1)
        {
            while(PORTAbits.RA2==1);
            teclado[0]=1;
            teclado[1]=2;
            teclado[2]=3;
            teclado[3]=4;
            contador=4;
            
        }
    }
    
    
    
}

