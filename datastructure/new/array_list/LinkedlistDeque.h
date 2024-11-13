#pragma once

struct DoublyListNode {
	int val;
	DoublyListNode *next;
	DoublyListNode *pre;
	DoublyListNode(int val) :val(val), pre(nullptr), next(nullptr) {}
};

//双向链表实现的双向队列
class LinkedlistDeque
{
public:
	LinkedlistDeque();

	~LinkedlistDeque();

	int size();

	bool isEmpty();

	//入队
	void push_first(int num);

	void push_last(int num);

	//出队
	int pop_first();

	int pop_last();

	int peekFirst();

	int peekLast();

	void print();

	static void test();
private:
	DoublyListNode *front_;
	DoublyListNode *rear_;
	int size_;
};

