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
		throw out_of_range("栈为空");
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
