#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

Stack* CreateStack();  // 初始化链栈 
int IsEmpty(Stack* S);  // 判断链栈是否为空 
void Push(Stack* S, Node* item);  // 入栈 
Node* Pop(Stack* S);  // 出栈




//二叉树
class CBinaryTree
{
public:
	CBinaryTree();
	~CBinaryTree();
	//插入
	bool insert_left(Node *cur ,ElemType e);
	bool insert_right(Node *cur ,ElemType e);
	//遍历 递归
	void pre_order(Node *cur);
	void in_order(Node *cur);
	void post_order(Node *cur);
	//遍历 非递归
	void pre_order_s(Node *cur);
	void in_order_s(Node *cur);
	void post_order_s(Node *cur);
	//层序遍历
	void level_order(Node *cur);
	Node *find(Node *cur, ElemType e);
	void destroy(Node *cur);
	void deleteTree();
	bool isempty();
	Node *createTree();
	//节点个数
	int count(Node *cur);
	int height(Node *cur);
private:
	Node *root = nullptr;
};

