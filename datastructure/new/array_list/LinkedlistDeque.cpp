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
		throw out_of_range("队列为空");

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
		throw out_of_range("队列为空");
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
		throw out_of_range("队列为空");
	return front_->val;
}

int LinkedlistDeque::peekLast()
{
	if (isEmpty())
		throw out_of_range("队列为空");
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
	/* 初始化双向队列 */
	LinkedlistDeque *deque = new LinkedlistDeque();
	deque->push_last(3);
	deque->push_last(2);
	deque->push_last(5);
	cout << "双向队列 deque = ";
	deque->print();

	/* 访问元素 */
	int peekFirst = deque->peekFirst();
	cout << "队首元素 peekFirst = " << peekFirst << endl;
	int peekLast = deque->peekLast();
	cout << "队尾元素 peekLast = " << peekLast << endl;

	/* 元素入队 */
	deque->push_last(4);
	cout << "元素 4 队尾入队后 deque =";
	deque->print();
	deque->push_first(1);
	cout << "元素 1 队首入队后 deque = ";
	deque->print();

	/* 元素出队 */
	int popLast = deque->pop_last();
	cout << "队尾出队元素 = " << popLast << "，队尾出队后 deque = ";
	deque->print();
	int popFirst = deque->pop_first();
	cout << "队首出队元素 = " << popFirst << "，队首出队后 deque = ";
	deque->print();

	/* 获取双向队列的长度 */
	int size = deque->size();
	cout << "双向队列长度 size = " << size << endl;

	/* 判断双向队列是否为空 */
	bool isEmpty = deque->isEmpty();
	cout << "双向队列是否为空 = " << boolalpha << isEmpty << endl;

	// 释放内存
	delete deque;
}
