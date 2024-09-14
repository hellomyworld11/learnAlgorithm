#pragma once

#include "util.h"


//����ʵ�ֵ�ջ
class ArrayStack
{
public:
	ArrayStack();

	~ArrayStack();

	int size();

	bool isEmpty();

	void push(int num);

	int pop();

	int top();

	void print();

	static void test();

private:
	vector<int> stack_;

};

