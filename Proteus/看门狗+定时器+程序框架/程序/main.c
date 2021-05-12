#include "include.h"

//看门狗 不一定有用 （没有测试过看门狗）
/****************************
定时器0  250us 中断
这是我写的程序的框架结构
****************************/
void main()
{
	EA = 0;
	Timer0Init(250);
	WDTInit();
	EA = 1;
	for(;;)
	{
		Task_Process();
		ClearWDT();
	}

}
