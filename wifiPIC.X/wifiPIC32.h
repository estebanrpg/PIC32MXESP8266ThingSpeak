/* ************************************************************************** */
/** libreria para el uso del ESP8266 con el pic32mx v0.0

  @Institution
    UPTC
 
  @Author 
    Esteban Prieto

  @File wifiPIC32
    wifiPIC32.h

  @Summary
    La libreria wifiPIC32 esta hecha para facilitar el uso del ESP8266

  @Description
    En esta primera version se configura el ESP8266 para ser usado como
    servidor
 */
/* ************************************************************************** */

#ifndef WIFIPIC32_H
#define	WIFIPIC32_H
#include "systemPIC32MX.h"
#include "m_uart.h"
#include "delay.h"
#include <stdio.h>
#include <string.h>

void configServerMode(char *password,char *SSID,char *IP,char *puerto);
void tcpWrite(char *dato,char ID,char *getStr);

#endif	/* WIFIPIC32_H */
