#include"list.h"
static TNode * AddNode(TNode * p,int data)
{
	//插入内容
	if(0 == p->data) //插入第一个节点 
	{
		p->data = data;
		return p;
	}
	TNode * nt=(TNode *)malloc(sizeof(TNode)); //申明一个新节点
	if(NULL == nt)
	{
		printf("你的内存满了喔￣へ￣\n");
		return p; 
	}
	nt->data = data;
	nt->next =  p->next; //临时节点的next指向定位节点的下一节点 
	nt->pre = p; //临时节点的pre指向定位节点 
	nt->next->pre = nt;
	nt->pre->next = nt;
	if(p->pre == p) //构造循环 
	{
		p->pre = nt;
	}
	return p;
}

static void Tprint(ptr_TNode head)
{
	//判断链表是否为空 
	if(NULL == head)
	{
		printf("链表没有内容耶╮(╯▽╰)╭\n");
		return;
	}
	int i=0;
	//输出内容 
	TNode * p = head;
	puts("内容：");
	do{		
		printf("%-5d: %p %p %p\n",p->data,p->pre,p,p->next);
		p=p->next; 
		i++;
	}while(p!=head && i<15);
	return ;	
}

ptr_TNode create(int *arr, int n) //初始化 
{
	//判断数组是否为空 
	if(NULL == arr || 0==n)
	{
		printf("数组是空的\n");
		return NULL; 
	}
	//创建链表
	int i;
	TNode * p = (TNode *)malloc(sizeof(TNode)); //申请头节点空间。 
	if(NULL == p)
	{
		printf("申请内存失败\n");
		return NULL; 
	}
	//初始化 
	p->data = 0; 
	p->next = p; //指向自己 
	p->pre = p;  //指向自己 
	//读取数组并添加节点 
	for(i=0; i<n ;i++)
	{
		p = AddNode(p,arr[i]);
	}
	return p;
}

Status insert_T(ptr_TNode *head, ptr_TNode node, int index)
{
	printf("添加%d到第%d个位置。\n",node->data,index+1);
	//判断指针是否为空 
	if(NULL == *head)
	{
		printf("链表是空的，请先创建链表\n");
		return ERROR;
	}
	//插入内容
	int i=1;
	TNode * nt = *head;
	while(i<index && NULL != nt)//定位到待添加节点的上一节点 
	{
		nt=nt->next;
		i++;
	}
	if(nt == NULL)	//检测输入的index是否超出范围 
	{
		printf("链表不够长！\n");
		return ERROR;
	}
	else if(index==0)	//检测头节点是否符合要求 
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
	if(nt == nt->pre) //如果node是第二个被添加的节点， 把头节点的上一个节点指向node构成循环 
		nt->pre = node;
	return SUCCESS;
} 

Status delete_T(ptr_TNode *head, int index, int *data)
{
	printf("删除第%d个节点.\n",index+1);
	//判断指针是否为空 
	if(NULL == *head)
	{
		printf("head == NULL\n");
		return ERROR;
	}
	//插入内容
	int i=1;
	TNode * nt = *head;
	while(i<index && NULL != nt)//定位到待删除节点的上一节点 
	{
		nt=nt->next;
		i++;
	}
	if(nt == NULL)	//检测输入的index是否超出范围 
	{
		printf("链表不够长！\n");
		return ERROR;
	}
	else if(index==0)	//检测头节点是否符合要求 
	{
		*data = nt->data;
		if(nt = nt->pre) //链表只剩下一个元素时 
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
		nt = nt->next;//指向待删除节点
		*data = nt->data; 
		nt->pre->next = nt->next;  
		nt->next->pre = nt->pre; 
		free(nt);
		nt = NULL;
		return SUCCESS; 
}

void print(ptr_TNode head)
{
	//判断指针是否为空 
	if(NULL == head)
	{
		printf("head == NULL\n");
		return ;
	}
	int i=0;
	TNode* p = head;
	puts("内容：");
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
	
	p=create(a,9);// 创造链表
	print(p);
	insert_T(&p,&temp,0); //插入节点到第一个位置 
	print(p);
	delete_T(&p,5,&data); //删除第0个节点 
	print(p);
	printf("data = %d\n",data);
	getchar();
}
