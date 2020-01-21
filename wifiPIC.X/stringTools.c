#include "SystemPIC32MX.h"
#include "stringTools.h"

void ST_cutStr(char *cutString,char *string,unsigned int ic,unsigned int fc){
    unsigned int i = 0;
    do{
       cutString[i]=string[i+ic];
       i++;
    }
    while((i+ic)!=fc);
}
void ST_strCop(volatile unsigned char *str1,volatile unsigned char *str2){
    unsigned char n = 0;
    while(str2[n]!='\0'){
        str1[n]=str2[n];
        n++;
    }
}