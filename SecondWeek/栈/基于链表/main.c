#include"Stack.h"

int main()
{
	LinkStack * ls;
	ls = initStack();
	
	char g;
	printf("1.压栈\n2.弹栈\n3.获取栈顶数据\n4.获取栈长度\n");
	printf("5.清空栈\n6.销毁栈\n");
	printf("请输入选项(直接回车退出)：");
	g=getchar();
	ElemType e=0;
	int length;
	while(g!=0 && g!='\n'){
		fflush(stdin);
//		printf("调试：%s\n",ps->student->name);
		switch (g){
			case '1':
				printf("请输入待压栈数据:");
				scanf("%d",&e);
				fflush(stdin);
				if(push(ls,&e))
					printf("压进去了%d\n",e);
//				show(ls);
				break;
			case '2':
				if(pop(ls,&e))
					printf("弹出来了%d\n",e);
//				show(ls);
				break;
			case '3':
				if(getTop(ls,&e))
					printf("目前栈顶是%d\n",e);
//				show(ls);
				break;
			case '4':
				if(stackLength(ls,&length))
					printf("栈长度是%d\n",length);
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
			default :printf("请输入选项前对应的数字！\n");
		}
		putchar('\n'); 
		printf("1.压栈\n2.弹栈\n3.获取栈顶数据\n4.获取栈长度\n");
		printf("5.清空栈\n6.销毁栈\n");
		printf("请输入选项(直接回车退出)：");
		g=getchar();
	}
	
	return 0;
} 
