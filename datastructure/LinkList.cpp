#include "LinkList.h"



CLinkList::CLinkList()
{
	init();
}

CLinkList::~CLinkList()
{
	clear();
}

void CLinkList::init()
{
	head = nullptr;
}

int CLinkList::length()
{
	return len;
// 	if (head == nullptr)
// 	{
// 		return 0;
// 	}
// 	Node *p = head->next;
// 	int ilen = 1;
// 	while (p != nullptr)
// 	{
// 		p = p->next;
// 		ilen++;
// 	}
//	return ilen;
}

int CLinkList::tailCreate(int n /*= 1*/)
{
	clear();
	Node *r = nullptr;
	for (int i = 0; i < n; i++)
	{
		Node *pnew = new Node();
		if (pnew == nullptr)
		{
			return -1;
		}
		std::cin >> pnew->data;
		pnew->next = nullptr;
		if (head == nullptr)
		{
			head = pnew;
		}
		else 
		{
			r->next = pnew;
		}
		r = pnew;
	}
	len = n;
	return 0;
}

int CLinkList::insert(ElemType elem, int i)
{
	//插入之后
	Node *p = find(i);
	if (p == nullptr)
	{
		return -1;
	}
	Node *n = new Node();
	n->data = elem;
	n->next = p->next;
	p->next = n;
	return 0;
}

int CLinkList::deleted(int i)
{
	if (i < 0 || i >= len)
	{
		return -1;
	}
	//找到前一个
	Node *pre = find(i - 1);
	if (pre == nullptr)
	{
		Node *p = head->next;
		delete head;
		head = p;
		len--;
	}
	else {
		Node *p = pre->next;
		pre->next = p->next;
		delete p;
		p = nullptr;
		len--;
	}
	return 0;
}

Node * CLinkList::find(int i)
{
	if (i < 0 || i > len || len == 0)
	{
		return nullptr;
	}
	Node *p = head;
	while (p != nullptr && i >= 0)
	{
		p = p->next;
		i--;
	}
	return p;
}

Node * CLinkList::find(ElemType val)
{
	Node *p = head;
	while (p != nullptr)
	{
		if (p->data == val)
		{
			return p;
		}
	}
	return p;
}

void CLinkList::reverse()
{
	//1 2 3 4 5   ->   5 4 3 2 1
	Node *p = nullptr, *q = nullptr;
	p = head->next;
	head->next = nullptr;
	while (p)
	{
		q = p->next;
		p->next = head;
		head = p;
		p = q;
	}
}

void CLinkList::clear()
{
	Node *p = head;
	while (p)
	{
		Node *q = p->next;
		delete p;
		p = q;
	}
	head = nullptr;
}

void CLinkList::print()
{
	Node *p = head;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << std::endl;
}

Node * SolutionList::merge(Node *l1, Node *l2)
{
	if (l1 == nullptr)
	{
		return l2;
	}else if (l2 == nullptr)
	{
		return l1;
	}
	else if (l1->data < l2->data)
	{
		l1->next = SolutionList::merge(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = Solution::merge(l1, l2->next);
		return l2;
	}
}
