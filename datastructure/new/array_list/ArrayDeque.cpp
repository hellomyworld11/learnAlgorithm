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
		std::cout << "队列满" << std::endl;
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
		std::cout << "队列满" << std::endl;
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
		throw std::out_of_range("双向队列为空");
	return nums_[front_];
}

int ArrayDeque::peekLast()
{
	if (isEmpty())
		throw std::out_of_range("双向队列为空");
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
	std::cout << "双向队列 deque = ";
	deque->print();

	/* 访问元素 */
	int peekFirst = deque->peekFirst();
	std::cout << "队首元素 peekFirst = " << peekFirst << std::endl;
	int peekLast = deque->peekLast();
	std::cout << "队尾元素 peekLast = " << peekLast << std::endl;

	/* 元素入队 */
	deque->push_last(4);
	std::cout << "元素 4 队尾入队后 deque = ";
	deque->print();
	deque->push_first(1);
	std::cout << "元素 1 队首入队后 deque = ";
	deque->print();

	/* 元素出队 */
	int popLast = deque->pop_last();
	std::cout << "队尾出队元素 = " << popLast << "，队尾出队后 deque = ";
	deque->print();
	int popFirst = deque->pop_first();
	std::cout << "队首出队元素 = " << popFirst << "，队首出队后 deque = ";
	deque->print();

	/* 获取双向队列的长度 */
	int size = deque->size();
	std::cout << "双向队列长度 size = " << size << std::endl;

	/* 判断双向队列是否为空 */
	bool isEmpty = deque->isEmpty();
	std::cout << "双向队列是否为空 = " << std::boolalpha << isEmpty << std::endl;
	return ;
}
