//Rafael Teixeira Arroyo 768092
//João Marcos Castelli 833251
//Rogério Luis Brigantini Junior 834831



#include <xc.h>

#define LED1 LATBbits.LATB1 // LED em B1
#define LED2 LATBbits.LATB2 // LED em B2
#define LOOP_LED LATBbits.LATB4 // LED do loop em B4

void Timer1_start();
void Timer2_start();
void atraso(void);

int contador = 0;


void main() {
    OSCCON = 0x72; // Configura para freq. 8MHz
   
    TRISBbits.TRISB1 = 0; // Coloca porta B bit 1 em output (LED1)
    TRISBbits.TRISB2 = 0; // Coloca porta B bit 2 em output (LED2)
    TRISBbits.TRISB4 = 0; // Coloca porta B bit 4 em output (LOOP LED)
    
    Timer1_start();
    Timer2_start(); 

    while(1) {
        LOOP_LED = 1; // Acende o LED do loop
        atraso();
        LOOP_LED = 0; // Apaga o LED do loop
        atraso();
    }
}


void __interrupt(high_priority) High_ISR(void) {
    if (PIR1bits.TMR1IF) {
        TMR1 = 0x0000; // Reinicia o Timer1
        if(contador == 31) {
            contador = 0;
            LED1 = ~LED1; // Inversão do LED em RB1
            LED2 = ~LED2; // Inverte o estado do LED em RB2
        }
        contador++;
        PIR1bits.TMR1IF = 0; // Limpa a flag do Timer1
    }

    if (PIR1bits.TMR2IF) {
        
        PIR1bits.TMR2IF = 0; // Limpa a flag do Timer2
    }
}

//-------------------------------------------------------------

void Timer2_start() {
    T2CON = 0x04; 
    PR2 = 124; 
    TMR2 = 0x0000;
    TMR2ON = 1; // Liga o Timer2
    PIE1bits.TMR2IE = 1; // Habilita a interrupção do Timer2
}

//-------------------------------------------------------------

void Timer1_start() {
    GIE = 1; // Habilita a Global Interrupt
    PEIE = 1; // Habilita a Peripheral Interrupt
    TMR1IE = 1; // Habilita o Timer1 Overflow Interrupt
    TMR1IF = 0; // Limpa a flag do Timer1
    T1CON = 0x80; 
    TMR1 = 
    TMR1ON = 1; // Liga o Timer1
}

//-------------------------------------------------------------

void atraso(void) {
    int i, j;
    for(i = 0; i < 5000; i++) {
        for(j = 0; j < 3; j++) {
            // No operation (delay loop)
        }
    }
}
