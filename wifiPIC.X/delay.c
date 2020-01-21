#include "delay.h"

void delay_ms(unsigned int ms)
{
    unsigned int delay=0, tick=0, tock=0, elapsed=0;
    delay=(SYSCLK/2000)*ms;
    tick=_CP0_GET_COUNT();
    
    while(elapsed<delay)
    {
        tock=_CP0_GET_COUNT();
        if(tock<=tick)
        {
            elapsed=(0xffffffff-tick)+tock+1;
        }
        else
        {
            elapsed = tock - tick;
        }
    }
}


void delay_us(unsigned int us)
{
    unsigned int delay=0, tick=0, tock=0, elapsed=0;
    delay=(SYSCLK/2000000)*us;
    tick=_CP0_GET_COUNT();
    
    while(elapsed<delay)
    {
        tock=_CP0_GET_COUNT();
        if(tock<=tick)
        {
            elapsed=(0xffffffff-tick)+tock+1;
        }
        else
        {
            elapsed = tock - tick;
        }
    }
}
