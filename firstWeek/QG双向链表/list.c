#include"list.h"
static TNode * AddNode(TNode * p,int data)
{
	//��������
	if(0 == p->data) //�����һ���ڵ� 
	{
		p->data = data;
		return p;
	}
	TNode * nt=(TNode *)malloc(sizeof(TNode)); //����һ���½ڵ�
	if(NULL == nt)
	{
		printf("����ڴ�����ร��أ�\n");
		return p; 
	}
	nt->data = data;
	nt->next =  p->next; //��ʱ�ڵ��nextָ��λ�ڵ����һ�ڵ� 
	nt->pre = p; //��ʱ�ڵ��preָ��λ�ڵ� 
	nt->next->pre = nt;
	nt->pre->next = nt;
	if(p->pre == p) //����ѭ�� 
	{
		p->pre = nt;
	}
	return p;
}

static void Tprint(ptr_TNode head)
{
	//�ж������Ƿ�Ϊ�� 
	if(NULL == head)
	{
		printf("����û������Ү�r(�s���t)�q\n");
		return;
	}
	int i=0;
	//������� 
	TNode * p = head;
	puts("���ݣ�");
	do{		
		printf("%-5d: %p %p %p\n",p->data,p->pre,p,p->next);
		p=p->next; 
		i++;
	}while(p!=head && i<15);
	return ;	
}

ptr_TNode create(int *arr, int n) //��ʼ�� 
{
	//�ж������Ƿ�Ϊ�� 
	if(NULL == arr || 0==n)
	{
		printf("�����ǿյ�\n");
		return NULL; 
	}
	//��������
	int i;
	TNode * p = (TNode *)malloc(sizeof(TNode)); //����ͷ�ڵ�ռ䡣 
	if(NULL == p)
	{
		printf("�����ڴ�ʧ��\n");
		return NULL; 
	}
	//��ʼ�� 
	p->data = 0; 
	p->next = p; //ָ���Լ� 
	p->pre = p;  //ָ���Լ� 
	//��ȡ���鲢��ӽڵ� 
	for(i=0; i<n ;i++)
	{
		p = AddNode(p,arr[i]);
	}
	return p;
}

Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
	printf("���%d����%d��λ�á�\n",node->data,index+1);
	//�ж�ָ���Ƿ�Ϊ�� 
	if(NULL == *head)
	{
		printf("�����ǿյģ����ȴ�������\n");
		return ERROR;
	}
	//��������
	int i=1;
	TNode * nt = *head;
	while(i<index && NULL != nt)//��λ������ӽڵ����һ�ڵ� 
	{
		nt=nt->next;
		i++;
	}
	if(nt == NULL)	//��������index�Ƿ񳬳���Χ 
	{
		printf("����������\n");
		return ERROR;
	}
	else if(index==0)	//���ͷ�ڵ��Ƿ����Ҫ�� 
	{
		node->next = nt;
		node->pre = nt->pre;
		nt->pre->next = node;
		nt->pre = node;
		*head = node;
		return SUCCESS;
	}
	node->next = nt->next;
	node->pre = nt;
	nt->next = node;
	if(nt == nt->pre) //���node�ǵڶ�������ӵĽڵ㣬 ��ͷ�ڵ����һ���ڵ�ָ��node����ѭ�� 
		nt->pre = node;
	return SUCCESS;
} 

Status delete_T(ptr_TNode *head, int index, int *data)
{
	printf("ɾ����%d���ڵ�.\n",index+1);
	//�ж�ָ���Ƿ�Ϊ�� 
	if(NULL == *head)
	{
		printf("head == NULL\n");
		return ERROR;
	}
	//��������
	int i=1;
	TNode * nt = *head;
	while(i<index && NULL != nt)//��λ����ɾ���ڵ����һ�ڵ� 
	{
		nt=nt->next;
		i++;
	}
	if(nt == NULL)	//��������index�Ƿ񳬳���Χ 
	{
		printf("����������\n");
		return ERROR;
	}
	else if(index==0)	//���ͷ�ڵ��Ƿ����Ҫ�� 
	{
		*data = nt->data;
		if(nt = nt->pre) //����ֻʣ��һ��Ԫ��ʱ 
		{
			free(nt);
			*head = NULL;
			return SUCCESS;
		}
		nt->pre->next=nt->next;
		nt->next->pre = nt->pre;
		free(nt);
		return SUCCESS;
	}
		nt = nt->next;//ָ���ɾ���ڵ�
		*data = nt->data; 
		nt->pre->next = nt->next;  
		nt->next->pre = nt->pre; 
		free(nt);
		nt = NULL;
		return SUCCESS; 
}

void print(ptr_TNode head)
{
	//�ж�ָ���Ƿ�Ϊ�� 
	if(NULL == head)
	{
		printf("head == NULL\n");
		return ;
	}
	int i=0;
	TNode* p = head;
	puts("���ݣ�");
	do{
		printf("%-4d",p->data);
		p=p->next; 
		i++;
//		puts("###################");
		if(i%5==0)
			putchar('\n');
	}while(p!=head);
	if(i%5!=0)
		putchar('\n');
	return ;
}

int main()
{
	TNode * p;
	int a[]={5,8,7,9,6,3,2,4,5};
	TNode temp;
	temp.data = 16;
	int data = 32;
	
	p=create(a,9);// ��������
	print(p);
	insert_T(&p,&temp,0); //����ڵ㵽��һ��λ�� 
	print(p);
	delete_T(&p,5,&data); //ɾ����0���ڵ� 
	print(p);
	printf("data = %d\n",data);
	getchar();
}
