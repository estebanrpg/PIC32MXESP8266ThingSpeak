#include "m_uart.h"


void Uart1_Config(unsigned int RxPin, unsigned int TxPin, unsigned int baudrate)
{
   U1RXR=RxPin;
   *((unsigned int *)TxPin)=1;
   
   U1MODEbits.IREN=0;
   U1MODEbits.UEN=0;
   U1MODEbits.WAKE=0;
   U1MODEbits.LPBACK=0;
   U1MODEbits.ABAUD=0;
   U1MODEbits.RXINV=0;
   U1MODEbits.BRGH=1;
   U1MODEbits.PDSEL=0;
   U1MODEbits.STSEL=0;
   
   U1STAbits.ADM_EN=0;
   U1STAbits.UTXISEL=0;
   U1STAbits.UTXINV=0;
   U1STAbits.UTXBRK=0;
   U1STAbits.URXISEL=0;
   U1STAbits.ADDEN=0;
   U1STAbits.OERR=0;
   
   U1BRG=(SYSCLK)/(4*baudrate)-1;   
}


void Uart1Puts(unsigned char *str)
{
    while(*str!='\0')
    {        
        Uart1WriteData(*str++);
    }
}


//==============================================================================


void Uart2_Config(unsigned int RxPin, unsigned int TxPin, unsigned int baudrate)
{
   U2RXR=RxPin;
   *((volatile unsigned int *)TxPin)=2;
   
   U2MODEbits.IREN=0;
   U2MODEbits.UEN=0;
   U2MODEbits.WAKE=0;
   U2MODEbits.LPBACK=0;
   U2MODEbits.ABAUD=0;
   U2MODEbits.RXINV=0;
   U2MODEbits.BRGH=1;
   U2MODEbits.PDSEL=0;
   U2MODEbits.STSEL=0;
   
   U2STAbits.ADM_EN=0;
   U2STAbits.UTXISEL=0;
   U2STAbits.UTXINV=0;
   U2STAbits.UTXBRK=0;
   U2STAbits.URXISEL=0;
   U2STAbits.ADDEN=0;
   U2STAbits.OERR=0;
   
   U2BRG=(SYSCLK)/(4*baudrate)-1;   
}


void Uart2Puts(unsigned char *str)
{
    while(*str!='\0')
    {
        Uart2WriteData(*str++);
    }
}

