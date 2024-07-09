#include "LinkStack.h"



CLinkStack::CLinkStack() :top{ nullptr }
{
}


CLinkStack::~CLinkStack()
{
	clear();
}

void CLinkStack::clear()
{
	Node *p = nullptr;
	while (top)
	{
		p = top;
		top = top->next;
		delete p;
	}
	top = nullptr;
}

bool CLinkStack::isEmpty()
{
	return (!top);
}

bool CLinkStack::push(ElemType elem)
{
	Node *p = new Node;
	if (p)
	{
		p->data = elem;
		p->next = top;
		top = p;
		return true;
	}
	return false;
}

bool CLinkStack::pop(ElemType &elem)
{
	if (isEmpty()) return false;
	Node *p = top->next;
	elem = top->data;
	delete top;
	top = p;
	return true;
}

bool CLinkStack::gettop(ElemType &elem)
{
	if (isEmpty())return false;
	return elem = top->data;
}
