/***************************************************************************************
 *	File Name				:	Stack_ADT.h
 *	CopyRight				:
 *	ModuleName				:	LinkStack header
 *
 *	SYSTEM					:   win10
 *	Create Data				:	2016.5.2
 *	Author/Corportation		:	
 *
 *	Abstract Description	:	this will be used for
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/


/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED


/**************************************************************
*	Include File Section
**************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**************************************************************
*	Macro Define Section
**************************************************************/
#define LEN sizeof(struct node)
#define MAXQUEUE 10
//��ͬ����ʵ�ַ�ʽ��ѡ��
//#define ARRAY         //ѭ������ʵ��
//#define HEADLINK    //��ͷ�������ʵ��
//#define UNLINK      //��ͷ�������ʵ��

/**************************************************************
*	Struct Define Section
**************************************************************/
#ifdef ARRAY
typedef struct queue
{
    void *data[MAXQUEUE];  //������
    int front;
    int rear;
    size_t data_size;
} Queue;

#else
//���нṹ
typedef struct node
{
    void* data;       //������ָ��
    struct node *next;//ָ��ǰ������һ���
    char type;  		  //��ȡ�������� 
} Node;

typedef struct queue
{
    Node *front;       //��ͷ
    Node *rear;        //��β
    size_t data_size;  //�������ڴ��С
    int count;
} Queue;

#endif // ARRAY

//Status���Ͷ���
typedef enum
{
    FALSE, TRUE
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : void InitQueue(Queue *Q)
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void InitQueue(Queue *Q);

/**
 *  @name        : void DestoryQueue(Queue *Q)
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryQueue(Queue *Q);

/**
 *  @name        : Status IsFullQueue(const Queue *Q)
 *	@description : �������Ƿ�����
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsFullQueue(const Queue *Q);

/**
 *  @name        : Status IsEmptyQueue(const Queue *Q)
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsEmptyQueue(const Queue *Q);

/**
 *  @name        : Status GetHeadQueue(Queue *Q, void *e)
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
 */
Status GetHeadQueue(Queue *Q, Node *n);

/**
 *  @name        : int LengthQueue(Queue *Q)
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
 *  @notice      : None
 */
int LengthQueue(Queue *Q);

/**
 *  @name        : Status EnQueue(Queue *Q, void *data)
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data��������ݵ�����type 
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnQueue(Queue *Q, void *data,const char type);

/**
 *  @name        : Status DeQueue(Queue *Q)
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q�����ӽڵ�n 
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �ýڵ�ָ�벻���� Ұָ�롣�ڵ�������Ҫ�ڵ��ú���֮����Ϊ���١� 
 */
Status DeQueue(Queue *Q,Node * n);

/**
 *  @name        : void ClearQueue(Queue *Q)
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearQueue(Queue *Q);

/**
 *  @name        : Status TraverseQueue(const Queue *Q, void (*foo)(Node *q))
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseQueue(const Queue *Q, void (*foo)(void *q));


/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif // QUEUE_H_INCLUDED
