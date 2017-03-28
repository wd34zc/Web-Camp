/*个位数的四则运算*/
#include"Stack.h"
//把算式转化为计算的模式 
char * transform(char * str);
//计算转化后的式子 
float calculate(char * str);
//用于辅助计算的函数 
float cal(float a,float b,char s);

int main()
{
	//获取式子 
	char *pstr;
	char str[31];
	printf("请转换为英文输入法。\n");
	printf("请输入您的式子：");
	fgets(str,30,stdin);
	fputs(str,stdout);
	
	//计算式子 
	pstr = transform(str);
	puts(str);
	float num;
	num = calculate(str);
	printf("%.2f\n",num);
	getchar();
	return 0;
}

char * transform(char * str)
{
	LinkStack * ls= initStack(); //初始化一个 转化栈 
	ElemType e = 0; //建立一个压栈弹栈的临时变量 

	char ch; //获取符号 
	char str2[30]; //用于存储后缀表达式 
	int i; //变量 i 用于持续读取字符串str。 
	int j;  //变量 j 用于在str上重新覆盖 改写后的式子 
	for(j=i=0;(ch=str[i]) != 0;i++)
	{
		//遇到空格，直接跳过 
		if(ch == ' '); 
		//遇到数字，直接写入数组 
		else if(ch <= '9'&& ch>='0')
		{
				str2[j] = ch; //若是数字，直接写入数组 
				j++;
				
				ch = str[i+1];
				if(ch <= '9'&& ch>='0');
				else //若不是连续数字，用空格分隔 
				{
					str2[j] = ' ';
					j++;
				}
		}
		//遇到加减符号，把栈内除左括号一下的内容全部输出，并把该符号压栈 
		else if(ch == '+' || ch == '-')
		{
			while(!isEmpty(ls)) //判断栈是否为空 
			{
				pop(ls,&e);	//若非空，持续弹栈，直到遇到左括号或者栈为空 
//				printf("%d %c",e,e);
				if(e != '(')
				{
					str2[j] = e;
					j++; 
				}
				else //若遇到左括号，把弹出来的 括号 压回去 
				{
					push(ls,&e);
					break;
				}
			}
			e=ch;
			push(ls,&e);
			//show(ls); 
		}
		//遇到乘除，把栈顶的连续的乘除号弹出，并把当前符号压入栈 
		else if(ch == '*'||ch=='/')
		{
			while(getTop(ls,&e))
			{
				if(e=='*'||e=='/') //如果栈顶有乘除号，则持续弹出 
				{
					pop(ls,&e);
					str2[j] = e;
					j++;
					getTop(ls,&e);
				} 
				else
				{
					break;
				}
			}
			e = ch; //把该符号压进栈 
			push(ls,&e);
			show(ls);
		}
		//遇到左括号，直接压栈 
		else if(ch == '(')
		{
			e = ch;
			push(ls,&e);
		}
		//遇到右括号，把持续弹栈，直至遇到左括号 
		else if(ch == ')')
		{
			while(!isEmpty(ls))
			{
				pop(ls,&e); //持续弹栈检测 
				if(e != '(')
				{
					str2[j] = (int)e;
					j++; 
				}
				else
					break;
			}
			
		}
		else if(ch == '\n');
		//若非以上字符，则有异常字符。 
		else 
		{
			putchar(ch);
			printf("\n有异常字符。\n"); 
			exit(-1);
		}
	} 
	while(!isEmpty(ls))
	{
		pop(ls,&e);
		str2[j]=e;
		j++;
	}
	str2[j]=0;
	destroyStack(ls); //销毁栈
	strcpy(str,str2);; 
	return str;
}

float calculate(char * str)
{
	
	LinkStack * ls= initStack();
	ElemType e = 0;

	char ch;
	int i,j;
	int b=0;  //用于标记是否是大于10的数字
	float number[10]; //用于计算的数组 
	for(i=j=0;(ch = str[i])!=0;i++)
	{
		if(ch>='0'&&ch<='9')//若是数字，把数字从字符转化为数字
		{
			str[i]-='0';
			if(b==0)
			{
				b=1;
				number[j]=str[i];  
				j++;
			}
			else if(b == 1)
			{
				number[j-1]=number[j-1]*10+str[i];
			}
			else
			{
				printf("b异常！\n");
			}
//				printf("j=%d b=%d\n",j,b);
		}
		else if(ch == ' ')
		{
			b=0;
		}
		else//若是运算符，则调用函数运算，并赋入新的 计算数组 
		{
			b=0;
			j--;
			number[j-1]=cal(number[j-1],number[j],ch);
		}
		//展示number数组的内容 
//		{
//			int k;
//			for(k=0;k<j;k++)
//				printf("%.2f ",number[k]);
//			putchar('\n');
//		}
	} 
	destroyStack(ls); 
	return number[j-1];
}

float cal(float a,float b,char s)
{
	float num;
	switch (s)
	{
		case '+':
			num = a+b;
			break;
		case '-':
			num = a-b;
			break;
		case '*':
			num = a*b;
			break;
		case '/':
			num = 1.0*a/b;
			break;
		defalut:
			printf("%c是什么鬼",s);
	}
//	printf("num = %.2f\n",num);
	return num;
}
