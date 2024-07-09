#include "BinaryTree.h"



CBinaryTree::CBinaryTree()
{
}


CBinaryTree::~CBinaryTree()
{
}

bool CBinaryTree::insert_left(Node *cur, ElemType e)
{
	if (cur == nullptr)
	{
		return false;
	}
	Node *p = new Node;
	p->data = e;
	cur->left = p;
	return true;
}

bool CBinaryTree::insert_right(Node *cur, ElemType e)
{
	if (cur == nullptr)
	{
		return false;
	}
	Node *p = new Node;
	p->data = e;
	cur->right = p;
	return true;
}

void CBinaryTree::pre_order(Node *cur)
{
	if (cur == nullptr)
	{
		return;
	}
	std::cout << cur->data << std::endl;
	pre_order(cur->left);
	pre_order(cur->right);
}

void CBinaryTree::in_order(Node *cur)
{
	if (cur == nullptr)
	{
		return;
	}
	in_order(cur->left);
	std::cout << cur->data << std::endl;
	in_order(cur->right);
}

void CBinaryTree::post_order(Node *cur)
{
	if (cur == nullptr)
	{
		return;
	}
	post_order(cur->left);
	post_order(cur->right);
	std::cout << cur->data << std::endl;
}

void CBinaryTree::pre_order_s(Node *cur)
{
	Stack *stack = CreateStack();
	while (cur || !IsEmpty(stack))
	{
		if (cur)
		{
			std::cout << cur->data << std::endl;
			Push(stack, cur);
			cur = cur->left;
		}
		else {
			cur =  Pop(stack);
			cur = cur->right;
		}
	}

}

void CBinaryTree::in_order_s(Node *cur)
{
	Stack *stack = CreateStack();
	while (cur || !IsEmpty(stack))
	{
		if (cur)
		{		
			Push(stack, cur);
			cur = cur->left;
		}
		else {
			cur = Pop(stack);
			std::cout << cur->data << std::endl;
			cur = cur->right;
		}	
	}
}

void CBinaryTree::post_order_s(Node *cur)
{
	Stack *stack = CreateStack();
	std::vector<Node*> v;
	Push(stack, cur);
	while (!IsEmpty(stack))
	{
		cur = Pop(stack);
		v.push_back(cur);
		if (cur->left)
			Push(stack, cur->left);
		if (cur->right)
			Push(stack, cur->right);
	}
	reverse(v.begin(), v.end());
	for (Node *p : v)
	{
		std::cout << p->data;
	}
}

void CBinaryTree::level_order(Node *cur)
{
	std::queue<Node * > q;
	if (!cur) return;
	q.push(cur);
	while (!q.empty())
	{
		Node *p = q.front();
		q.pop();
		std::cout << p->data;
		if (p->left)
		{
			q.push(p->left);
		}
		if (p->right)
		{
			q.push(p->right);
		}
	}
}

Node * CBinaryTree::find(Node *cur, ElemType e)
{
	if (cur == nullptr)
		return nullptr;
	
	if (cur->data == e)
	{
		return cur;
	}
	Node *p = find(cur->left, e);
	if (p == nullptr)
	{
		return find(cur->right, e);
	}
	return p;
}

void CBinaryTree::destroy(Node *cur)
{
	if (cur != nullptr)
	{
		destroy(cur->left);
		destroy(cur->right);
		delete cur;
	}
}



bool CBinaryTree::isempty()
{
	return root == nullptr;
}

Node * CBinaryTree::createTree()
{
	ElemType elem;
	Node *p;
	std::cin >> elem;
	if (elem == -9999)
	{
		p = nullptr;
	}
	else
	{
		p = new Node;
		p->data = elem;
		p->left = createTree();
		p->right = createTree();
	}
	return p;
}

int CBinaryTree::count(Node *cur)
{
	int ln, rn;
	if (cur == nullptr)
	{
		return 0;
	}
	ln = count(cur->left);
	rn = count(cur->right);
	return ln + rn + 1;
}

int CBinaryTree::height(Node *cur)
{
	if (cur == nullptr)
	{
		return 0;
	}
	else
	{
		return std::max(height(cur->left), height(cur->right)) + 1;
	}
}

// 初始化 
Stack* CreateStack() {
	Stack* p = (Stack*)new Stack;
	p->Next = nullptr;
	return p;
}

// 判断是否为空 
int IsEmpty(Stack* p) {
	return (p->Next == NULL);
}

// 入栈
void Push(Stack* p, Node *n) {
	Stack* tmp;
	tmp = (Stack*)new Stack;
	tmp->Data = n;
	// 链栈栈顶元素是链表头结点，新入栈的链表在栈顶元素后面 
	tmp->Next = p->Next;
	p->Next = tmp;
}

// 出栈
Node* Pop(Stack* S) {
	Stack* First;
	Node* TopVal;
	if (IsEmpty(S)) {
		std::cout << "stack empty" << std::endl;
		return NULL;
	}
	else {
		First = S->Next;   // 出栈第一个元素在栈顶元素后面 
		S->Next = First->Next;  //把第一个元素从链栈删除 
		TopVal = First->Data;   // 取出被删除结点的值 
		delete (First);  // 释放空间 
		return TopVal;
	}
}