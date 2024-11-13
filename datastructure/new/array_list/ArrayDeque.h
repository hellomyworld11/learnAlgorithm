#pragma once
#include <vector>

//数组实现的双向队列
class ArrayDeque
{
public:
	ArrayDeque(int capacity);

	~ArrayDeque();

	int capacity();

	int size();

	bool isEmpty();

	int index(int i);

	void push_first(int num);

	void push_last(int num);

	int pop_first();

	int pop_last();

	int peekFirst();

	int peekLast();

	void print();

	static void test();
private:
	std::vector<int> nums_;
	int front_;
	int size_;
};

