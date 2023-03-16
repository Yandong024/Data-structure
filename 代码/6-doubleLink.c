/*
双向链表
(1) 双向链表的结构体定义
(2) 带表头初始化
(3) 创建一个链表节点
(4) 打印双向链表
(5) 双向链表尾插
(6) 双向链表尾删
(7) 双向链表头插
(8) 双向链表头删 
(9) 双向链表查找 
(10) pos位置之前插入
(11) 删除pos位置
(12) 销毁链表
*/

#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
 
/*（1）双向链表的结构体定义 */
typedef struct ListNode
{
	int data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

/* (2) 带表头初始化 */
LTNode* ListInit()//初始化
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode)); 
	//带有头结点的链表，这里malloc出的是头结点的空间(带头)
	phead->next = phead;
	phead->prev = phead;
	phead->data = 100;
	return phead;
}

/* (3) 创建一个链表节点 */
LTNode* BuyListNode(int x)//malloc一个新的newnode
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = newnode->prev = NULL;
	return newnode;
}

/* (4) 打印双向链表 */
void ListPrint(LTNode* phead)//打印
{
	assert(phead);    // 程序诊断，它可以将程序诊断信息写入标准错误文件
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("%d", cur->data);
	printf("\n");
}

/* (5) 双向链表尾插 */
void ListPushBack(LTNode* phead, int x)
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = BuyListNode(x);//malloc一个新的newnode
 
	//  phead   tail   newnode 
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}


/* (6) 双向链表尾删 */
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next!=phead);
    //这里判断链表是否只剩下头结点了，如果链表只剩下 头结点了，就不能再删了
 
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	tail = NULL;
}

/* (7) 双向链表头插 */
void ListPushFront(LTNode* phead, int x)//头插
{
	assert(phead);
	LTNode* newnode = BuyListNode(x);//malloc一个新的newnode
	LTNode* next = phead->next;
	// phead newnode next   
	newnode->next = next;
	next->prev = newnode;  //注意别忘了是双向的 
	newnode->prev = phead;
	phead->next = newnode;
}

/* (8) 双向链表头删 */
void ListPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	//判断链表是否只剩下头结点了，如果链表只剩下 头结点了，就不能再删了
 
	LTNode* next = phead->next;
	LTNode* nextnext = next->next;
 
	// phead nextnext
	phead->next = nextnext;
	nextnext->prev = phead;
	free(next);
	next = NULL;
}


/* (9) 双向链表查找 */
//在链表中寻找值为x的结点并返回，找不到的话就返回NULL
LTNode* ListFind(LTNode* phead, int x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

/* (10) pos位置之前插入 */
void ListInsert(LTNode* pos, int x)//在pos位置之前插入
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);//malloc一个新的newnode 
	// prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
 
	newnode->next = pos;
	pos->prev = newnode;
}

/* (11) 删除pos位置 */
void ListErase(LTNode* pos)//删除pos位置
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	//prev next  
	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}

/* (12) 销毁链表 */
void ListDestroy(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
	phead = NULL;
}

// 删除双向链表的中间结点
LTNode *delNode(LTNode *pos){
	/*
	(1) DN_pos-1 向后指的指针指向， DN_pos+1
	(2) DN_pos+1 向前指的指针指向？
	(3) free DN
	return 链表，Head 地址
	*/
	//（1）
	LTNode * preNode = pos->prev;
	preNode->next = pos ->next;
	// (2)
	LTNode * nextNode=pos->next;
	nextNode->prev=pos->prev;
	// (3)
	free(pos); 
	return NULL;
}

int main(int argc, char const *argv[])
{
  /* code */

  /*创建一个链表节点，并做尾插*/ 
  // 哨兵节点 表头
  LTNode* l_head = ListInit();
	printf("头结点value：%d\n", l_head->data);
  // 头插
  int x_value = 2;
  ListPushFront(l_head, x_value);
  x_value -= 10;
  ListPushFront(l_head, x_value);
	x_value -= 10;
  ListPushFront(l_head, x_value);
  // 打印
  ListPrint(l_head);

  //TODO:其他方法实现
	// pos -8 find（-8）
	int a = 12;
	LTNode * findNode = ListFind(l_head, a);
	if (findNode)
	{
		/* code */
		printf("找到了这个结点：%d\n", findNode->data);
	}
	else printf("没找到……\n");
	



  return 0;
}
