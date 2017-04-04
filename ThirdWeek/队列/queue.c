#include"queue.h"
//#define TEST

 //�ڲ���������
 
 /**
 *  @name        : static Status IsPointNull(void * a)
 *	@description : ���ָ���Ƿ�Ϊ��ָ�� 
 *	@param		 : ����ָ��Q
 *	@return		 : ״̬
 *  @notice      : None
 */
 
 //���к���ʵ�� 
 static Status IsPointNull(void * a)
 {
 	if(a == NULL)
 		return TRUE;
 	else
 		return FALSE;
  } 
void InitQueue(Queue *Q)
{
	//���г�Ա��Ϊ�� 
	Q->count=0;
	Q->data_size=0;
	Q->front=NULL;
	Q->rear=NULL;
}

Status IsFullQueue(const Queue *Q)
{
	if(Q->count > MAXQUEUE)
		return TRUE;
	else
		return FALSE;
}

Status IsEmptyQueue(const Queue *Q)
{
	if(Q->front == NULL)
		return TRUE;
	else
		return FALSE;
}

Status GetHeadQueue(Queue *Q, Node *n)
{
	if(IsEmptyQueue(Q))
	{
		printf("�����ǿյġ�\n");
		return FALSE;
	}
	else
	{
		*n=*Q->front; 
		return TRUE;
	}
	
}

int LengthQueue(Queue *Q)
{
	return Q->count;
}

Status EnQueue(Queue *Q, void *data,const char type)
{
	if(IsFullQueue(Q))
	{
		printf("�����Ѿ�����\n");
		return FALSE;
	 } 
	
	size_t size = sizeof(Node);//���ڵ��ڴ� 
	Node* n = (Node *)malloc(size);						
	if(IsPointNull(n))	//����Ƿ����ڴ�
		return FALSE;
	
	void *t;
	switch  (type)
	{
		case 'i':
#ifdef TEST
			printf("���뺯����ȡ�� �������ݣ�%f\n",*(int *)data);
#endif
			t=(int *)malloc(sizeof(int));
			if(IsPointNull(t))	//����Ƿ����ڴ�
				return FALSE;
				
			*(int *)t = *(int*)(data);
			Q->data_size+=sizeof(int);	//���������Ӷ�Ӧ���������ʹ�С 
			break;
		case 'f':
#ifdef TEST
			printf("���뺯����ȡ�� ���������ݣ�%f\n",*(float*)data);
#endif
			t =(float *)malloc(sizeof(float));
			if(IsPointNull(t))	//����Ƿ����ڴ�
				return FALSE;			
			
			*(float *)t = *(float*)(data);
			Q->data_size+=sizeof(float);
			break;
		case 'c':
#ifdef TEST
			printf("���뺯����ȡ�� �ַ������ݣ�%f\n",*(char*)data);
#endif
			t =(char *)malloc(sizeof(char));
			if(IsPointNull(t))	//����Ƿ����ڴ�
				return FALSE;	
				
			*(char *)t = *(char*)(data);
			Q->data_size+=sizeof(char);
			break;
		case 's':
#ifdef TEST
			printf("���뺯����ȡ�� �ַ�����%s\n",data);
#endif
			t =(char *)malloc(sizeof(data));
			if(IsPointNull(t))	//����Ƿ����ڴ�
				return FALSE;	
				
			strcpy(t,data);
			Q->data_size+=sizeof(data);
			break;
		default:
			printf("��֧�ִ洢�����͡�\n");
			return FALSE;
	}								
									
	if(IsEmptyQueue(Q))
	{
		Q->front = n; //�������Ϊ�գ�����ͷ��ָ�������β����ͬ 
	}
	else
	{
		Q->rear->next=n;	//����Ϊ�գ����һ���ڵ��nextָ�� ָ�� n�� 
	}
		
	//�����ڵ����ݸ�ֵ 
	n->data = t;
	n->next = NULL;
	n->type=type;
	
	//���¶�����ֵ 
	Q->rear=n; 
	Q->count++;
	Q->data_size+=size;//�������ڴ����� 
	
#ifdef TEST
	printf("����ڵ����ݣ�");
	switch  (n->type)
		{
			case 'i':
				printf("%d\n",*(int*)n->data);
				break;
			case 'f':
				printf("%f\n",*(float*)n->data);
				break;
			case 'c':
				printf("%c\n",*(char*)n->data);
				break;
			case 's':
				printf("%s\n",n->data);
				break;
		}
#endif
	
	return TRUE;
}

Status DeQueue(Queue *Q, Node * n)
{
	if(IsEmptyQueue(Q))
	{
		printf("����Ϊ�ա�\n");
		return FALSE;
	}
	
	Node *t = Q->front; //�����ͷ��ڴ����ʱ�ڵ� 
	
	*n = *t;
	n->next = NULL; //�Ѵ���ȥ�Ľڵ�� nextָ����Ϊ�� 
	
#ifdef TEST
	{
		printf("�����������ԣ�\n");
		switch  (n->type)
		{
			case 'i':
				printf("\tn�����ݣ�%d\n\t���ͣ�%c\n",*(int*)n->data,n->type);
				break;
			case 'f':
				printf("\tn�����ݣ�%f\n\t���ͣ�%c\n",*(float*)n->data,n->type);
				break;
			case 'c':
				printf("\tn�����ݣ�%c\n\t���ͣ�%c\n",*(char*)n->data,n->type);
				break;
			case 's':
				printf("\tn�����ݣ�%s\n\t���ͣ�%c\n",n->data,n->type);
				break;
		}
	}
#endif	
	
	switch  (t->type)	//�������ȥ��Ӧ���������ʹ�С 
		{
			case 'i':
				Q->data_size-=sizeof(int);
				break;
			case 'f':
				Q->data_size-=sizeof(float);
				break;
			case 'c':
				Q->data_size-=sizeof(char);
				break;
			case 's':
				Q->data_size-=sizeof(n->data);
				break;
		}
		
	Q->count--;
	Q->data_size-=sizeof(Node);
	Q->front=Q->front->next;
	
	free(t);
	
	if(IsEmptyQueue(Q))  //������пգ���rearָ����Ϊ�� 
		Q->rear = NULL;
		
		
	#ifdef TEST
	{
		printf("������������2��\n");
		switch  (n->type)
		{
			case 'i':
				printf("\tn�����ݣ�%d\n\t���ͣ�%c\n",*(int*)n->data,n->type);
				break;
			case 'f':
				printf("\tn�����ݣ�%f\n\t���ͣ�%c\n",*(float*)n->data,n->type);
				break;
			case 'c':
				printf("\tn�����ݣ�%c\n\t���ͣ�%c\n",*(char*)n->data,n->type);
				break;
			case 's':
				printf("\tn�����ݣ�%s\n\t���ͣ�%c\n",n->data,n->type);
				break;
		}
	}
#endif	
	return TRUE;
} 

void ClearQueue(Queue *Q)
{
	Node n;
	while(!IsEmptyQueue(Q))
	{
		DeQueue(Q,&n);	
	}
 } 

Status TraverseQueue(const Queue *Q, void (*foo)(void *q))
{
	if(IsEmptyQueue(Q))
	{
		printf("�����ǿյġ�\n");
		return FALSE; 
	}
	
	Node* t = Q->front;
	printf("���в��������ȣ�%d �������С%u\n",Q->count,Q->data_size);
#ifdef TEST
	printf("\t%p %p\n",Q->front,Q->rear);
#endif	
	while(t != NULL)
	{
		foo(t);
		t=t->next;
	}
	putchar('\n'); 
	return TRUE;
 } 
 

 
