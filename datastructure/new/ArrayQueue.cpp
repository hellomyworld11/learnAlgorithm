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
		cout << "������" << endl;
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
		throw out_of_range("����Ϊ��");

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

	/* Ԫ����� */
	queue->push(1);
	queue->push(3);
	queue->push(2);
	queue->push(5);
	queue->push(4);
	cout << "���� queue = ";
	queue->print();

	/* ���ʶ���Ԫ�� */
	int peek = queue->peek();
	cout << "����Ԫ�� peek = " << peek << endl;

	/* Ԫ�س��� */
	peek = queue->pop();
	cout << "����Ԫ�� pop = " << peek << "�����Ӻ� queue = ";
	queue->print();

	/* ��ȡ���еĳ��� */
	int size = queue->size();
	cout << "���г��� size = " << size << endl;

	/* �ж϶����Ƿ�Ϊ�� */
	bool empty = queue->isEmpty();
	cout << "�����Ƿ�Ϊ�� = " << empty << endl;

	/* ���Ի������� */
	for (int i = 0; i < 10; i++) {
		queue->push(i);
		queue->pop();
		cout << "�� " << i << " ����� + ���Ӻ� queue = ";
		queue->print();
	}

	// �ͷ��ڴ�
	delete queue;
}
