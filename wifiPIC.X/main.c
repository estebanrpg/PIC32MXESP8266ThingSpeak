/*
 * File:   main.c
 * Author: Esteban Prieto
 * Created on 24 de septiembre de 2019, 03:50 PM
 * Ejemplo envio de datos thingSpeak
 */
#include "systemPIC32MX.h"
#include "m_uart.h"
#include "M_ADC.h"
#include "M_Timers.h"
#include "delay.h"
#include <stdio.h>
#include <string.h>

char getStr[100]="";
char apiKey[20]= "XX8QPEKB4MLYZ91W";
char nombre[20]= "WIFI-UPTC";
char contra[20]= "";

void __ISR(_UART2_VECTOR,IPL7SOFT) Uart2_Rx(void){
    
    unsigned int tmp;
    
    if(IFS1bits.U2RXIF==1){
        tmp=Uart2ReadData();
        //si recibe el caracter > entonces envia los datos al servidor
        if(tmp == '>'){
            Uart2Puts(getStr);
        }
        IFS1bits.U2RXIF=0;
    }
}
void thingSpeakWrite(double data){
    // Establece una conexion tcp con el servidor de ThingSpeak en el puerto 80
    Uart2Puts("AT+CIPSTART=\"TCP\",\"184.106.153.149\",80\r\n\0");
    delay_ms(200);
    char strAux[100]="";
    /*en la cadena auxiliar se ponen los datos que se van a subir,
     * si por ejemplo se requiere subir la informacion de otro sensor
     * se pondria de la siguiente manera:
     * sprintf(strAux,"&field1=%0.2f&field2=%0.2f\r\n\r\n\0",data1,data2);
     */ 
    sprintf(strAux,"&field1=%0.2f\r\n\r\n\0",data);
    strcpy(getStr,"GET /update?api_key=");//a la cadena que se va a enviar le asigna lo que esta entre comillas dobles
    strcat(getStr,apiKey);//luego se le concatena el apiKey
    strcat(getStr,strAux);//por ultimo se concatena los datos que se van a enviar
    int lonStr=strlen(getStr);//se obtiene la longitud de la cadena
    sprintf(strAux,"AT+CIPSEND=%d\r\n\0",lonStr);
    Uart2Puts(strAux);//se le indica al modulo la cantidad de caracteres que se van a enviar
}
void configClientMode(char *password,char *SSID){
    delay_ms(1);
    Uart2Puts("AT\r\n\0");//Prueba de funcionamiento del modulo ESP
    delay_ms(1);
    Uart2Puts("AT+RST\r\n\0");//Resetea el modulo
    delay_ms(260);
    Uart2Puts("ATE0\r\n\0");//Quita el eco del ESP, se cambia el 0 por el 1 para depurar
    delay_ms(6);
    Uart2Puts("AT+CWMODE=1\r\n\0");//Configura el modulo en modo estación
    delay_ms(6);
    
    Uart2Puts("AT+CWJAP=\"");//se configura la red wi-fi de la locacion con internet
    Uart2Puts(SSID);
    Uart2Puts("\",\"");
    Uart2Puts(password);
    Uart2Puts("\"\r\n\0");
    delay_ms(500);
}



int main(void) {
    ANSELA=0X00000000;//inicia los puertos analogicos en cero
    ANSELB=0X00000000;
    
    TRISBbits.TRISB10 = 0;//configura los pines para la trasmicion y recepbion serial
    TRISBbits.TRISB11 = 1;
    
    Uart2_Config(Uart2_Rx_RPB11,Uart2_Tx_RPB10,115200);
    Uart2TxEn(1);
    Uart2RxEn(1);//configura y habilata a uart a 115200 baudios
    Uart2En(1); 
    
    __builtin_disable_interrupts();//se configuran las interrupciones
    
    INTCONbits.MVEC=1;
    IPC9bits.U2IP=7;
    IPC9bits.U2IS=3;    
    IFS1bits.U2RXIF=0;
    IEC1bits.U2RXIE=1;
    
    __builtin_enable_interrupts();
    
    ADC_config(CH_AN5,1);//se reconfigura el ansel selecciona el canal 5 
    ADC_Channel(5);//
    ADC_enable(1);
    
    TMR23_config(TMR23_PRESCALA_256,2343749);//15 segundos 
    TMR23_cntrl(1);
    
    // ThingSpeak recive los datos cada 15 segundos
    
    configClientMode(contra,nombre);
 
    unsigned int ADC_datos[16];
    double vIn = 0.0;     
    
    while(1){
        if (TMR23_Test() == 1){//si pasaron 15 segundos
            ADC_start();
            delay_ms(1);
            if(ADC_test()){
                ADC_read(ADC_datos,1);//lee lo que hay en el adc
                vIn= (double)ADC_datos[0]*3300/1023;//hace la conversion
                thingSpeakWrite(vIn/1000);// se envia a esta funcion los datos para ser procesados
            }
        }
        
    }
}
