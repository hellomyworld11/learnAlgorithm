#pragma once
#include <iostream>


typedef int ElemType;
typedef struct Node {
	ElemType data;
	Node *left = nullptr;
	Node *right = nullptr;
};


 typedef struct Stack {
	Node* Data;
	Stack* Next;
};

Stack* CreateStack();  // ��ʼ����ջ 
int IsEmpty(Stack* S);  // �ж���ջ�Ƿ�Ϊ�� 
void Push(Stack* S, Node* item);  // ��ջ 
Node* Pop(Stack* S);  // ��ջ





class CBinaryTree
{
public:
	CBinaryTree();
	~CBinaryTree();
	bool insert_left(Node *cur ,ElemType e);
	bool insert_right(Node *cur ,ElemType e);
	void pre_order(Node *cur);
	void in_order(Node *cur);
	void post_order(Node *cur);
	void pre_order_s(Node *cur);
	void in_order_s(Node *cur);
	void post_order_s(Node *cur);
	Node *find(Node *cur, ElemType e);
	void destroy(Node *cur);
	void deleteTree();
	bool isempty();
	Node *createTree();
private:
	Node *root = nullptr;
};

