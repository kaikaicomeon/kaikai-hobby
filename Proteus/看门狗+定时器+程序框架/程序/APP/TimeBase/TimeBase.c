#include "include.h"

void Timer0Init(u8 us)
{
 TMOD = 0X02; //8位自动重装
 TL0 = 0X00 ;//定时器初始值
 TH0 = (255 - us);//定时器自动重装值
 TR0 = 1;//定时器0开始运行
 ET0 = 1;//启动定时器0中断
 
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