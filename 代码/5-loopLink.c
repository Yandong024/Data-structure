/*
循环单链表
（1）创建循环单链表
（2）插入数据
（3）删除数据
（4）清空数据链表

*/

#include<stdio.h>
#include<stdlib.h>

typedef struct link{
    int data;
    struct link *next;
}link;
//data为存储的数据，next指针为指向下一个结点

//初始化 
link *InitList()
{
  link *head=(link*)malloc(sizeof(link));
  head->next=NULL;
  head->data=0;
  return head;
}

/* （1）创建循环单链表 */ 
void Add(link *s)
{
  link *p=s;
  int n;
  printf("你要输入多少数据：");
  scanf("%d",&n);
  printf("请输入%d个数据：",n);
  for(int i=1;i<=n;i++)
  {
    link *q=(link *)malloc(sizeof(link));
    scanf("%d",&q->data);
    p->next=q;
    p=q;
  }
  p->next=s;
}

/* （2）插入数据 */ 
void Insert(link *s)
{
  int a;
  int flag=0;
  link *q=(link *)malloc(sizeof(link));
  printf("请输入你要插入的数据：");
  scanf("%d",&q->data);
  printf("请输入你要插入哪个数据之后：");
  scanf("%d",&a);
  link *p=s->next;
  while(p!=s)
  {
    if(p->data==a)
    {
      q->next=p->next;
      p->next=q;
      flag=1;
      break;
    }
    p=p->next;
  }
  if(flag==1)
  printf("插入成功！\n");
  else
  printf("插入失败！\n"); 
} 

/* （3）删除数据 */ 
void Delete(link *s)
{
  int a;
  printf("请输入你要删除的数据：");
  scanf("%d",&a);
  link *p=s->next;
  int flag=0;
  link *q=s;
  while(p!=s)
  {
    if(p->data==a)
    {
      q->next=p->next;
      free(p);
      flag=1;
      break;
    }
    p=p->next;
    q=q->next;  
  }  
}

/* （4）清空链表 */ 
void Empty(link *s)
{
  link *p=s->next;
  link *q=p->next;
  while(p!=s)
  {
    free(p);
    p=q;
    q=q->next;
  }
  free(s);
}


/* 显示循环链表 */ 
void Display(link *s)
{
  link *v=s->next;
  while(v!=s)
  {
    printf("%d->",v->data);
    v=v->next;
  }
  printf("%d\n",v->data); //循环到表头
}

int main()
{
link * head=InitList();
// （1）循环单链表创建 
Add(head);
printf("创建了一个循环单链表！\n");
Display(head);
// （2）插入数据 
printf("插入一个数据！\n");
Insert(head);
printf("显示循环链表！\n");
Display(head);
// （3）删除数据 
Delete(head);
printf("删除数据后的循环链表！\n");
Display(head);
// （4）清空数据链表 
Empty(head);
printf("该链表已清空！");
return 0;
}