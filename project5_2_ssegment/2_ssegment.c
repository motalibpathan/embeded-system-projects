#include<reg51.h>

//sbit red=P1^0;
//sbit yellow=P1^1;
//sbit green=P1^2;

void delay(unsigned int time) // delay function
{
    unsigned int i, j;
    for(i=0; i<time; i++)
        for(j=0; j<1275; j++);
}

void ssd_delay()
{
  unsigned char seg[10]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};
	unsigned char x;
	unsigned char y;
	unsigned char z;
	
	P1=0x00;
	P2=0x00;
	P3=0x00;
		for(x=0; x<10; x++){
			P1=seg[x];
			for(y=0; y<10; y++){
				P2=seg[y];
				for(z=0; z<10; z++){
					P3=seg[z];
					delay(100);
				}	
			}
			P3=seg[0];
		}
}

void main()
{
	//red=green=yellow=0;
    while(1)
    {
        //red = 1; 
        ssd_delay(); 
        //red = 0; 
        //yellow = 1; 
        ssd_delay(); 
        //yellow = 0; 
        //green = 1; 
        ssd_delay(); 
        //green = 0; 
    }
}
