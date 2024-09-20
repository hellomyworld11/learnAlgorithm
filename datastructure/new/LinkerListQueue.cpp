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
		throw out_of_range("����Ϊ��");

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
		throw out_of_range("����Ϊ��");
	return head_->val;
}

void LinkerListQueue::test()
{
	LinkerListQueue *queue = new LinkerListQueue();

	/* Ԫ����� */
	queue->push(1);
	queue->push(2);
	queue->push(3);
	queue->push(4);
	queue->push(5);
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

	// �ͷ��ڴ�
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
