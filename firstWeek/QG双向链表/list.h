/**  * 双向链表操作  */ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
typedef struct TNode {
    int data;
	struct TNode *next;
	struct TNode *pre;
}TNode, *ptr_TNode; 

typedef enum Status {
  SUCCESS, ERROR 
  }Status; 
 
//双向链表,删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
Status delete_T(ptr_TNode *head, int index, int *data); 
//双向链表,在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
Status insert_T(ptr_TNode *head, ptr_TNode node, int index); 
