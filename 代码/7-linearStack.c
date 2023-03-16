/*
堆栈
(1) 堆栈的初始化
（2）入栈
（3）判断栈是否为空 
（4）删除栈顶数据(出栈)
（5）取出栈顶的数据
（6）获取栈中有效元素的个数
(7)栈的销毁
*/

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
 
typedef struct Stack
{
	int *a;  //整型指针，指向数组的首地址
	int top; //栈顶
	int capacity;//容量
}ST;

/*（1）初始化栈 */
void StackInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

/*（2）入栈 */
void StackPush(ST* ps, int x)
{
	// assert(ps);
	if (ps->top == ps->capacity)
	{
		// 三目运算符，ps->capacity == 0成立，赋值为4，否则为扩容2倍
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//从堆上分配内存的,当扩大一块内存空间时, realloc直接从堆上现存的数据后面的那些字节中获得附加的字节
		int* tmp = (int*)realloc(ps->a,sizeof(int)*newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;  //数组与指针（补充内容）
	ps->top++;
}

/*（3）判断栈是否为空 */
bool StackEmpty(ST* ps)//判断栈是否为空
{
	assert(ps);
	return ps->top == 0;
 
 
 
	/*if (ps->top == 0)
		return true;
	else
		return false;*/
 
}

/*（4）删除栈顶数据(出栈) */

 
void StackPop(ST* ps)//删除，出栈
{
	assert(ps);
	assert(!StackEmpty(ps));//判断栈是否为空
	ps->top--;
}


/*（5）取出栈顶的数据 */

int StackTop(ST* ps)//栈顶的数据，获取栈顶数据
{
	assert(ps);
	assert(!StackEmpty(ps));//判断栈是否为空
	return ps->a[ps->top-1];
}

/*（6）获取栈中有效元素的个数 */
int StackSize(ST* ps)//栈内数据的多少，获取栈中有效元素的个数
{
	assert(ps);
	return ps->top;
}

/*（7）销毁栈 */
void StackDestroy(ST* ps)//销毁栈
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}


int main(int argc, char const *argv[])
{
	/* code */
	// 插入数据
	int num = 10;
	
	ST* my_stack = (ST*)malloc(sizeof(ST));
	StackInit(my_stack);
	printf("Stack 完成初始化！\n");
	StackPush(my_stack, num); // 入栈（10）
	int num_2 = 100;
	StackPush(my_stack, num_2);
	printf("top-1:%d\n",my_stack->top);
	printf("stack num1:%d, num2:%d \n", my_stack->a[0], my_stack->a[1]);
	int top_num = StackTop(my_stack);
	printf("top_num:%d\n", top_num);
	printf("top-2:%d\n", my_stack->top);
	return 0;
}
