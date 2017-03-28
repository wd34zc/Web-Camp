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
	printf("l->top=%p\n",l->top);
	l->count++;
	return OK;
}

//��ջ
//n�������յ�����ջ 
Status pop(LinkStack * l,ElemType * e)
{
	if(isEmpty(l))
	{
		printf("ջ�ǿյģ���Ҫ�ҵ�ʲô��\n");
		*e = -1;
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
		printf("ջ�ǿյ�Ү~");
		return ERROR; 
	}
		
}

//��Ϊ��ջ 
Status clear(LinkStack* l)
{
	if(l->count == 0)
	{
		printf("�������ǿյģ���Ҫ�����ɶ��\n"); 
	}
	StackNode * n = NULL;
	while(l->count != 0)
	{
		n = l->top;
		l->top = l->top->next;
		free(n);
		l->count--;
	}
	printf("��ճɹ���\n");
	return OK;
}

//����ջ 
Status destroyStack(LinkStack* l)
{
	if(l == NULL)
	{
		printf("ջ�����Ͳ����ڡ�\n"); 
		return ERROR;
	}
	if(!clear(l))
		return ERROR;
	free(l);
	printf("ջ������\n");
	return OK;
}

//��ȡջ�ĳ��� 
Status stackLength(LinkStack* l ,int * n)
{
	if(l->count == 0)
	{
		printf("ջ�ǿյ�Ӵ��\n"); 
	}
	*n=l->count;
	return OK;
}

void show(LinkStack* l )
{
	StackNode * head = l->top;
	while(l->top != NULL)
	{
		printf("%d %p %p\n",l->top->data,l->top,l->top->next);
		l->top = l->top->next;
	}
	l->top = head;
} 

//int main()
//{
//	LinkStack * ls = initStack();
//	ElemType e;
//	e=2;
//	push(ls,&e);
//	e=3;
//	push(ls,&e);
//	e=4;
//	push(ls,&e);
//	return 0;
// } 


