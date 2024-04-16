#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 20000000

void ADC_init(void); // Inicializar los modulos ADC
int ADC_read(int); // Recibir un valor de 0 a 1023 y seleccionamos en qué canal

int val = 0;

void main(void) {
    TRISB = 0; // Salida de los led
   
    ADC_init();
    while(1){
        val = ADC_read(0);
        LATB = val; //mostrar l salida en binario de nuestra lectura en ADC
       
        __delay_ms(1000);
        val = 0;    
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