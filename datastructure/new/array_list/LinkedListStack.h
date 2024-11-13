#pragma once
#include "ZLinkedlist.h"


//����ʵ�ֵ�ջ  ͷ�巨
class LinkedListStack
{
public:
	LinkedListStack();

	~LinkedListStack();

	int size();

	bool isEmpty();

	void push(int num);

	int pop();

	int top();
	
	void print();

	static void test();
private:
	ListNode* stackTop_;
	int		  size_;
};

