#pragma once

struct DoublyListNode {
	int val;
	DoublyListNode *next;
	DoublyListNode *pre;
	DoublyListNode(int val) :val(val), pre(nullptr), next(nullptr) {}
};

//˫������ʵ�ֵ�˫�����
class LinkedlistDeque
{
public:
	LinkedlistDeque();

	~LinkedlistDeque();

	int size();

	bool isEmpty();

	//���
	void push_first(int num);

	void push_last(int num);

	//����
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

