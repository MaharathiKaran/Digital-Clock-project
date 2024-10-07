#include<reg51.h>
void delay()
{
	unsigned int x;
	for(x=0;x<14;x++)
	{
		TMOD=0x01;
		TH0=0;
		TL0=0;
		TR0=1;
		while(TF0==0);
		TF0=0;
		TR0=0;
	}
}
int hextodec(int y)
{
	int z0,z1;
	z0=y%10;
	z1=y/10;
	y=z0+z1*16;
	return y;
}
void main()
{
	unsigned int a,b,c;
	for(c=0;c<24;c++)
	{
		P0=hextodec(c);
		for(b=0;b<60;b++)
	 {
		 P2=hextodec(b);
		 for(a=0;a<60;a++)
	  {
		  P3=hextodec(a);
		  delay();
	  }
		delay();
   }
		delay();
	}
}