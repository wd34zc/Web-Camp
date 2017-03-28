#include"Stack.h"

int main()
{
	LinkStack * ls;
	ls = initStack();
	
	char g;
	printf("1.ѹջ\n2.��ջ\n3.��ȡջ������\n4.��ȡջ����\n");
	printf("5.���ջ\n6.����ջ\n");
	printf("������ѡ��(ֱ�ӻس��˳�)��");
	g=getchar();
	ElemType e=0;
	int length;
	while(g!=0 && g!='\n'){
		fflush(stdin);
//		printf("���ԣ�%s\n",ps->student->name);
		switch (g){
			case '1':
				printf("�������ѹջ����:");
				scanf("%d",&e);
				fflush(stdin);
				if(push(ls,&e))
					printf("ѹ��ȥ��%d\n",e);
//				show(ls);
				break;
			case '2':
				if(pop(ls,&e))
					printf("��������%d\n",e);
//				show(ls);
				break;
			case '3':
				if(getTop(ls,&e))
					printf("Ŀǰջ����%d\n",e);
//				show(ls);
				break;
			case '4':
				if(stackLength(ls,&length))
					printf("ջ������%d\n",length);
//				show(ls);
				break;
			case '5':
				clear(ls);
//				show(ls);
				break;
			case '6':
				destroyStack(ls);
//				show(ls);
				break;
			default :printf("������ѡ��ǰ��Ӧ�����֣�\n");
		}
		putchar('\n'); 
		printf("1.ѹջ\n2.��ջ\n3.��ȡջ������\n4.��ȡջ����\n");
		printf("5.���ջ\n6.����ջ\n");
		printf("������ѡ��(ֱ�ӻس��˳�)��");
		g=getchar();
	}
	
	return 0;
} 
