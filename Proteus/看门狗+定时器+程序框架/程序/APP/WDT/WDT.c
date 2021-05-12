#include "include.h"

//Ê¹ÄÜWDT
void EnableWDT(void)
{
	WDT_CONTR |= 0x20;
}

//void NoEnableWDT(void)
//{
//		WDT_CONTR &= 0xDF;
//}

void ClearWDT(void)
{
	WDT_CONTR |= 0x01;
}

void WDTInit(void)
{
	WDT_CONTR = 0x18;//65.5ms
	EnableWDT();
}

