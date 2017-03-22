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
 
//������������һ�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL 
ptr_Node create(int *arr, int n); 
 
//���ٸ��������� 
void destroy(ptr_Node head); 
 
//�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
Status insert(ptr_Node *head, ptr_Node node, int index); 
 
//ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
//ɾ���ɹ����� SUCCESS������������� ERROR 
Status delete(ptr_Node *head, int index, int *data); 
 
//�������в��ҽڵ�ֵ�� data ��ȵĽڵ㣬�������ҵ��ĵ�һ���ڵ��ǰһ���ڵ��λ�� 
//������ͷ�ڵ���ȣ����� 0����û�ҵ����������������-1 
ptr_Node search(ptr_Node head, int data); 
 
//�������� index λ�����Ľ���ֵ�޸�Ϊ(*data)����ԭֵ���浽(*data) 
//�޸ĳɹ����� SUCCESS������������� ERROR 
Status edit(ptr_Node head, int index, int *data); 
 
//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã� 
void print(ptr_Node head); 
 
//����ѡ��,ʵ�ֵ������սڵ�ֵ��С�������� 
Status sort(ptr_Node *head); 
 
 
