#include"List.h"
static Node * AddNode(Node * p,int data); //用于添加节点 
static void Tprint(ptr_Node head); //用于调试的输出函数 
//内部辅助函数 
static void Tprint(ptr_Node head)
{
	//判断链表是否为空 
	if(NULL == head)
	{
		printf("链表没有内容耶╮(╯▽╰)╭\n");
		return;
	}
		
	//输出内容 
	Node * p = head;
	puts("内容：");
	while(NULL != p)
	{
		printf("%p %d %.6p\n",p,p->data,p->next);
		p=p->next; 
	}
	return ;	
}
static Node * AddNode(Node * p,int data)
{
	if(p->data == 0)//检测 链表是否为空 
	{
		p->data=data; //复制到第一个节点中
		return p; 
	} 
	Node * head = p; //让head保持指向头节点 
	while(NULL != p->next) //定位到最后的节点 
	{
		p = p->next;
	}
	Node * nt = (Node *)malloc(sizeof(Node)); //Node temp; 申请空间；
	if(NULL == nt) //判断是否获取到内存 
	{
		printf("获取内存失败。\n");
		return head;
	} 		
	nt->data = data;
	nt->next = NULL;	//初始化新节点的next指针 
	p->next=nt; 		//把新节点加入链表中；
	return head; 		 //返回新节点的地址 
}

ptr_Node create(int *arr, int n)
{
	//判断数组是否为空 
	if(NULL == arr)
	{
		printf("数组是空的\n");
		return ERROR; 
	}
	//创建链表并初始化 
	int i;
	Node * p = (Node *)malloc(sizeof(Node)); //申请头节点空间。 
	if(NULL == p)
	{
		printf("申请内存失败\n");
		return ERROR; 
	}
	//初始化 
	p->data = 0; 
	p->next = NULL;
	
	//读取数组并添加节点 
	for(i=0; i<n ;i++)
	{
		p = AddNode(p,arr[i]);
	}
	return p;
}
void print(ptr_Node head)
{
	//判断链表是否为空 
	if(NULL == head)
	{
		printf("链表没有内容耶╮(╯▽╰)╭\n");
		return;
	}
		
	//输出内容 
	Node * p = head;
	int i;
	puts("内容：");
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
	//判断指针
	if(NULL == head) 
	{
		printf("指针是空的\n");
		return ; 
	}
	//清空列表
	Node * nt = head;
	Node * next;
	while(next != NULL) 
	{
//		Tprint(head); //调试输出函数 
		nt = next;
		next = next->next;
		free(nt);
		nt = NULL;
	 } 
	 return ;
}
Status insert(ptr_Node *head, ptr_Node node, int index)
{
	//判断指针
	if(NULL == *head) 
	{
		printf("指针是空的\n");
		return ERROR; 
	}
	int i=1;
	Node * nt = *head;
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
		*head = node;
		return SUCCESS;
	}
	node->next = nt->next;
	nt->next = node;
	return SUCCESS;
}
Status delete(ptr_Node *head, int index, int *data)
{
	//判断指针
	if(NULL == *head) 
	{
		printf("指针是空的\n");
		return ERROR; 
	}
	int i=1;
	Node * nt = *head;
	Node * nt2 ;
	while(i<index && NULL != nt)//定位到待删除节点的上一节点 
	{
		nt=nt->next;
		i++;
	}
	if(nt == NULL)//检测输入的index是否超出范围 
	{
		printf("不存在这个元素！\n");
		return ERROR;
	}
	else if(0==index)//检测头节点是否符合要求 
	{
		nt2 = nt->next;
		nt->data = nt2->data;
		nt->next = nt2->next;
		free(nt2);
		return SUCCESS;
	}
	nt2=nt->next;	//nt2指向待删除节点 
	nt->next=nt2->next;	//nt->next指向待删除节点的下一个节点 
	*data = nt2->data; //把待删除节点数据发送给data 
	free(nt2); //释放！ 
	nt2 = NULL; //指空！ 
	return SUCCESS;
}
ptr_Node search(ptr_Node head, int data)
{
	//判断指针
	if(NULL == head) 
	{
		printf("指针是空的\n");
		return ERROR; 
	}
	if(head->data == data)
	{
		return 0;
	}
	while(head->next != NULL)
	{
		if(head->next->data == data) //判断当前节点的下一节点数据是否符合要求 
			return head;
		else
			head = head->next; 
	}
	return -1;
}
Status edit(ptr_Node head, int index, int *data)
{
	//判断指针
	if(NULL == head) 
	{
		printf("指针是空的\n");
		return ERROR; 
	}
	int i=1;
	int t;
	Node * nt = head;
	Node * nt2 ;
	while(i<=index && NULL != nt)//定位到待修改节点 
	{
		nt=nt->next;
		i++;
	}
	if(nt == NULL)//检测输入的index是否超出范围 
	{
		printf("不存在这个元素！\n");
		return ERROR;
	}
	else if(0==index)//检测头节点是否符合要求 
	{
		t=*data;
		*data = head->data;
		head->data = t;
		return SUCCESS;
	}
	t = *data; //交换数据 
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
	
	p=create(a,9);// 创造链表
	print(p);
	insert(&p,&temp,0); //插入节点到第一个位置 
	print(p);
	delete(&p,5,&data); //删除第六个节点 
	print(p);
	printf("data = %d\n",data);
	edit(p,3,&data); //替换第4节点内容 
	print(p);
	printf("data = %d\n",data);
	getchar(); 
	return 0;
}
