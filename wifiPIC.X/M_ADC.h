/* 
 * File:   M_ADC.h
 * Author: Juancho
 *
 * Created on 14 de mayo de 2018, 10:34
 */

#ifndef M_ADC_H
#define	M_ADC_H

#include "systemPIC32MX.h"


#define CH_AN0 0x00000001
#define CH_AN1 0x00000002
#define CH_AN2 0x00000004
#define CH_AN3 0x00000008
#define CH_AN4 0x00000010
#define CH_AN5 0x00000020
#define CH_AN9 0x00020000
#define CH_AN10 0x00010000
#define CH_AN11 0x00008000

//#define ADC_inputs(config) ANSELA|=config; TRISA|=(config&0x00000003); ANSELB|=(config>>2); TRISB|=(config>>2)

#define SCAN_SELECT_EN 0

//#define 


void ADC_config(unsigned int config, unsigned char numenumero_muestras);

void ADC_Channel(unsigned char canal);

void ADC_start(void);

void ADC_enable(unsigned char cntrl);

void ADC_read(unsigned int *vector, unsigned char size);

unsigned char ADC_test(void);

#endif	/* M_ADC_H */

