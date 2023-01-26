#include<reg51.h>

sbit red=P1^0; // Connecting red LED to P1.0
sbit yellow=P1^1; // Connecting yellow LED to P1.1
sbit green=P1^2; // Connecting green LED to P1.2

void delay(unsigned int time) // delay function
{
    unsigned int i, j;
    for(i=0; i<time; i++)
        for(j=0; j<1275; j++);
}

void ssd_delay(int y)
{
  unsigned char seg[10]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
	unsigned char x;
	unsigned int i;
	P2=0x00;
		for(x=y; x<=y; x--){
			P2=seg[x];
			delay(150);
		}
}

void main()
{
	red=green=yellow=0;
    while(1)
    {
        red = 1; 
        ssd_delay(9); 
        red = 0; 
        yellow = 1; 
        ssd_delay(4); 
        yellow = 0; 
        green = 1; 
        ssd_delay(9); 
        green = 0; 
    }
}
