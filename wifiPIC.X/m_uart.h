/* 
 * File:   m_uart.h
 * Author: Juancho
 *
 * Created on 20 de mayo de 2018, 15:35
 */

#ifndef M_UART_H
#define	M_UART_H
#include "systemPIC32MX.h"

#define Uart1_Rx_RPA2 0
#define Uart1_Rx_RPA4 2
#define Uart1_Rx_RPB13 3
#define Uart1_Rx_RPB2 4

#define Uart1_Tx_RPA0 (unsigned int)(&RPA0R)
#define Uart1_Tx_RPB3 (unsigned int)(&RPB3R()
#define Uart1_Tx_RPB4 (unsigned int)(&RPB4R)
#define Uart1_Tx_RPB15 (unsigned int)(&RPB15R)
#define Uart1_Tx_RPB7 (unsigned int)(&RPB7R)

#define Uart1En(enable) U1MODEbits.ON=enable

#define Uart1RxEn(enable) U1STAbits.URXEN=enable

#define Uart1TxEn(enable) U1STAbits.UTXEN=enable

#define Uart1WriteData(data) while(U2STAbits.UTXBF); U2TXREG=data

#define Uart1ReadData() U1RXREG

void Uart1_Config(unsigned int RxPin, unsigned int TxPin, unsigned int baudrate);

void Uart1Puts(unsigned char *str);


//==============================================================================================
#define Uart2_Rx_RPA1 0
#define Uart2_Rx_RPB5 1
#define Uart2_Rx_RPB1 2
#define Uart2_Rx_RPB11 3
#define Uart2_Rx_RPB8 4

#define Uart2_Tx_RPA3 (unsigned int)(&RPA3R)
#define Uart2_Tx_RPB14 (unsigned int)(&RPB14R)
#define Uart2_Tx_RPB0 (unsigned int)(&RPB0R)
#define Uart2_Tx_RPB10 (unsigned int)(&RPB10R)
#define Uart2_Tx_RPB9 (unsigned int)(&RPB9R)

#define Uart2En(enable) U2MODEbits.ON=enable

#define Uart2RxEn(enable) U2STAbits.URXEN=enable

#define Uart2TxEn(enable) U2STAbits.UTXEN=enable

#define Uart2WriteData(data) while(U2STAbits.UTXBF); U2TXREG=data

#define Uart2ReadData() U2RXREG

void Uart2_Config(unsigned int RxPin, unsigned int TxPin, unsigned int baudrate);

void Uart2Puts(unsigned char *str);
#endif	/* M_UART_H */

