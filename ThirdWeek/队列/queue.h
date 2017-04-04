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
//不同队列实现方式的选择
//#define ARRAY         //循环数组实现
//#define HEADLINK    //带头结点链表实现
//#define UNLINK      //无头结点链表实现

/**************************************************************
*	Struct Define Section
**************************************************************/
#ifdef ARRAY
typedef struct queue
{
    void *data[MAXQUEUE];  //数据域
    int front;
    int rear;
    size_t data_size;
} Queue;

#else
//队列结构
typedef struct node
{
    void* data;       //数据域指针
    struct node *next;//指向当前结点的下一结点
    char type;  		  //获取数据类型 
} Node;

typedef struct queue
{
    Node *front;       //队头
    Node *rear;        //队尾
    size_t data_size;  //数据域内存大小
    int count;
} Queue;

#endif // ARRAY

//Status类型定义
typedef enum
{
    FALSE, TRUE
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : void InitQueue(Queue *Q)
 *	@description : 初始化队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void InitQueue(Queue *Q);

/**
 *  @name        : void DestoryQueue(Queue *Q)
 *	@description : 销毁队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryQueue(Queue *Q);

/**
 *  @name        : Status IsFullQueue(const Queue *Q)
 *	@description : 检查队列是否已满
 *	@param		 : 队列指针Q
 *	@return		 : 满-TRUE; 未满-FLASE
 *  @notice      : None
 */
Status IsFullQueue(const Queue *Q);

/**
 *  @name        : Status IsEmptyQueue(const Queue *Q)
 *	@description : 检查队列是否为空
 *	@param		 : 队列指针Q
 *	@return		 : 空-TRUE; 未空-FLASE
 *  @notice      : None
 */
Status IsEmptyQueue(const Queue *Q);

/**
 *  @name        : Status GetHeadQueue(Queue *Q, void *e)
 *	@description : 查看队头元素
 *	@param		 : 队列指针Q，存放元素e
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否空
 */
Status GetHeadQueue(Queue *Q, Node *n);

/**
 *  @name        : int LengthQueue(Queue *Q)
 *	@description : 确定队列长度
 *	@param		 : 队列指针Q
 *	@return		 : 队列长度count
 *  @notice      : None
 */
int LengthQueue(Queue *Q);

/**
 *  @name        : Status EnQueue(Queue *Q, void *data)
 *	@description : 入队操作
 *	@param		 : 队列指针Q,入队数据指针data，入队数据的类型type 
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否满了或为空
 */
Status EnQueue(Queue *Q, void *data,const char type);

/**
 *  @name        : Status DeQueue(Queue *Q)
 *	@description : 出队操作
 *	@param		 : 队列指针Q，出队节点n 
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 该节点指针不能是 野指针。节点数据需要在调用函数之后人为销毁。 
 */
Status DeQueue(Queue *Q,Node * n);

/**
 *  @name        : void ClearQueue(Queue *Q)
 *	@description : 清空队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearQueue(Queue *Q);

/**
 *  @name        : Status TraverseQueue(const Queue *Q, void (*foo)(Node *q))
 *	@description : 遍历函数操作
 *	@param		 : 队列指针Q，操作函数指针foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseQueue(const Queue *Q, void (*foo)(void *q));


/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif // QUEUE_H_INCLUDED
