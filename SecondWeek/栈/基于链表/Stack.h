#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h> 
typedef enum Status{
	ERROR,OK
}Status;

typedef int ElemType;
typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;	
}StackNode ,*LinkStackPtr;

typedef  struct  LinkStack{
	LinkStackPtr top;	  //ջ��ָ��
	int	count;  //ջ��Ԫ�ظ���
}LinkStack;

//��ʼ��һ��ջ 
LinkStack* initStack(void);

//�ж�ջ�Ƿ�Ϊ�� 
Status isEmpty(LinkStack* l);

//��ջ
//n�������յ�����ջ 
Status pop(LinkStack * l,ElemType * e);

//ѹջ 
//n�Ǽ���ѹ���ջ 
Status push(LinkStack * l ,ElemType * e);

//��ȡջ������ 
Status getTop(LinkStack * l ,ElemType * e);

//��Ϊ��ջ 
Status clear(LinkStack* l);

//����ջ 
Status destroyStack(LinkStack* l);

//��ȡջ�ĳ��� 
Status stackLength(LinkStack* l ,int * n);

void show(LinkStack* l ); 


