#define MAXSIZE 100

typedef int ElemType;  //假设顺序表中的数据元素是整型

typedef struct{
  ElemType elem[MAXSIZE];
  int last;
}SeqList;

