/**  * ˫���������  */ 
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
 
//˫������,ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
Status delete_T(ptr_TNode *head, int index, int *data); 
//˫������,�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
Status insert_T(ptr_TNode *head, ptr_TNode node, int index); 
