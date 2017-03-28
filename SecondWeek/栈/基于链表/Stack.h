#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 
typedef enum Status{
	ERROR,OK
}Status;

typedef int ElemType;
typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;	
}StackNode ,*LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;	  //栈顶指针
	int	count;  //栈中元素个数
}LinkStack;

//初始化一个栈 
LinkStack* initStack(void);

//判断栈是否为空 
Status isEmpty(LinkStack* l);

//弹栈
//n用来接收弹出的栈 
Status pop(LinkStack * l,ElemType * e);

//压栈 
//n是即将压入的栈 
Status push(LinkStack * l ,ElemType * e);

//获取栈顶数据 
Status getTop(LinkStack * l ,ElemType * e);

//置为空栈 
Status clear(LinkStack* l);

//销毁栈 
Status destroyStack(LinkStack* l);

//获取栈的长度 
Status stackLength(LinkStack* l ,int * n);

void show(LinkStack* l ); 


