#include "reg52.h"

//ʱ��Ϊ12M 1��ʱ��Ϊ0.0833us
//12��ʱ�� Ϊһ����е���� ��Լ1us  for һ��Ϊ2������ 
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
		
		delay(100); //��Լ0.8S
		
		Led = Led <<1 ;
		if(Led == 0)
		{
			Led = 0x01;
		}
		
	}
}