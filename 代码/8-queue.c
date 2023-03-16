/*
队列
(1) 队列的结构体定义（链式结构）
(2) 队列初始化
（3）队列的销毁
（4）队列的添加
（5）队列是否为空
（6）队列的删除
（7）队头的数据
（8）队尾的数据
（9）队列的大小
*/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int QDataType;

/*(1) 队列的结构体定义（链式结构）*/
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QueueNode;
 
typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
}Queue;

/*(2) 队列初始化*/
void QueueInit(Queue* pq)//初始化
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

/*（3）队列的销毁*/
void QueueDestroy(Queue* pq)//销毁
{
	assert(pq);
	QueueNode* cur = pq->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

/*（4）队列的添加 */
void QueuePush(Queue* pq, QDataType x)//添加   尾插
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

/*（5）队列是否为空 */
bool QueueEmpty(Queue* pq)//判断队列是否为空
{
	assert(pq);
	return pq->head == NULL;
}

/*（6）队列的删除 */
void QueuePop(Queue* pq)//删除  头删
{
	assert(pq);
	assert(!(QueueEmpty(pq)));
	QueueNode* next = pq->head->next;
	free(pq->head);
	pq->head = next;
	if (pq->head == NULL) 
		// 这个情况是需要特殊来判断一下的，就是删除以后链表为空了，
		// 这时要记得把尾指针(tail)也置空一下
	{
		pq->tail = NULL;
	}
}


/*（7）队头的数据 */
QDataType QueueFront(Queue* pq)//取队头的数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

/*（8）队尾的数据 */
QDataType QueueBack(Queue* pq)//取队尾的数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

/*（9）队列的大小 */
int QueueSize(Queue* pq)//队列的大小
{
	QueueNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		cur = cur->next;
		size++;
	}
	return size;
}


int main(int argc, char const *argv[])
{
  /* code */
  //队列初始化
  Queue * myQueue;
  QueueNode *qn;
  qn->data = -1;
  qn->next = NULL;
  myQueue->head = qn;
  myQueue->tail = qn;
  return 0;
}
