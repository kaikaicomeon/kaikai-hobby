#include "include.h"

void Timer0Init(u8 us)
{
 TMOD = 0X02; //8λ�Զ���װ
 TL0 = 0X00 ;//��ʱ����ʼֵ
 TH0 = (255 - us);//��ʱ���Զ���װֵ
 TR0 = 1;//��ʱ��0��ʼ����
 ET0 = 1;//������ʱ��0�ж�
 
}


void TimeBause() interrupt 1
{
 //250us
 static Time = 0;
 ++Time;
 if(Time >=3)  //1ms
 {
   Time = 0;
   Task_Inquiry();
 }

}