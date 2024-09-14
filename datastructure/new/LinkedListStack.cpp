#include "LinkedListStack.h"
#include "util.h"

LinkedListStack::LinkedListStack()
	:stackTop_(nullptr),
	size_(0)
{
	
}

LinkedListStack::~LinkedListStack()
{
	listFree(stackTop_);
}

int LinkedListStack::size()
{
	return size_;
}

bool LinkedListStack::isEmpty()
{
	return size_ == 0;
}

void LinkedListStack::push(int num)
{
	ListNode *node = new ListNode(num);
	node->next = stackTop_;
	stackTop_ = node;
	size_++;
}

int LinkedListStack::pop()
{
	int num = top();
	ListNode *node = stackTop_;
	stackTop_ = stackTop_->next;
	delete node;
	size_--;
	return num;
}

int LinkedListStack::top()
{
	if (isEmpty())
		throw out_of_range("ջΪ��");
	return stackTop_->val;
}

void LinkedListStack::print()
{
	std::cout << " [ ";
	ListNode *p = stackTop_;
	while (p != nullptr) {
		std::cout << p->val << " ";
		p = p->next;
	}
	std::cout << " ] " << std::endl;
}

void LinkedListStack::test()
{
	using namespace std;
	LinkedListStack stack;
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
