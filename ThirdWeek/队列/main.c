#include"queue.h"
//#define TEST

#ifndef TEST
	#define NOTTEST
#endif 
void print(Node * n);

#ifdef TEST
int main()
{
	void(*foo)();
	Queue q,*p = &q;
	InitQueue(p);
	Node n;	
	
	
	int a=10;
	EnQueue(p,&a,'i');
	
	GetHeadQueue(p,&n);
	print(&n);

	float b=20; 
	EnQueue(p,&b,'f');
	
	char c[]="you are a pig";
	EnQueue(p,c,'s');
	
//	printf("主函数测试插入函数：%d\n",*(int *)(p->front->data));
//	printf("主函数测试插入函数：%f\n",*(float *)(p->front->next->data));
//	printf("主函数测试插入函数：%s\n",(p->front->next->next->data));

	TraverseQueue(p,&print);

	DeQueue(p,&n);
	printf("%d\n",*(int*)n.data);
//	print(&n);
	DeQueue(p,&n);
	print(&n);
	DeQueue(p,&n);
	print(&n);

	
//	foo = *PRINT;
//	TraverseQueue(p,foo);

//	ClearQueue(p);
	
	TraverseQueue(p,&print);

	return 0;
}
#endif

#ifdef NOTTEST
int main()
{
	void(*foo)();
	Queue q,*p = &q;
	InitQueue(p);
	Node n;	
	foo = print;
	
	char g;
	printf("1.入队\n2.出队\n3.获取队头数据\n");
	printf("4.查看队列\n5.清空队列\n6.退出系统\n");
	printf("请输入选项：");
	g=getchar();
	while(1){
		fflush(stdin);
		switch (g){
			case '1':
				printf("请选择即将存储的数据类型:\n");
				printf("i.整型\nf.单精度浮点型\nc.字符型\ns.字符串型\n");
				g=getchar();
				fflush(stdin);
				printf("请输入数据："); 
				switch (g)
				{
					case 'i':
						{
							int i;
							scanf("%d",&i);
							if(EnQueue(p,&i,g))
								printf("数据入队成功！\n");
						}
						break;
					case 'f':
						{
							float f;
							scanf("%f",&f);
							if(EnQueue(p,&f,g))
								printf("数据入队成功！\n");
						}
						break;
					case 'c':
						{
							char ch;
							scanf("%c",&ch);
							if(EnQueue(p,&ch,g))
								printf("数据入队成功！\n");
						}
						break;
					case 's':
						{
							char str[30];
							gets(str);
							fflush(stdin);
							str[30] = 0;  //防止溢出
							if(EnQueue(p,str,g))
								printf("数据入队成功！\n");
						}
						break;
					default :
						printf("没有对应数据类型。\n");
				}
				fflush(stdin);
				break;
			case '2':
				if(DeQueue(p,&n))
				{
					print(&n);
					free(n.data);
				}
				break;
			case '3':
				if(GetHeadQueue(p,&n))
					print(&n);
				break;
			case '4':
				TraverseQueue(p,foo);
				break;
			case '5':
				ClearQueue(p);
				printf("清空完毕。\n");
				break;
			case '6':
				printf("你确定要退出吗？\n");
				printf("输入Y确认:");
				g=getchar();
				fflush(stdin);
				if(g=='y'||g=='Y')
				{
					printf("正在清空队列...\n");
					ClearQueue(p);
					printf("清空队列完毕。\n");
					getchar();
					return 0;
				}
			default :printf("请输入选项前对应的数字！\n");
		}
		putchar('\n'); 
		printf("1.入队\n2.出队\n3.获取队头数据\n");
		printf("4.查看队列\n5.清空队列\n6.退出系统\n");
		g=getchar();
	}
}
#endif

void print(Node * n)
{
//	printf("调用函数：%d\n",*(int *)n->data);
//	printf("\t%p\n",n->data);
//	printf("\t%p %p\n",n,n->next);
	switch  (n->type)
		{
			case 'i':
				printf("整型：%d\n",*(int*)n->data);
				break;
			case 'f':
				printf("单精度浮点型：%f\n",*(float*)n->data);
				break;
			case 'c':
				printf("字符型：%c\n",*(char*)n->data);
				break;
			case 's':
				printf("字符串型：%s\n",n->data);
				break;
		}
}


