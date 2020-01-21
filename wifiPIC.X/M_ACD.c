#include "M_ADC.h"


void ADC_config(unsigned int config,unsigned char numero_muestras)
{
    ANSELA|=config; 
    TRISA|=(config&0x00000003); 
    ANSELB|=(config>>2); 
    TRISB|=(config>>2);
            
    AD1CON1bits.FORM=4;
    AD1CON1bits.SSRC=7;    
    AD1CON1bits.CLRASAM=SCAN_SELECT_EN;
    
    AD1CON2bits.VCFG=0;
    AD1CON2bits.OFFCAL=0;
    AD1CON2bits.CSCNA=SCAN_SELECT_EN;
    AD1CON2bits.SMPI=numero_muestras-1;
    AD1CON2bits.BUFM=0;
    AD1CON2bits.ALTS=0;
    
    AD1CON3bits.ADRC=0;
    AD1CON3bits.SAMC=2;
    AD1CON3bits.ADCS=1; 
    
    AD1CHSbits.CH0NA=0;
    AD1CHSbits.CH0SA=12;
    
    AD1CSSL|=(config&0x000001FF)|((config&0x00020000)>>8)|((config&0x00010000)>>6)|((config&0x00008000)>>4);
}

void ADC_Channel(unsigned char canal)
{
    AD1CHSbits.CH0SA=canal;
}

void ADC_start(void)
{
    #if SCAN_SELECT_EN
        AD1CON1bits.ASAM=1;
    #else
        AD1CON1bits.SAMP=1;
    #endif
}

void ADC_enable(unsigned char cntrl)
{
    AD1CON1bits.ADON=cntrl;
}

void ADC_read(unsigned int *vector, unsigned char size)
{
    unsigned int i=0;
    for(i=0;i<size;i++)
    {
        *vector++=*(&ADC1BUF0+i*4);
    }
}


unsigned char ADC_test(void)
{
    if(IFS0bits.AD1IF==1)
    {
        IFS0bits.AD1IF=0;
        return 1;
    }
    else
    {
        return 0;
    }
}