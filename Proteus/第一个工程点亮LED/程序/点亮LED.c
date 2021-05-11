#include "reg52.h"

//时钟为12M 1个时钟为0.0833us
//12个时钟 为一个机械周期 大约1us  for 一般为2个周期 
void delay(unsigned int j)
{
	unsigned int i; 
	for(;j > 0 ;j--)
	{
		for(i = 1000; i > 0; i--);		
	}
}

void main()
{
	char Led = 0x01;
	for(;;)
	{

		P0 = Led;
		
		delay(100); //大约0.8S
		
		Led = Led <<1 ;
		if(Led == 0)
		{
			Led = 0x01;
		}
		
	}
}