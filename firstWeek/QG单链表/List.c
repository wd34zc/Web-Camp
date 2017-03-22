#include"List.h"
static Node * AddNode(Node * p,int data); //������ӽڵ� 
static void Tprint(ptr_Node head); //���ڵ��Ե�������� 
//�ڲ��������� 
static void Tprint(ptr_Node head)
{
	//�ж������Ƿ�Ϊ�� 
	if(NULL == head)
	{
		printf("����û������Ү�r(�s���t)�q\n");
		return;
	}
		
	//������� 
	Node * p = head;
	puts("���ݣ�");
	while(NULL != p)
	{
		printf("%p %d %.6p\n",p,p->data,p->next);
		p=p->next; 
	}
	return ;	
}
static Node * AddNode(Node * p,int data)
{
	if(p->data == 0)//��� �����Ƿ�Ϊ�� 
	{
		p->data=data; //���Ƶ���һ���ڵ���
		return p; 
	} 
	Node * head = p; //��head����ָ��ͷ�ڵ� 
	while(NULL != p->next) //��λ�����Ľڵ� 
	{
		p = p->next;
	}
	Node * nt = (Node *)malloc(sizeof(Node)); //Node temp; ����ռ䣻
	if(NULL == nt) //�ж��Ƿ��ȡ���ڴ� 
	{
		printf("��ȡ�ڴ�ʧ�ܡ�\n");
		return head;
	} 		
	nt->data = data;
	nt->next = NULL;	//��ʼ���½ڵ��nextָ�� 
	p->next=nt; 		//���½ڵ���������У�
	return head; 		 //�����½ڵ�ĵ�ַ 
}

ptr_Node create(int *arr, int n)
{
	//�ж������Ƿ�Ϊ�� 
	if(NULL == arr)
	{
		printf("�����ǿյ�\n");
		return ERROR; 
	}
	//����������ʼ�� 
	int i;
	Node * p = (Node *)malloc(sizeof(Node)); //����ͷ�ڵ�ռ䡣 
	if(NULL == p)
	{
		printf("�����ڴ�ʧ��\n");
		return ERROR; 
	}
	//��ʼ�� 
	p->data = 0; 
	p->next = NULL;
	
	//��ȡ���鲢��ӽڵ� 
	for(i=0; i<n ;i++)
	{
		p = AddNode(p,arr[i]);
	}
	return p;
}
void print(ptr_Node head)
{
	//�ж������Ƿ�Ϊ�� 
	if(NULL == head)
	{
		printf("����û������Ү�r(�s���t)�q\n");
		return;
	}
		
	//������� 
	Node * p = head;
	int i;
	puts("���ݣ�");
	while(NULL != p)
	{
		printf("%-4d",p->data);
		p=p->next; 
		i++;
		if(i%5==0)
			putchar('\n');
	}
	if(i%5!=0)
		putchar('\n');
	return ;	
}
void destroy(ptr_Node head)
{
	//�ж�ָ��
	if(NULL == head) 
	{
		printf("ָ���ǿյ�\n");
		return ; 
	}
	//����б�
	Node * nt = head;
	Node * next;
	while(next != NULL) 
	{
//		Tprint(head); //����������� 
		nt = next;
		next = next->next;
		free(nt);
		nt = NULL;
	 } 
	 return ;
}
Status insert(ptr_Node *head, ptr_Node node, int index)
{
	//�ж�ָ��
	if(NULL == *head) 
	{
		printf("ָ���ǿյ�\n");
		return ERROR; 
	}
	int i=1;
	Node * nt = *head;
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
		*head = node;
		return SUCCESS;
	}
	node->next = nt->next;
	nt->next = node;
	return SUCCESS;
}
Status delete(ptr_Node *head, int index, int *data)
{
	//�ж�ָ��
	if(NULL == *head) 
	{
		printf("ָ���ǿյ�\n");
		return ERROR; 
	}
	int i=1;
	Node * nt = *head;
	Node * nt2 ;
	while(i<index && NULL != nt)//��λ����ɾ���ڵ����һ�ڵ� 
	{
		nt=nt->next;
		i++;
	}
	if(nt == NULL)//��������index�Ƿ񳬳���Χ 
	{
		printf("���������Ԫ�أ�\n");
		return ERROR;
	}
	else if(0==index)//���ͷ�ڵ��Ƿ����Ҫ�� 
	{
		nt2 = nt->next;
		nt->data = nt2->data;
		nt->next = nt2->next;
		free(nt2);
		return SUCCESS;
	}
	nt2=nt->next;	//nt2ָ���ɾ���ڵ� 
	nt->next=nt2->next;	//nt->nextָ���ɾ���ڵ����һ���ڵ� 
	*data = nt2->data; //�Ѵ�ɾ���ڵ����ݷ��͸�data 
	free(nt2); //�ͷţ� 
	nt2 = NULL; //ָ�գ� 
	return SUCCESS;
}
ptr_Node search(ptr_Node head, int data)
{
	//�ж�ָ��
	if(NULL == head) 
	{
		printf("ָ���ǿյ�\n");
		return ERROR; 
	}
	if(head->data == data)
	{
		return 0;
	}
	while(head->next != NULL)
	{
		if(head->next->data == data) //�жϵ�ǰ�ڵ����һ�ڵ������Ƿ����Ҫ�� 
			return head;
		else
			head = head->next; 
	}
	return -1;
}
Status edit(ptr_Node head, int index, int *data)
{
	//�ж�ָ��
	if(NULL == head) 
	{
		printf("ָ���ǿյ�\n");
		return ERROR; 
	}
	int i=1;
	int t;
	Node * nt = head;
	Node * nt2 ;
	while(i<=index && NULL != nt)//��λ�����޸Ľڵ� 
	{
		nt=nt->next;
		i++;
	}
	if(nt == NULL)//��������index�Ƿ񳬳���Χ 
	{
		printf("���������Ԫ�أ�\n");
		return ERROR;
	}
	else if(0==index)//���ͷ�ڵ��Ƿ����Ҫ�� 
	{
		t=*data;
		*data = head->data;
		head->data = t;
		return SUCCESS;
	}
	t = *data; //�������� 
	*data = nt->data;
	nt->data = t;
	return SUCCESS;
}
Status sort(ptr_Node *head)
{
	return SUCCESS;
} 
int main()
{
	Node * p;
	int a[]={5,8,7,9,6,3,2,4,5};
	Node temp;
	temp.data = 16;
	int data = 32;
	
	p=create(a,9);// ��������
	print(p);
	insert(&p,&temp,0); //����ڵ㵽��һ��λ�� 
	print(p);
	delete(&p,5,&data); //ɾ���������ڵ� 
	print(p);
	printf("data = %d\n",data);
	edit(p,3,&data); //�滻��4�ڵ����� 
	print(p);
	printf("data = %d\n",data);
	getchar(); 
	return 0;
}
