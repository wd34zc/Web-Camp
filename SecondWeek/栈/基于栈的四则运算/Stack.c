#include"Stack.h" 

//��ʼ��һ��ջ 
LinkStack* initStack(void)
{
	LinkStack * l;
	l=(LinkStack *)malloc(sizeof(LinkStack));
	l->top = NULL;
	l->count = 0;
	return l;
}

//�ж�ջ�Ƿ�Ϊ�� 
Status isEmpty(LinkStack* l)
{
	if(l->count == 0)
		return OK;
	else 
		return ERROR;
}

//ѹջ 
//n�Ǽ���ѹ���ջ 
Status push(LinkStack * l ,ElemType * e)
{
	StackNode * n = (StackNode*)malloc(sizeof(StackNode));
	if(n == NULL)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		return ERROR;
	}
	n->data = *e;
	n->next = l->top;
	l->top = n;
	l->count++;
	return OK;
}

//��ջ
//n�������յ�����ջ 
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

//��ȡջ������ 
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

//��Ϊ��ջ 
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

//����ջ 
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

//��ȡջ�ĳ��� 
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
		printf("ջ�����ݣ�");
	while(l->top != NULL)
	{
		printf("%c ",l->top->data);
		l->top = l->top->next;
	}
		putchar('\n') ;
	l->top = n;
} 
