#include "ArrayQueue.h"
#include "util.h"


ArrayQueue::ArrayQueue(int capacity):capacity_(capacity)
{
	nums_ = new int[capacity_];
	head = size_ = 0;
}


ArrayQueue::~ArrayQueue()
{
	delete[] nums_;
}

void ArrayQueue::push(int num)
{
	if (size_ == capacity_)
	{
		cout << "队列满" << endl;
		return;
	}

	int tail = (head + size_) % capacity_;
	nums_[tail] = num;
	size_++;
}

int ArrayQueue::pop()
{
	int num = peek();
	head = (head + 1) % capacity_;
	size_--;
	return num;
}

int ArrayQueue::peek()
{
	if(isEmpty())
		throw out_of_range("队列为空");

	return nums_[head];
}

int ArrayQueue::capacity()
{
	return capacity_;
}

int ArrayQueue::size()
{
	return size_;
}

bool ArrayQueue::isEmpty()
{
	return 0 == size_;
}

void ArrayQueue::print()
{
	std::cout << " [ ";
	for (int i = 0, j = head; i < size_; i++, j++) {
		int val = nums_[j % capacity_];
		std::cout << val << " ";
	}
	std::cout << " ] " << std::endl;
}

void ArrayQueue::test()
{
	int capacity = 10;
	ArrayQueue *queue = new ArrayQueue(capacity);

	/* 元素入队 */
	queue->push(1);
	queue->push(3);
	queue->push(2);
	queue->push(5);
	queue->push(4);
	cout << "队列 queue = ";
	queue->print();

	/* 访问队首元素 */
	int peek = queue->peek();
	cout << "队首元素 peek = " << peek << endl;

	/* 元素出队 */
	peek = queue->pop();
	cout << "出队元素 pop = " << peek << "，出队后 queue = ";
	queue->print();

	/* 获取队列的长度 */
	int size = queue->size();
	cout << "队列长度 size = " << size << endl;

	/* 判断队列是否为空 */
	bool empty = queue->isEmpty();
	cout << "队列是否为空 = " << empty << endl;

	/* 测试环形数组 */
	for (int i = 0; i < 10; i++) {
		queue->push(i);
		queue->pop();
		cout << "第 " << i << " 轮入队 + 出队后 queue = ";
		queue->print();
	}

	// 释放内存
	delete queue;
}
