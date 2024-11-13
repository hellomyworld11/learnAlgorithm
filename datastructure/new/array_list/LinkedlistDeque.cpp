#include "LinkedlistDeque.h"
#include "../util.h"


LinkedlistDeque::LinkedlistDeque():front_(nullptr),rear_(nullptr)
{
}


LinkedlistDeque::~LinkedlistDeque()
{
	DoublyListNode *pre, *cur = front_;
	while (cur != nullptr)
	{
		pre = cur;
		cur = cur->next;
		delete pre;
	}
}

int LinkedlistDeque::size()
{
	return size_;
}

bool LinkedlistDeque::isEmpty()
{
	return size_ == 0;
}

void LinkedlistDeque::push_first(int num)
{
	DoublyListNode *newnode = new DoublyListNode(num);
	if (isEmpty())
	{
		front_ = rear_ = newnode;
	}
	else {
		newnode->next = front_;
		front_->pre = newnode;
		front_ = newnode;
	}
	size_++;
}

void LinkedlistDeque::push_last(int num)
{
	DoublyListNode *newnode = new DoublyListNode(num);
	if (isEmpty())
	{
		front_ = rear_ = newnode;	
	}
	else {
		newnode->pre = rear_;
		rear_->next = newnode;
		rear_ = newnode;
	}
	
	size_++;
}

int LinkedlistDeque::pop_first()
{
	if (isEmpty())
		throw out_of_range("����Ϊ��");

	DoublyListNode *popnode = front_;
	front_ = front_->next;
	if (front_)
	{
		front_->pre = nullptr;
	}
	int val = popnode->val;
	delete popnode;
	size_--;
	return val;
}

int LinkedlistDeque::pop_last()
{
	if (isEmpty())
		throw out_of_range("����Ϊ��");
	DoublyListNode *popnode = rear_;
	rear_ = rear_->pre;
	if (rear_)
	{
		rear_->next = nullptr;
	}
	int val = popnode->val;
	delete popnode;
	size_--;
	return val;
}

int LinkedlistDeque::peekFirst()
{
	if (isEmpty())
		throw out_of_range("����Ϊ��");
	return front_->val;
}

int LinkedlistDeque::peekLast()
{
	if (isEmpty())
		throw out_of_range("����Ϊ��");
	return rear_->val;
}

void LinkedlistDeque::print()
{
	std::cout << " [ ";
	DoublyListNode *p = front_;
	while (p != nullptr) {
		std::cout << p->val << " ";
		p = p->next;
	}
	std::cout << " ] " << std::endl;
}

void LinkedlistDeque::test()
{
	/* ��ʼ��˫����� */
	LinkedlistDeque *deque = new LinkedlistDeque();
	deque->push_last(3);
	deque->push_last(2);
	deque->push_last(5);
	cout << "˫����� deque = ";
	deque->print();

	/* ����Ԫ�� */
	int peekFirst = deque->peekFirst();
	cout << "����Ԫ�� peekFirst = " << peekFirst << endl;
	int peekLast = deque->peekLast();
	cout << "��βԪ�� peekLast = " << peekLast << endl;

	/* Ԫ����� */
	deque->push_last(4);
	cout << "Ԫ�� 4 ��β��Ӻ� deque =";
	deque->print();
	deque->push_first(1);
	cout << "Ԫ�� 1 ������Ӻ� deque = ";
	deque->print();

	/* Ԫ�س��� */
	int popLast = deque->pop_last();
	cout << "��β����Ԫ�� = " << popLast << "����β���Ӻ� deque = ";
	deque->print();
	int popFirst = deque->pop_first();
	cout << "���׳���Ԫ�� = " << popFirst << "�����׳��Ӻ� deque = ";
	deque->print();

	/* ��ȡ˫����еĳ��� */
	int size = deque->size();
	cout << "˫����г��� size = " << size << endl;

	/* �ж�˫������Ƿ�Ϊ�� */
	bool isEmpty = deque->isEmpty();
	cout << "˫������Ƿ�Ϊ�� = " << boolalpha << isEmpty << endl;

	// �ͷ��ڴ�
	delete deque;
}
