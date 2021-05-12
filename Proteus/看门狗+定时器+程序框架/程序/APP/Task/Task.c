#include "include.h"

#define TASK_NUM  2

typedef struct
{
 void (*Function)(void); //����ָ��
 u16 inter_cycle;        //����
 u16 inter_start;        //��ʼʱ��
 u16 inter_now;          // ��ǰʱ��
 u8 run_flag;           //���к�����־
} Task_Strtuct;

void Task_1(void)
{
  P0 = 0x00;
}
void Task_2(void)
{
  P0 = 0x00;
}


static Task_Strtuct Task_Strtuct1[TASK_NUM] =
{
 { Task_1, 50, 30,0, 0 }, 
 { Task_2, 50, 20,0, 0 } 
};

void Task_Process(void)
{
  u8 i = 0;
  for(i = 0; i < TASK_NUM; i ++)
  {
   if(Task_Strtuct1[i].run_flag)
   {
    Task_Strtuct1[i].run_flag = 0;
    Task_Strtuct1[i].Function();
   }
  
  }

}


void Task_Inquiry(void)  
{
 u8 i = 0;

    for(i = 0; i < TASK_NUM; i++)  
    {
//       if(schedule_task[i].inter_now)  
//     {
     ++Task_Strtuct1[i].inter_now;
     if(Task_Strtuct1[i].inter_now == Task_Strtuct1[i].inter_start)   
     {   
      Task_Strtuct1[i].run_flag  = 1;
     }
     if(Task_Strtuct1[i].inter_now >= Task_Strtuct1[i].inter_cycle)
     {
      Task_Strtuct1[i].inter_now = 0;
     }
//     }
    }    
}


