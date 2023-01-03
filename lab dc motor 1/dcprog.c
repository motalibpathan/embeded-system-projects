#include<reg51.h>
sbit motp=P1^0;
sbit motn=P1^1;

sbit motp2=P1^2;
sbit motn2=P1^3;

void main(){
	unsigned int i;
	motn=motp=motp2=motn2=0;

	while(1){
		motp=1;
		motn=0;
		motp2=0;
		motn2=1;
		for(i=0; i<50000; i++){}
		motp=0;
		motn=1;
		motp2=1;
		motn2=0;
		for(i=0; i<50000; i++){}	
	}
}