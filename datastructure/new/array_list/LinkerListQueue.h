#pragma once
#include "ZLinkedlist.h"

//����ʵ�ֵĶ���
class LinkerListQueue
{
public:
	LinkerListQueue();

	~LinkerListQueue();

	void push(int num);

	int pop();

	int size();

	bool isEmpty();

	int peek();

	static void test();

	void print();
private:
	int size_;

	ListNode* head_;
	ListNode* tail_;
};

