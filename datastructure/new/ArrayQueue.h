#pragma once



class ArrayQueue
{
public:
	ArrayQueue(int capacity);

	~ArrayQueue();

	void push(int num);

	int pop();

	int peek();

	int capacity();

	int size();

	bool isEmpty();

	void print();

	static void test();
private:

	int size_;

	int head;
	
	int *nums_;

	int capacity_;

};

