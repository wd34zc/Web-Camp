#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Node {    
	int data;    
	struct Node *next; 
}Node, *ptr_Node; 
 
typedef enum Status {
  SUCCESS, ERROR 
  }Status; 
 
//根据数组生成一条链表，成功则返回头节点，失败返回 NULL 
ptr_Node create(int *arr, int n); 
 
//销毁给定的链表 
void destroy(ptr_Node head); 
 
//在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
Status insert(ptr_Node *head, ptr_Node node, int index); 
 
//删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
//删除成功返回 SUCCESS，其他情况返回 ERROR 
Status delete(ptr_Node *head, int index, int *data); 
 
//在链表中查找节点值与 data 相等的节点，并返回找到的第一个节点的前一个节点的位置 
//（例：头节点相等，返回 0），没找到或者其他情况返回-1 
ptr_Node search(ptr_Node head, int data); 
 
//将链表中 index 位点后面的结点的值修改为(*data)，将原值保存到(*data) 
//修改成功返回 SUCCESS，其他情况返回 ERROR 
Status edit(ptr_Node head, int index, int *data); 
 
//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好） 
void print(ptr_Node head); 
 
//此题选做,实现单链表按照节点值大小升序排序 
Status sort(ptr_Node *head); 
 
 
