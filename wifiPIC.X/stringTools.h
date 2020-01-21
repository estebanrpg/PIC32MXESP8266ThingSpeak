#ifndef SERIAL_H
#define	SERIAL_H
#include "SystemPIC32MX.h"

void ST_cutStr(char* cutString, char* string, unsigned int ic, unsigned int fc);
void ST_strCop(volatile unsigned char *str1,volatile unsigned char *str2);

#endif

