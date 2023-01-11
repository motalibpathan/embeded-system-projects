#include<reg51.h>
sbit rs=P3^0;
sbit rw=P3^1;
sbit en=P3^2;

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void delay();

void main(){
    P2=0x00;
    while(1)
    {
        lcdcmd(0x38);delay();
        lcdcmd(0x80);delay();
				lcdcmd(0x0C);delay();
        lcddata('M');delay();
        lcddata('O');delay();
        lcddata('T');delay(); 
        lcddata('A');delay();
        lcddata('L');delay();
        lcddata('I');delay();
        lcddata('B');delay();
				lcddata(' ');delay();
        lcddata('P');delay();
				lcddata('A');delay();
        lcddata('T');delay(); 
        lcddata('H');delay();
        lcddata('A');delay();
        lcddata('N');delay();
        lcdcmd(0xC0);delay();
        lcddata('2');delay();
        lcddata('0');delay();
        lcddata('1');delay(); 
        lcddata('9');delay();
        lcddata('0');delay();
        lcddata('0');delay();
        lcddata('0');delay();
        lcddata('0');delay();
        lcddata('1');delay(); 
        lcddata('0');delay();
        lcddata('0');delay();
        lcddata('8');delay();
        lcddata('1');delay();
				delay();delay();
				
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