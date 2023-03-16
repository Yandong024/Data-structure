/*
[程序实例]：将元素非递减的顺序表LA和LB，合并为LC，要求合并后的LC仍为非递减。
*/

#include "stdio.h"  /*包含标准输入输出文件*/
#include "seqlist.c"  /*包含顺序表文件*/

#define OK 1  /* 必要的宏定义*/
#define ERROR 0

/*函数声明*/
void merge(SeqList *LA,  SeqList *LB,  SeqList *LC);

int main()
{
	SeqList L1,L2,L3;   /*定义三个顺序表*/

	InitList(&L1);  /*分别予以初始化*/
	InitList(&L2);
	InitList(&L3);

	printf("\nL1: 按非递减顺序输入若干元素，空格分开，数目<=50，以-100结束\n");
	InputList(&L1);

	printf("\nL2: 按非递减顺序输入若干元素，空格分开，数目<=50，以-100结束\n");
	InputList(&L2);

  // 功能实现
	merge(&L1,&L2,&L3);

	printf("\n顺序表L1和L2合并后的结果为：\n");
	OutputList(L3);

	return 0;
}

/*将元素非递减的顺序表LA和LB，合并为LC。合并后的LC仍为非递减*/
void merge(SeqList *LA,  SeqList *LB,  SeqList *LC)
{
	int i,j,k;
	i=0;j=0;k=0;
  // 比较表A，B元素的大小
	while(i<=LA->last&&j<=LB->last)
		if(LA->elem[i]<=LB->elem[j])
		{
			LC->elem[k]= LA->elem[i];
			i++;
			k++;
		}
		else
		{
			LC->elem[k]=LB->elem[j];
			j++;
			k++;
        }

	while(i<=LA->last)	/*当表LA有剩余元素时，则将表LA余下的元素赋给表LC*/
	{
		LC->elem[k]= LA->elem[i];
		i++;
		k++;
	}
	while(j<=LB->last)  /*当表LB有剩余元素时，则将表LB余下的元素赋给表LC*/
	{
		LC->elem[k]= LB->elem[j];
		j++;
		k++;
	}
	LC->last=LA->last+LB->last+1;
}

