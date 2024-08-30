#include <pic18f4550.h>		

#define Pulso LATB  		/* Define LATB para saida no PORTB */

void Timer1_delay();

void main()
{
    OSCCON=0x72;  		/* Configura para freq. de 8MHz */
    TRISB=0;  			/* Coloca a porta com output*/
    Pulso=0xff;  		/* Coloca os bits em nivel logico 1 */
    
    while(1)
    {
        Pulso=~Pulso;  		/* Faz a inversão da porta B na freq. de 500 Hz */ 
        Timer1_delay();  	/* Chama a rotina de delay */    
    }   
}

void Timer1_delay()
{
    /* habilita registro 16-bit TMR1, sem pre-scaler, clock interno,timer OFF */
    T1CON=0x80;  
    //
    TMR1=0xf830;		/* Carrega o valor para contar um delay de 1ms */
    T1CONbits.TMR1ON=1;  	/* Faz ON no Timer1 */
    while(PIR1bits.TMR1IF==0); 	/* Espera pelo flag INTR do timer */
    TMR1ON=0;  			/* Faz OFF no timer */
    TMR1IF=0;  			/* Coloca o flag em  '0' */
}
//--------------------------------------------------------------------------
