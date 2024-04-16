#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000

void ADC_init(void); 
int ADC_read(int); 

int sensor1 = 0;
int sensor2 = 0;
int sensores = 0;
int decenas = 0;
int unidades = 0;
int estado_bomba = 0;
int diferencia=0;
int display_array[]= {63,6,91,79,102,109,124,71,127,103,119,124,57,94,121,113};

void main(void) {
    TRISB = 0;
    TRISC = 0;
    TRISD = 0b00100010;
    ADC_init();
    while(1){
        LATDbits.LATD2 = 0; 
        LATDbits.LATD6 = 0; 
        sensor1 = ADC_read(0);
        sensor2 = ADC_read(1);
        sensores = ((sensor1+sensor2)/2)/10.23; 
        
        decenas =sensores/10; 
        LATB = display_array[decenas]; 
        __delay_ms(50);
        unidades = sensores -(decenas*10); //sacar unidades
        LATC = display_array[unidades]; //display en binairo
        LATDbits.LATD0 = 1;
        LATDbits.LATD1 = 0;
        __delay_ms(50);
        if(PORTDbits.RD7==1)
        {
            estado_bomba =estado_bomba+1; //contador
            while(PORTDbits.RD7==1); //secuestr
        }
        __delay_ms(20);
        if(estado_bomba==1)
        {
            LATDbits.LATD3 = 1;
        }
        __delay_ms(10);
        if(estado_bomba==2)
        {
            estado_bomba=0; //apagar bomba
            LATDbits.LATD3 = 0;
        }
        __delay_ms(10);
        if(val3 <=10 ){ //si es menor de 10 apagar bomba y encender led
            LATDbits.LATD3 = 0;
            estado_bomba=0;
            LATDbits.LATD2 = 1;
        }
        diferencia=ADC_read(0)-ADC_read(1); //sacar diferencia
        if(diferencia <0)
        {
            diferencia=-diferencia; //si es negativa convertirla en positivo
        }
        if(diferencia>=100 ){ // si la diferencia es mayor a 100 apagar bomba y encender led
            LATDbits.LATD3 = 0;
            estado_bomba=0;
            LATDbits.LATD2 = 1;
        }
        if(val3 >10 & diferencia <100)
        {
            LATDbits.LATD2 = 0; //si es mayor a 10 apagar led
        }
        /*if(diferencia<100)
        {
            LATDbits.LATD2 = 0; // si es menor a 100 diferencia apagar led
        }*/
        
        
    }
   
    return;
}
void ADC_init(void){
    TRISA = 0xFF; // Todos son entradas
    ADCON1 = 0x0D; // VSS, VDD Y dos entradas analógicas A0 y A1
    ADCON2 = 0xB5; // justificado a la derecha con 16 TAD, y FOSC/16
    ADRESH = 0; // Limpiamos el registro
    ADRESL = 0; // Limpiamos el registro
}

int ADC_read(int chanel){
    int digital = 0;
   
    // canal 0 es seleccionado 0000 y ADC está apagado
    ADCON0 = (ADCON0 & 0b11000011)|((chanel << 2) & 0b00111100);
   
    // habilitar el ADC y empezar la conversión
    ADCON0 |=((1<<ADON)| (1 << GO));
   
    //Esperar para el término de la conversión
    while(ADCON0bits.GO_nDONE==1);
   
    // Combinamos los 8 bits LSB y los 2 bits MSB
    digital = (ADRESH*256)|(ADRESL);
   
    return digital;
}
