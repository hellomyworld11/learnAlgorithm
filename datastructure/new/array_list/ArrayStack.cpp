#include "ArrayStack.h"



ArrayStack::ArrayStack()
{
}


ArrayStack::~ArrayStack()
{
}

int ArrayStack::size()
{
	return stack_.size();
}

bool ArrayStack::isEmpty()
{
	return stack_.size() == 0;
}

void ArrayStack::push(int num)
{
	stack_.push_back(num);
}

int ArrayStack::pop()
{
	int num = top();
	stack_.pop_back();
	return num;
}

int ArrayStack::top()
{
	if (isEmpty())
		throw out_of_range("ջΪ��");
	return stack_.back();
}

void ArrayStack::print()
{
	std::cout << " [ ";
	for (auto val : stack_)
	{
		std::cout << val << " ";
	}
	std::cout << " ] " << std::endl;
}

void ArrayStack::test()
{
	ArrayStack stack;
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);
	cout << "ջ stack = ";
	stack.print();

	/* ����ջ��Ԫ�� */
	int top = stack.top();
	cout << "ջ��Ԫ�� top = " << top << endl;

	/* Ԫ�س�ջ */
	top = stack.pop();
	cout << "��ջԪ�� pop = " << top << "����ջ�� stack = ";
	stack.print();

	/* ��ȡջ�ĳ��� */
	int size = stack.size();
	cout << "ջ�ĳ��� size = " << size << endl;

	/* �ж��Ƿ�Ϊ�� */
	bool empty = stack.isEmpty();
	cout << "ջ�Ƿ�Ϊ�� = " << empty << endl;
}
