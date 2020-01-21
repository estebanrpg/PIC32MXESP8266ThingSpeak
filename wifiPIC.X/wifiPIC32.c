#include "wifiPIC32.h"
void configServerMode( char *password, char *SSID, char *IP, char *puerto){
    delay_ms(1000);
    Uart2Puts("AT\r\n\0");
    delay_ms(1000);  
    Uart2Puts("AT+RST\r\n\0");
    delay_ms(10000);
    Uart2Puts("AT+CWMODE=2\r\n\0");
    delay_ms(300);
    Uart2Puts("AT+CIPSERVER=0\r\n\0");
    delay_ms(300);
    Uart2Puts("AT+CIPMUX=0\r\n\0");
    delay_ms(300);
    Uart2Puts("AT+CIPMODE=0\r\n\0");
    delay_ms(300);
    Uart2Puts("AT+CWSAP=\"");
    Uart2Puts(SSID);
    Uart2Puts("\",\"");
    Uart2Puts(password);
    Uart2Puts("\",5,3\r\n\0");
    delay_ms(15000);
    Uart2Puts("AT+CWSAP=\"");
    Uart2Puts(IP);
    Uart2Puts("\"\r\n\0");
    delay_ms(15000);
    Uart2Puts("AT+CIPMUX=1\r\n\0");
    delay_ms(300);
    Uart2Puts("AT+CIPSERVER=1,");
    Uart2Puts(puerto);
    Uart2Puts("\r\n\0");
    delay_ms(300);
    Uart2Puts("AT+CIPSTO=0\r\n\0");
}


void tcpWrite(char *dato,char ID,char *getStr){
    int lonStr = strlen(dato);
    strcpy(getStr,dato);
    char strAux[20]="";
    Uart2Puts("AT+CIPSEND=");
    Uart2WriteData(ID);
    sprintf(strAux,",%d\r\n\0",lonStr);
}