/*
线性表
（1）定义：元素和长度
（2）创建线性表；
（3）查找；
（4）插入新元素；
（5）删除元素；
*/
#include<stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

/* （1）定义线性表结构体 */
typedef struct List
{
  int Data[MAXSIZE];  // 数组，元素
  int Last;           // 线性表的长度
  float sihui;
}myList;

/* （2）创建线性表 */
myList *MakeEmpty(){
  myList *PtrL;   //结构体指针
  PtrL = (myList *)malloc(sizeof(myList));  //开辟内存空间
  PtrL->Last = -1;   //线性表长度
  PtrL->sihui = 19.0;
  myList Psihui;
  printf("年龄：%f\n", Psihui.sihui);


  return PtrL;       //返回线性表结构体指针
}

/* (3) 查找元素，返回位置索引 */
int Find(int element, myList *PtrL){
  int i=0;
  while (i<=PtrL->Last && PtrL->Data[i]!=element)
  {
    i++;
  }
  if (i>PtrL->Last) return -1;
  else return i;
}

/* (4) 插入一个新元素 */ 
void Insert(int new_x, int i, myList *PtrL){
  //判断是否表满了
  int j;
  if (PtrL->Last == MAXSIZE){
    printf("表满");
  }
  //插入位置是否合法
  if (i<1 || i>PtrL->Last+2)
  {
    printf("位置不合法");
  }
  //插入新元素
  for (j = PtrL->Last; j >= i-1; j--)
  {
    PtrL->Data[j+1] = PtrL->Data[j];
  }
  PtrL->Data[i-1] = new_x;
  PtrL->Last += 1;
}

/*（5）删除元素*/ 
void Delete(int idx, myList *PtrL){
  int j;
  //判断删除是否合法
  // if (idx<1||idx>PtrL->Last+1)
  // {
  //   printf("不存在这个位置%d的元素！", idx);
  return;
  // }
  for ( j = idx; j <= PtrL->Last; j++)
  {
    PtrL->Data[j-1] = PtrL->Data[j]; 
  }
  PtrL->Last -= 1;
  
}



// 打印数据
void printArray(int Array[], int lenght ){
 
  for (int i = 0; i < lenght; i++)
  {
    printf("%d ", Array[i]);
  }

  printf("\n");
}



int main(int argc, char const *argv[])
{
  //创建线性表并赋值
  myList *PtrL1 = MakeEmpty();

  //给线性表赋值
  int list_length = 5;
  for (int i = 0; i < list_length; i++)
  {
    PtrL1->Data[i] = i+10;
  }
  PtrL1->Last = list_length; //改变表的长度

  // 打印数据
  printArray(PtrL1->Data, PtrL1->Last);

  // 查找元素
  int find_num = 100;
  int result = Find(find_num, PtrL1);
  printf("查找结果为: %d \n", result);
  
  // 插入新元素
  printf("插入新元素例子\n");
  int new_el = 100;
  int idx = 3;
  Insert(new_el, idx, PtrL1);
  int lenght = sizeof(PtrL1->Data) / sizeof(int);
  printArray(PtrL1->Data, lenght);

  // 删除元素
  printf("删除元素例子\n");
  Delete(idx, PtrL1);
  lenght = sizeof(PtrL1->Data) / sizeof(int);
  printArray(PtrL1->Data, lenght);



  return 0;
}

