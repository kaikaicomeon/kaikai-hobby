#include "include.h"

//���Ź� ��һ������ ��û�в��Թ����Ź���
/****************************
��ʱ��0  250us �ж�
������д�ĳ���Ŀ�ܽṹ
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
