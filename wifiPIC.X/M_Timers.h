/* 
 * File:   Timers.h
 * Author: JUANCHO
 *
 * Created on 27 de diciembre de 2017, 02:49 PM
 */

#ifndef M_TIMERS_H
#define	M_TIMERS_H

#include "systemPIC32MX.h"

#define TMR1_EXTERNAL_CLK 	0x00000002
#define TMR1_SYNC_CLK 		0x00000004
#define TMR1_PRESCALA_1		0x00000000
#define TMR1_PRESCALA_8		0x00000010
#define TMR1_PRESCALA_64	0x00000020
#define TMR1_PRESCALA_256	0x00000030
#define TMR1_TGATE			0x00000080
#define TMR1_DIS_ASYNC		0x00001000
#define TMR1_STOP_IDLE		0x00002000

#define TMR2_EXTERNAL_CLK 	0x00000002
#define TMR2_PRESCALA_1		0x00000000
#define TMR2_PRESCALA_2		0x00000010
#define TMR2_PRESCALA_4		0x00000020
#define TMR2_PRESCALA_8		0x00000030
#define TMR2_PRESCALA_16	0x00000040
#define TMR2_PRESCALA_32	0x00000050
#define TMR2_PRESCALA_64	0x00000060
#define TMR2_PRESCALA_256	0x00000070
#define TMR2_TGATE			0x00000080
#define TMR2_STOP_IDLE		0x00002000

#define TMR3_EXTERNAL_CLK 	0x00000002
#define TMR3_PRESCALA_1		0x00000000
#define TMR3_PRESCALA_2		0x00000010
#define TMR3_PRESCALA_4		0x00000020
#define TMR3_PRESCALA_8		0x00000030
#define TMR3_PRESCALA_16	0x00000040
#define TMR3_PRESCALA_32	0x00000050
#define TMR3_PRESCALA_64	0x00000060
#define TMR3_PRESCALA_256	0x00000070
#define TMR3_TGATE			0x00000080
#define TMR3_STOP_IDLE		0x00002000

#define TMR4_EXTERNAL_CLK 	0x00000002
#define TMR4_PRESCALA_1		0x00000000
#define TMR4_PRESCALA_2		0x00000010
#define TMR4_PRESCALA_4		0x00000020
#define TMR4_PRESCALA_8		0x00000030
#define TMR4_PRESCALA_16	0x00000040
#define TMR4_PRESCALA_32	0x00000050
#define TMR4_PRESCALA_64	0x00000060
#define TMR4_PRESCALA_256	0x00000070
#define TMR4_TGATE			0x00000080
#define TMR4_STOP_IDLE		0x00002000

#define TMR5_EXTERNAL_CLK 	0x00000002
#define TMR5_PRESCALA_1		0x00000000
#define TMR5_PRESCALA_2		0x00000010
#define TMR5_PRESCALA_4		0x00000020
#define TMR5_PRESCALA_8		0x00000030
#define TMR5_PRESCALA_16	0x00000040
#define TMR5_PRESCALA_32	0x00000050
#define TMR5_PRESCALA_64	0x00000060
#define TMR5_PRESCALA_256	0x00000070
#define TMR5_TGATE			0x00000080
#define TMR5_STOP_IDLE		0x00002000


#define TMR23_EXTERNAL_CLK 	0x00000002
#define TMR23_PRESCALA_1	0x00000000
#define TMR23_PRESCALA_2	0x00000010
#define TMR23_PRESCALA_4	0x00000020
#define TMR23_PRESCALA_8	0x00000030
#define TMR23_PRESCALA_16	0x00000040
#define TMR23_PRESCALA_32	0x00000050
#define TMR23_PRESCALA_64	0x00000060
#define TMR23_PRESCALA_256	0x00000070
#define TMR23_TGATE			0x00000080


#define TMR45_EXTERNAL_CLK 	0x00000001
#define TMR45_PRESCALA_1	0x00000000
#define TMR45_PRESCALA_2	0x00000010
#define TMR45_PRESCALA_4	0x00000020
#define TMR45_PRESCALA_8	0x00000030
#define TMR45_PRESCALA_16	0x00000040
#define TMR45_PRESCALA_32	0x00000050
#define TMR45_PRESCALA_64	0x00000060
#define TMR45_PRESCALA_256	0x00000070
#define TMR45_TGATE			0x00000080

/* Funciones para la configuracion y manipulacion del Periferico 
 TIMER 1*/

void TMR1_config(unsigned int config, unsigned int periodo);

void TMR1_cntrl(unsigned char on_off);

void TMR1_Periodo(unsigned int periodo);

unsigned int TMR1_read(void);

void TMR1_write(unsigned int valor);

unsigned char TMR1_Test(void);

/* Funciones para la configuracion y manipulacion del Periferico 
 TIMER 2*/
void TMR2_cntrl(unsigned char on_off);

void TMR2_Periodo(unsigned int periodo);

unsigned int TMR2_read(void);

void TMR2_write(unsigned int valor);

unsigned char TMR2_Test(void);


/* Funciones para la configuracion y manipulacion del Periferico 
TIMER 3*/
void TMR3_cntrl(unsigned char on_off);

void TMR3_Periodo(unsigned int periodo);

unsigned int TMR3_read(void);

void TMR3_write(unsigned int valor);

unsigned char TMR3_Test(void);

/* Funciones para la configuracion y manipulacion del Periferico 
TIMER 4*/
void TMR4_cntrl(unsigned char on_off);

void TMR4_Periodo(unsigned int periodo);

unsigned int TMR4_read(void);

void TMR4_write(unsigned int valor);

unsigned char TMR4_Test(void);

/* Funciones para la configuracion y manipulacion del Periferico 
TIMER 5*/
void TMR5_cntrl(unsigned char on_off);

void TMR5_Periodo(unsigned int periodo);

unsigned int TMR5_read(void);

void TMR5_write(unsigned int valor);

unsigned char TMR5_Test(void);

/* Funciones para la configuracion y manipulacion del Periferico 
TIMER 23*/
void TMR23_cntrl(unsigned char on_off);

void TMR23_Periodo(unsigned int periodo);

unsigned int TMR23_read(void);

void TMR23_write(unsigned int valor);

unsigned char TMR23_Test(void);

/* Funciones para la configuracion y manipulacion del Periferico 
TIMER 45*/
void TMR45_cntrl(unsigned char on_off);

void TMR45_Periodo(unsigned int periodo);

unsigned int TMR45_read(void);

void TMR45_write(unsigned int valor);

unsigned char TMR45_Test(void);

#endif	/* M_TIMERS_H */

