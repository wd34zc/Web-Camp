#include"queue.h"
//#define TEST

 //内部函数调用
 
 /**
 *  @name        : static Status IsPointNull(void * a)
 *	@description : 检测指针是否为空指针 
 *	@param		 : 队列指针Q
 *	@return		 : 状态
 *  @notice      : None
 */
 
 //队列函数实现 
 static Status IsPointNull(void * a)
 {
 	if(a == NULL)
 		return TRUE;
 	else
 		return FALSE;
  } 
void InitQueue(Queue *Q)
{
	//所有成员置为空 
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
		printf("队列是空的。\n");
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
		printf("队列已经满了\n");
		return FALSE;
	 } 
	
	size_t size = sizeof(Node);//检测节点内存 
	Node* n = (Node *)malloc(size);						
	if(IsPointNull(n))	//检测是否获得内存
		return FALSE;
	
	void *t;
	switch  (type)
	{
		case 'i':
#ifdef TEST
			printf("插入函数获取到 整型数据：%f\n",*(int *)data);
#endif
			t=(int *)malloc(sizeof(int));
			if(IsPointNull(t))	//检测是否获得内存
				return FALSE;
				
			*(int *)t = *(int*)(data);
			Q->data_size+=sizeof(int);	//数据域增加对应的数据类型大小 
			break;
		case 'f':
#ifdef TEST
			printf("插入函数获取到 浮点型数据：%f\n",*(float*)data);
#endif
			t =(float *)malloc(sizeof(float));
			if(IsPointNull(t))	//检测是否获得内存
				return FALSE;			
			
			*(float *)t = *(float*)(data);
			Q->data_size+=sizeof(float);
			break;
		case 'c':
#ifdef TEST
			printf("插入函数获取到 字符型数据：%f\n",*(char*)data);
#endif
			t =(char *)malloc(sizeof(char));
			if(IsPointNull(t))	//检测是否获得内存
				return FALSE;	
				
			*(char *)t = *(char*)(data);
			Q->data_size+=sizeof(char);
			break;
		case 's':
#ifdef TEST
			printf("插入函数获取到 字符串：%s\n",data);
#endif
			t =(char *)malloc(sizeof(data));
			if(IsPointNull(t))	//检测是否获得内存
				return FALSE;	
				
			strcpy(t,data);
			Q->data_size+=sizeof(data);
			break;
		default:
			printf("不支持存储该类型。\n");
			return FALSE;
	}								
									
	if(IsEmptyQueue(Q))
	{
		Q->front = n; //如果队列为空，队列头部指向与队列尾部相同 
	}
	else
	{
		Q->rear->next=n;	//若不为空，最后一个节点的next指针 指向 n； 
	}
		
	//新增节点数据赋值 
	n->data = t;
	n->next = NULL;
	n->type=type;
	
	//更新队列数值 
	Q->rear=n; 
	Q->count++;
	Q->data_size+=size;//数据域内存增加 
	
#ifdef TEST
	printf("新添节点数据：");
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
		printf("队列为空。\n");
		return FALSE;
	}
	
	Node *t = Q->front; //用于释放内存的临时节点 
	
	*n = *t;
	n->next = NULL; //把传出去的节点的 next指针置为空 
	
#ifdef TEST
	{
		printf("弹出函数测试：\n");
		switch  (n->type)
		{
			case 'i':
				printf("\tn的数据：%d\n\t类型：%c\n",*(int*)n->data,n->type);
				break;
			case 'f':
				printf("\tn的数据：%f\n\t类型：%c\n",*(float*)n->data,n->type);
				break;
			case 'c':
				printf("\tn的数据：%c\n\t类型：%c\n",*(char*)n->data,n->type);
				break;
			case 's':
				printf("\tn的数据：%s\n\t类型：%c\n",n->data,n->type);
				break;
		}
	}
#endif	
	
	switch  (t->type)	//数据域减去对应的数据类型大小 
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
	
	if(IsEmptyQueue(Q))  //如果队列空，把rear指针置为空 
		Q->rear = NULL;
		
		
	#ifdef TEST
	{
		printf("弹出函数测试2：\n");
		switch  (n->type)
		{
			case 'i':
				printf("\tn的数据：%d\n\t类型：%c\n",*(int*)n->data,n->type);
				break;
			case 'f':
				printf("\tn的数据：%f\n\t类型：%c\n",*(float*)n->data,n->type);
				break;
			case 'c':
				printf("\tn的数据：%c\n\t类型：%c\n",*(char*)n->data,n->type);
				break;
			case 's':
				printf("\tn的数据：%s\n\t类型：%c\n",n->data,n->type);
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
		printf("队列是空的。\n");
		return FALSE; 
	}
	
	Node* t = Q->front;
	printf("队列参数：长度：%d 数据域大小%u\n",Q->count,Q->data_size);
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
 

 
