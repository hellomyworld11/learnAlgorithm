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



// ��ʼ�� 
Stack* CreateStack() {
	Stack* p;
	p = (Stack)new[sizeof(struct SNode)];
	p->Next = nullptr;
	return p;
}

// �ж��Ƿ�Ϊ�� 
int IsEmpty(Stack* p) {
	return (p->Next == NULL);
}

// ��ջ
void Push(Stack* p, Node *n) {
	Stack* tmp;
	tmp = (Stack)new[sizeof(struct SNode)];
	tmp->Data = n;
	// ��ջջ��Ԫ��������ͷ��㣬����ջ��������ջ��Ԫ�غ��� 
	tmp->Next = p->Next;
	p->Next = tmp;
}

// ��ջ
Node* Pop(Stack* S) {
	Stack* First;
	Node* TopVal;
	if (IsEmpty(S)) {
		std::cout << "stack empty" << std::endl;
		return;
	}
	else {
		First = S->Next;   // ��ջ��һ��Ԫ����ջ��Ԫ�غ��� 
		S->Next = First->Next;  //�ѵ�һ��Ԫ�ش���ջɾ�� 
		TopVal = First->Data;   // ȡ����ɾ������ֵ 
		delete (First);  // �ͷſռ� 
		return TopVal;
	}
}