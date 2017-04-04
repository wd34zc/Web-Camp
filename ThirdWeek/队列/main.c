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
	
//	printf("���������Բ��뺯����%d\n",*(int *)(p->front->data));
//	printf("���������Բ��뺯����%f\n",*(float *)(p->front->next->data));
//	printf("���������Բ��뺯����%s\n",(p->front->next->next->data));

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
	printf("1.���\n2.����\n3.��ȡ��ͷ����\n");
	printf("4.�鿴����\n5.��ն���\n6.�˳�ϵͳ\n");
	printf("������ѡ�");
	g=getchar();
	while(1){
		fflush(stdin);
		switch (g){
			case '1':
				printf("��ѡ�񼴽��洢����������:\n");
				printf("i.����\nf.�����ȸ�����\nc.�ַ���\ns.�ַ�����\n");
				g=getchar();
				fflush(stdin);
				printf("���������ݣ�"); 
				switch (g)
				{
					case 'i':
						{
							int i;
							scanf("%d",&i);
							if(EnQueue(p,&i,g))
								printf("������ӳɹ���\n");
						}
						break;
					case 'f':
						{
							float f;
							scanf("%f",&f);
							if(EnQueue(p,&f,g))
								printf("������ӳɹ���\n");
						}
						break;
					case 'c':
						{
							char ch;
							scanf("%c",&ch);
							if(EnQueue(p,&ch,g))
								printf("������ӳɹ���\n");
						}
						break;
					case 's':
						{
							char str[30];
							gets(str);
							fflush(stdin);
							str[30] = 0;  //��ֹ���
							if(EnQueue(p,str,g))
								printf("������ӳɹ���\n");
						}
						break;
					default :
						printf("û�ж�Ӧ�������͡�\n");
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
				printf("�����ϡ�\n");
				break;
			case '6':
				printf("��ȷ��Ҫ�˳���\n");
				printf("����Yȷ��:");
				g=getchar();
				fflush(stdin);
				if(g=='y'||g=='Y')
				{
					printf("������ն���...\n");
					ClearQueue(p);
					printf("��ն�����ϡ�\n");
					getchar();
					return 0;
				}
			default :printf("������ѡ��ǰ��Ӧ�����֣�\n");
		}
		putchar('\n'); 
		printf("1.���\n2.����\n3.��ȡ��ͷ����\n");
		printf("4.�鿴����\n5.��ն���\n6.�˳�ϵͳ\n");
		g=getchar();
	}
}
#endif

void print(Node * n)
{
//	printf("���ú�����%d\n",*(int *)n->data);
//	printf("\t%p\n",n->data);
//	printf("\t%p %p\n",n,n->next);
	switch  (n->type)
		{
			case 'i':
				printf("���ͣ�%d\n",*(int*)n->data);
				break;
			case 'f':
				printf("�����ȸ����ͣ�%f\n",*(float*)n->data);
				break;
			case 'c':
				printf("�ַ��ͣ�%c\n",*(char*)n->data);
				break;
			case 's':
				printf("�ַ����ͣ�%s\n",n->data);
				break;
		}
}


