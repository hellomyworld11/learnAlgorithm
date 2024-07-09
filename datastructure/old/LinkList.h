#pragma once
#include <iostream>
typedef int ElemType;
typedef struct Node {
	ElemType data;
	Node *next = nullptr;
};
//线性表链式存储结构  不带头节点

class CLinkList
{
public:
	CLinkList();
	~CLinkList();
	void init();
	int length();
	int tailCreate(int n = 1);
	int insert(ElemType elem, int i);
	int deleted(int i);
	Node *findByIndex(int i);
	Node *find(ElemType val);	
	void reverse();
	void clear();
	void print();
	
private:
	Node *head = nullptr;
	int  len = 0;
};

//常用算法
class SolutionList {
public:
	static Node *merge(Node *l1, Node *l2); //合并有序链表
};

