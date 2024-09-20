#include "LinkerListQueue.h"
#include "util.h"


LinkerListQueue::LinkerListQueue():head_(nullptr),tail_(nullptr),size_(0)
{
}


LinkerListQueue::~LinkerListQueue()
{
	listFree(head_);
}

void LinkerListQueue::push(int num)
{
	ListNode *node = new ListNode(num);
	if (tail_ == nullptr)
	{
		tail_ = node;
		head_ = node;
	}
	else {
		tail_->next = node;
		tail_ = node;
	}
	size_++;
}

int LinkerListQueue::pop()
{
	if (isEmpty())
		throw out_of_range("队列为空");

	ListNode *tmp = head_;
	head_ = head_->next;
	int num = tmp->val;
	delete tmp;
	tmp = nullptr;
	size_--;
	return num;
}

int LinkerListQueue::size()
{
	return size_;
}

bool LinkerListQueue::isEmpty()
{
	return size_ == 0;
}

int LinkerListQueue::peek()
{
	if (isEmpty())
		throw out_of_range("队列为空");
	return head_->val;
}

void LinkerListQueue::test()
{
	LinkerListQueue *queue = new LinkerListQueue();

	/* 元素入队 */
	queue->push(1);
	queue->push(2);
	queue->push(3);
	queue->push(4);
	queue->push(5);
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

	// 释放内存
	delete queue;
}

void LinkerListQueue::print()
{
	std::cout << " [ ";
	ListNode *p = head_;
	while (p != nullptr) {
		std::cout << p->val << " ";
		p = p->next;
	}
	std::cout << " ] " << std::endl;
}
