/*��λ������������*/
#include"Stack.h"
//����ʽת��Ϊ�����ģʽ 
char * transform(char * str);
//����ת�����ʽ�� 
float calculate(char * str);
//���ڸ�������ĺ��� 
float cal(float a,float b,char s);

int main()
{
	//��ȡʽ�� 
	char *pstr;
	char str[31];
	printf("��ת��ΪӢ�����뷨��\n");
	printf("����������ʽ�ӣ�");
	fgets(str,30,stdin);
	fputs(str,stdout);
	
	//����ʽ�� 
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
	LinkStack * ls= initStack(); //��ʼ��һ�� ת��ջ 
	ElemType e = 0; //����һ��ѹջ��ջ����ʱ���� 

	char ch; //��ȡ���� 
	char str2[30]; //���ڴ洢��׺���ʽ 
	int i; //���� i ���ڳ�����ȡ�ַ���str�� 
	int j;  //���� j ������str�����¸��� ��д���ʽ�� 
	for(j=i=0;(ch=str[i]) != 0;i++)
	{
		//�����ո�ֱ������ 
		if(ch == ' '); 
		//�������֣�ֱ��д������ 
		else if(ch <= '9'&& ch>='0')
		{
				str2[j] = ch; //�������֣�ֱ��д������ 
				j++;
				
				ch = str[i+1];
				if(ch <= '9'&& ch>='0');
				else //�������������֣��ÿո�ָ� 
				{
					str2[j] = ' ';
					j++;
				}
		}
		//�����Ӽ����ţ���ջ�ڳ�������һ�µ�����ȫ����������Ѹ÷���ѹջ 
		else if(ch == '+' || ch == '-')
		{
			while(!isEmpty(ls)) //�ж�ջ�Ƿ�Ϊ�� 
			{
				pop(ls,&e);	//���ǿգ�������ջ��ֱ�����������Ż���ջΪ�� 
//				printf("%d %c",e,e);
				if(e != '(')
				{
					str2[j] = e;
					j++; 
				}
				else //�����������ţ��ѵ������� ���� ѹ��ȥ 
				{
					push(ls,&e);
					break;
				}
			}
			e=ch;
			push(ls,&e);
			//show(ls); 
		}
		//�����˳�����ջ���������ĳ˳��ŵ��������ѵ�ǰ����ѹ��ջ 
		else if(ch == '*'||ch=='/')
		{
			while(getTop(ls,&e))
			{
				if(e=='*'||e=='/') //���ջ���г˳��ţ���������� 
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
			e = ch; //�Ѹ÷���ѹ��ջ 
			push(ls,&e);
			show(ls);
		}
		//���������ţ�ֱ��ѹջ 
		else if(ch == '(')
		{
			e = ch;
			push(ls,&e);
		}
		//���������ţ��ѳ�����ջ��ֱ������������ 
		else if(ch == ')')
		{
			while(!isEmpty(ls))
			{
				pop(ls,&e); //������ջ��� 
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
		//���������ַ��������쳣�ַ��� 
		else 
		{
			putchar(ch);
			printf("\n���쳣�ַ���\n"); 
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
	destroyStack(ls); //����ջ
	strcpy(str,str2);; 
	return str;
}

float calculate(char * str)
{
	
	LinkStack * ls= initStack();
	ElemType e = 0;

	char ch;
	int i,j;
	int b=0;  //���ڱ���Ƿ��Ǵ���10������
	float number[10]; //���ڼ�������� 
	for(i=j=0;(ch = str[i])!=0;i++)
	{
		if(ch>='0'&&ch<='9')//�������֣������ִ��ַ�ת��Ϊ����
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
				printf("b�쳣��\n");
			}
//				printf("j=%d b=%d\n",j,b);
		}
		else if(ch == ' ')
		{
			b=0;
		}
		else//���������������ú������㣬�������µ� �������� 
		{
			b=0;
			j--;
			number[j-1]=cal(number[j-1],number[j],ch);
		}
		//չʾnumber��������� 
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
			printf("%c��ʲô��",s);
	}
//	printf("num = %.2f\n",num);
	return num;
}
