#include "ArrayDeque.h"
#include <iostream>
#include "../util.h"

ArrayDeque::ArrayDeque(int capacity)
{
	nums_.resize(capacity);
	front_ = size_ = 0;
}


ArrayDeque::~ArrayDeque()
{
}

int ArrayDeque::capacity()
{
	return nums_.size();
}

int ArrayDeque::size()
{
	return size_;
}

bool ArrayDeque::isEmpty()
{
	return size_ == 0;
}

int ArrayDeque::index(int i)
{
	return (i + capacity()) % capacity();
}

void ArrayDeque::push_first(int num)
{
	if (size_ == capacity())
	{
		std::cout << "������" << std::endl;
		return;
	}
	front_ = index(front_ - 1);
	nums_[front_] = num;
	size_++;
}

void ArrayDeque::push_last(int num)
{
	if (size_ == capacity())
	{
		std::cout << "������" << std::endl;
		return;
	}

	int rear = index(front_ + size_);
	nums_[rear] = num;
	size_++;
}

int ArrayDeque::pop_first()
{
	int num = peekFirst();
	front_ = index(front_ + 1);
	size_--;
	return num;
}

int ArrayDeque::pop_last()
{
	int num = peekLast();
	size_--;
	return num;
}

int ArrayDeque::peekFirst()
{
	if (isEmpty())
		throw std::out_of_range("˫�����Ϊ��");
	return nums_[front_];
}

int ArrayDeque::peekLast()
{
	if (isEmpty())
		throw std::out_of_range("˫�����Ϊ��");
	int last = index(front_ + size_ - 1);
	return nums_[last];
}

void ArrayDeque::print()
{
	std::cout << " [ ";
	for (int i = 0, j = front_; i < size_; i++, j++) {
		int val = nums_[index(j)];
		std::cout << val << " ";
	}
	std::cout << " ] " << std::endl;
}

void ArrayDeque::test()
{
	ArrayDeque *deque = new ArrayDeque(10);
	deque->push_last(3);
	deque->push_last(2);
	deque->push_last(5);
	std::cout << "˫����� deque = ";
	deque->print();

	/* ����Ԫ�� */
	int peekFirst = deque->peekFirst();
	std::cout << "����Ԫ�� peekFirst = " << peekFirst << std::endl;
	int peekLast = deque->peekLast();
	std::cout << "��βԪ�� peekLast = " << peekLast << std::endl;

	/* Ԫ����� */
	deque->push_last(4);
	std::cout << "Ԫ�� 4 ��β��Ӻ� deque = ";
	deque->print();
	deque->push_first(1);
	std::cout << "Ԫ�� 1 ������Ӻ� deque = ";
	deque->print();

	/* Ԫ�س��� */
	int popLast = deque->pop_last();
	std::cout << "��β����Ԫ�� = " << popLast << "����β���Ӻ� deque = ";
	deque->print();
	int popFirst = deque->pop_first();
	std::cout << "���׳���Ԫ�� = " << popFirst << "�����׳��Ӻ� deque = ";
	deque->print();

	/* ��ȡ˫����еĳ��� */
	int size = deque->size();
	std::cout << "˫����г��� size = " << size << std::endl;

	/* �ж�˫������Ƿ�Ϊ�� */
	bool isEmpty = deque->isEmpty();
	std::cout << "˫������Ƿ�Ϊ�� = " << std::boolalpha << isEmpty << std::endl;
	return ;
}
