#include <xc.h>
#pragma config FOSC = INTOSCIO_EC
#pragma config FCMEN = OFF
#pragma config BORV = 3
#pragma config WDT = OFF
#pragma config CPB = OFF
#pragma config CPD = OFF
#pragma config BOR = OFF, PWRT = ON
#pragma config CCP2MX = ON, PBADEN = OFF, MCLRE = ON
#pragma config DEBUG = OFF, STVREN = OFF, XINST = OFF, LVP = OFF
#pragma config ICPRT = ON

void atraso (void)
{
    int i, j;
    for(i = 0; i<5; i++)
        {
        for (j = 0; j<5000; j++)
            {
        
            }
        }
}

void main(void) 
{
    TRISB = 0; // Porta b configurada como saída
    while(1)
    {
        LATBbits.LATB0 = 1;
        atraso();
        LATBbits.LATB0 = 0;
        atraso();
    }
}
