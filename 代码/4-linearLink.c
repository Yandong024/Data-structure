/*
链式结构存储线性表
（1）链表节点的结构体
（2）单链表初始化
（3）求链表的长度
（4）查找--按索引
（5）查找--按值
（6）插入操作
（7）删除操作

*/

#include<stdio.h>
#include<stdlib.h>

/* （1）链表节点的结构体 */ 
typedef struct Link
{
  int value;
  struct Link *Next;
}myLink, *LinkedList;

/*（2）创建一个链表 */ 
LinkedList LinkedListInit() {
    myLink *L;
    L = (myLink *)malloc(sizeof(myLink));   //申请结点空间 
    if(L == NULL) { //判断是否有足够的内存空间 
        printf("申请内存空间失败\n");
    }
    L->Next = NULL;                  //将next设置为NULL,初始长度为0的单链表 
 	return L;
}

//单链表的建立1，头插法建立单链表
 
LinkedList LinkedListCreatH() {
    myLink *L;
    L = (myLink *)malloc(sizeof(myLink));   //申请头结点空间
    L->Next = NULL;   
    L->value = -1;                           //初始化一个空链表
    printf("请填充数值，以ctrl+D结束\n");
    int x;                                  //x为链表数据域中的数据
    while(scanf("%d",&x) != EOF) {
        myLink *p;
        p = (myLink *)malloc(sizeof(myLink));   //申请新的结点 
        p->value = x;                     //结点数据域赋值 
        p->Next = L->Next;                    //将结点插入到表头L-->|2|-->|1|-->NULL 
        L->Next = p; 
    }
    return L; 
} 


// 打印链表
void printLink(LinkedList L){
  while (L)
  {
    printf("%d ", L->value);
    L=L->Next;
  }
  printf("\n");
  
}

// 计算链表长度
int calLength(LinkedList L){
  LinkedList p = L;
  int j = 0;
  while (p)
  {
    p = p->Next;
    j++;
  }
  return j;
}

/*（3）按值查找、按索引位置查找 */ 
myLink *FindIdx(int idx, LinkedList PtrL){
  int i=1;
  while (PtrL != NULL && i<idx)
  {
    PtrL = PtrL->Next;
    i++;
  }
  if (i==idx) return PtrL;
  else return NULL;
  
}



myLink *FindValue(int value, LinkedList PtrL){
  while (PtrL!=NULL && PtrL->value!=value)
  {
    PtrL = PtrL->Next;
  }
  return PtrL;
}

/*（4）插入操作 */ 
myLink *Insert(int insertValue, int idx, myLink *PtrL){
  
  myLink *p, *s;
  //插入位置在表头
  if (idx==1)
  {
    s = (myLink *)malloc(sizeof(myLink));
    s->value = insertValue;
    s->Next = PtrL;
    return s;
  }
  //找到插入位置的节点
  p = FindIdx(idx-1, PtrL);
  //插入：注意插入顺序
  if (p==NULL)
  {
    /* code */
    printf("插入位置不合法");
    return NULL;
  }
  else
  {
    s = (myLink *)malloc(sizeof(myLink));
    s->value = insertValue;
    s->Next = p->Next;
    p->Next = s;
/*
p->Next = s;
s->Next = p->Next;

*/


    return PtrL;
  }
}

/*（5）删除操作 */ 
LinkedList Delete(int i, myLink *PtrL){
  myLink *p, *s;
  if (i==1){
    s=PtrL;
    if(PtrL != NULL) PtrL = PtrL->Next;
    else return NULL;
    free(s);
    return PtrL;
  }
  p = FindIdx(i-1, PtrL);
  if (p==NULL){
    printf("第%d个结点不存在", i-1);
    return NULL;
  }
  else if (p->Next==NULL){
    printf("第%d个结点不存在", i);
    return NULL;
  }
  else{
    s=p->Next;
    p->Next = s->Next;
    free(s);
    return PtrL;
  }
}

int main(int argc, char const *argv[])
{
  // 创建链表
  LinkedList firstL = LinkedListCreatH();
  //
  int l = calLength(firstL);
  printf("线性链表的长度：%d\n", l);
  // 打印Link
  printf("打印链表: \n");
  printLink(firstL);
  // 查找位置
  int pos = 2;
  LinkedList myL_1 = FindIdx(pos, firstL);
  printf("查找位置:%d的数值为:%d\n", pos, myL_1->value);
  // 按值查找
  int value = 10;
  LinkedList myL_2 = FindValue(value, firstL);
  if (myL_2) printf("查找的数值:%d,是否存在:%d\n", value, myL_2->value);
  else printf("不存在要找的数值:%d\n", value);
  // 插入新节点
  int insert_value = 22;
  int insert_pos = 2;
  LinkedList new_L = Insert(insert_value, insert_pos, firstL);
  printf("打印链表（插入新结点）: \n");
  printLink(new_L);
  //删除结点
  int del_pos = 3;
  LinkedList new_del_L = Delete(del_pos, new_L);
  printf("打印链表（删除结点）: \n");
  printLink(new_L);
  return 0;
}
