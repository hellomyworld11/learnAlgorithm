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
		throw out_of_range("栈为空");
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
	cout << "栈 stack = ";
	stack.print();

	/* 访问栈顶元素 */
	int top = stack.top();
	cout << "栈顶元素 top = " << top << endl;

	/* 元素出栈 */
	top = stack.pop();
	cout << "出栈元素 pop = " << top << "，出栈后 stack = ";
	stack.print();

	/* 获取栈的长度 */
	int size = stack.size();
	cout << "栈的长度 size = " << size << endl;

	/* 判断是否为空 */
	bool empty = stack.isEmpty();
	cout << "栈是否为空 = " << empty << endl;
}
