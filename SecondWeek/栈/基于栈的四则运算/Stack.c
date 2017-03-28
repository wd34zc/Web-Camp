#include"Stack.h" 

//初始化一个栈 
LinkStack* initStack(void)
{
	LinkStack * l;
	l=(LinkStack *)malloc(sizeof(LinkStack));
	l->top = NULL;
	l->count = 0;
	return l;
}

//判断栈是否为空 
Status isEmpty(LinkStack* l)
{
	if(l->count == 0)
		return OK;
	else 
		return ERROR;
}

//压栈 
//n是即将压入的栈 
Status push(LinkStack * l ,ElemType * e)
{
	StackNode * n = (StackNode*)malloc(sizeof(StackNode));
	if(n == NULL)
	{
		printf("申请内存失败！\n");
		return ERROR;
	}
	n->data = *e;
	n->next = l->top;
	l->top = n;
	l->count++;
	return OK;
}

//弹栈
//n用来接收弹出的栈 
Status pop(LinkStack * l,ElemType * e)
{
	if(isEmpty(l))
	{
		*e = 0;
		return ERROR;
	}
	StackNode * tempNode = l->top;
	l->top = l->top->next;
	*e = tempNode->data;
	free(tempNode);
	l->count--;
	return OK;
}

//获取栈顶数据 
Status getTop(LinkStack * l ,ElemType * e)
{
	if(!isEmpty(l))
	{
		*e = l->top->data;
		return OK;
	}
	else
	{
		return ERROR; 
	}
		
}

//置为空栈 
Status clear(LinkStack* l)
{
	if(l->count == 0)
	{
	}
	StackNode * n = NULL;
	while(l->count != 0)
	{
		n = l->top;
		l->top = l->top->next;
		free(n);
		l->count--;
	}
	return OK;
}

//销毁栈 
Status destroyStack(LinkStack* l)
{
	if(l == NULL)
	{
		return ERROR;
	}
	if(!clear(l))
		return ERROR;
	free(l);
	return OK;
}

//获取栈的长度 
Status stackLength(LinkStack* l ,int * n)
{
	if(l->count == 0)
	{
		return ERROR;
	}
	*n=l->count;
	return OK;
}

void show(LinkStack* l )
{
	StackNode * n = l->top; 
		printf("栈的数据：");
	while(l->top != NULL)
	{
		printf("%c ",l->top->data);
		l->top = l->top->next;
	}
		putchar('\n') ;
	l->top = n;
} 
