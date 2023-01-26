#include<reg51.h>
#include <stdio.h>
#include <string.h>
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void delay();

int j;
char full_name[] = "MOTALIB PATHAN - 2019000010081";
char department[] = "CSE - SOUTHEAST UNIVERSITY";

void main(){
    P2=0x00;
    while(1)
    {
        lcdcmd(0x38);delay();
        lcdcmd(0x80);delay();
				lcdcmd(0x0C);delay();

        for(j = 0; j < strlen(full_name); j++) {
          lcddata(full_name[j]);delay();
        }

        lcdcmd(0xC0);delay();
        for(j = 0; j < strlen(department); j++) {
          lcddata(department[j]);delay();
        }
				delay();delay();
        //lcdcmd(0x01);delay();
    }
}

void lcdcmd(unsigned char val){
    P2=val;
    rs=0;
    rw=0;
    en=1;
    delay();
    en=0;
}

void lcddata(unsigned char val){
    P2=val;
    rs=1;
    rw=0;
    en=1;
    delay();
    en=0;
}

void delay(){
    unsigned int i;
    for(i=0;i<5000;i++);
}