#ifndef _WDT_H_
#define _WDT_H_

 sfr WDT_CONTR = 0xe1;

void EnableWDT(void);
void NoEnableWDT(void);
void WDTInit(void);
void ClearWDT(void);

#endif