
#include "M_Timers.h"
//TIMER 1 Funciones de control y manipulacion
void TMR1_config(unsigned int config, unsigned int periodo)
{
    T1CON=config;
    TMR1_Periodo(periodo);
    TMR1_write(0);
    
}

void TMR1_cntrl(unsigned char on_off)
{
    T1CONbits.ON=(on_off&1);
    asm("nop");
}

void TMR1_Periodo(unsigned int periodo)
{
    PR1=periodo;
}

unsigned int TMR1_read(void)
{
    return(TMR1);
}

void TMR1_write(unsigned int valor)
{
    TMR1=valor;
}

unsigned char TMR1_Test(void)
{
    if(IFS0bits.T1IF==1)
    {
        IFS0bits.T1IF=0;
        return(1);
    }
    else
    {
        return(0);
    }
    
}


//Funciones de COntrol y Manipulacion TIMER 2

void TMR2_config(unsigned int config, unsigned int periodo)
{
    T2CON=config;
    TMR2_Periodo(periodo);
    TMR2_write(0); 
}

void TMR2_cntrl(unsigned char on_off)
{
    T2CONbits.ON=(on_off&1);
    asm("nop");
}

void TMR2_Periodo(unsigned int periodo)
{
    PR2=periodo;
}

unsigned int TMR2_read(void)
{
    return(TMR2);
}

void TMR2_write(unsigned int valor)
{
    TMR2=valor;
}

unsigned char TMR2_Test(void)
{
    if(IFS0bits.T2IF==1)
    {
        IFS0bits.T2IF=0;
        return(1);
    }
    else
    {
        return(0);
    }
    
}


//Funciones de COntrol y Manipulacion TIMER 3

void TMR3_config(unsigned int config, unsigned int periodo)
{
    T3CON=config;
    TMR3_Periodo(periodo);
    TMR3_write(0); 
}

void TMR3_cntrl(unsigned char on_off)
{
    T3CONbits.ON=(on_off&1);
    asm("nop");
}

void TMR3_Periodo(unsigned int periodo)
{
    PR3=periodo;
}

unsigned int TMR3_read(void)
{
    return(TMR3);
}

void TMR3_write(unsigned int valor)
{
    TMR3=valor;
}

unsigned char TMR3_Test(void)
{
    if(IFS0bits.T3IF==1)
    {
        IFS0bits.T3IF=0;
        return(1);
    }
    else
    {
        return(0);
    }
    
}



//Funciones de COntrol y Manipulacion TIMER 4

void TMR4_config(unsigned int config, unsigned int periodo)
{
    T4CON=config;
    TMR4_Periodo(periodo);
    TMR4_write(0); 
}

void TMR4_cntrl(unsigned char on_off)
{
    T4CONbits.ON=(on_off&1);
    asm("nop");
}

void TMR4_Periodo(unsigned int periodo)
{
    PR4=periodo;
}

unsigned int TMR4_read(void)
{
    return(TMR4);
}

void TMR4_write(unsigned int valor)
{
    TMR4=valor;
}

unsigned char TMR4_Test(void)
{
    if(IFS0bits.T4IF==1)
    {
        IFS0bits.T4IF=0;
        return(1);
    }
    else
    {
        return(0);
    }
    
}


//Funciones de COntrol y Manipulacion TIMER 5

void TMR5_config(unsigned int config, unsigned int periodo)
{
    T5CON=config;
    TMR5_Periodo(periodo);
    TMR5_write(0); 
}

void TMR5_cntrl(unsigned char on_off)
{
    T5CONbits.ON=(on_off&1);
    asm("nop");
}

void TMR5_Periodo(unsigned int periodo)
{
    PR5=periodo;
}

unsigned int TMR5_read(void)
{
    return(TMR5);
}

void TMR5_write(unsigned int valor)
{
    TMR5=valor;
}

unsigned char TMR5_Test(void)
{
    if(IFS0bits.T5IF==1)
    {
        IFS0bits.T5IF=0;
        return(1);
    }
    else
    {
        return(0);
    }
    
}


//Funciones de COntrol y Manipulacion TIMER 23

void TMR23_config(unsigned int config, unsigned int periodo)
{
    T2CON=config|0x00000008;
    TMR23_Periodo(periodo);
    TMR23_write(0); 
}

void TMR23_cntrl(unsigned char on_off)
{
    T2CONbits.ON=(on_off&1);
    asm("nop");
}

void TMR23_Periodo(unsigned int periodo)
{
    PR2=periodo;
    PR3=periodo>>16;
}

unsigned int TMR23_read(void)
{
    unsigned int tmp=0;
    tmp=TMR3;
    tmp=(tmp<<16)|TMR2;
    return(tmp);
}

void TMR23_write(unsigned int valor)
{
    TMR2=valor;
    TMR3=valor>>16;
}

unsigned char TMR23_Test(void)
{
    if(IFS0bits.T3IF==1)
    {
        IFS0bits.T3IF=0;
        return(1);
    }
    else
    {
        return(0);
    }
    
}

//Funciones de COntrol y Manipulacion TIMER 45

void TMR45_config(unsigned int config, unsigned int periodo)
{
    T4CON=config|0x00000008;
    TMR45_Periodo(periodo);
    TMR45_write(0); 
}

void TMR45_cntrl(unsigned char on_off)
{
    T4CONbits.ON=(on_off&1);
    asm("nop");
}

void TMR45_Periodo(unsigned int periodo)
{
    PR4=periodo;
    PR5=periodo>>16;
}

unsigned int TMR45_read(void)
{
    unsigned int tmp=0;
    tmp=TMR5;
    tmp=(tmp<<16)|TMR4;
    return(tmp);
}

void TMR45_write(unsigned int valor)
{
    TMR4=valor;
    TMR5=valor>>16;
}

unsigned char TMR45_Test(void)
{
    if(IFS0bits.T5IF==1)
    {
        IFS0bits.T5IF=0;
        return(1);
    }
    else
    {
        return(0);
    }
    
}