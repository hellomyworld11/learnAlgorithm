#include "ZLinkedlist.h"
#include "../util.h"

ListNode* listCreate(int num, ...)
{
	va_list arg;
	va_start(arg, num);

	ListNode *head = nullptr;
	ListNode *p = nullptr;
	int val;
	for (int i = 0; i < num; i++)
	{
		val = va_arg(arg, int);
		ListNode *pNode = new ListNode(val);
		if (head == nullptr)
		{
			head = pNode;
			p = head;
		}
		else {
			p->next = pNode;
			p = pNode;
		}
	}
	va_end(arg);

	return head;
}

void insert(ListNode* node, ListNode* P)
{
	P->next = node->next;
	node->next = P;
}

void remove(ListNode* node)
{
	if (node->next == nullptr)	return;

	ListNode *tmp = node->next;
	node->next = tmp->next;
	delete tmp;
}

ListNode* access(ListNode* head, int index)
{
	for (int i = 0; i < index; i++) {
		if (head == nullptr)
			return nullptr;
		head = head->next;
	}
	return head;
}

int find(ListNode* head, int target)
{
	int index = 0;
	while (head != nullptr) {
		if (head->val == target)
			return index;
		head = head->next;
		index++;
	}
	return -1;
}

void print_LinkedList(ListNode * head)
{
	std::cout << " [ ";
	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << " ] " << std::endl;
}

void listFree(ListNode *lst)
{
	// �ͷ��ڴ�
	ListNode *pre;
	while (lst != nullptr) {
		pre = lst;
		lst = lst->next;
		delete pre;
	}
}

void test_linkedlist()
{
	ListNode *lst = listCreate(5, 1, 2, 3, 4, 5);

	std::cout << "��ʼ��������Ϊ" << std::endl;
	print_LinkedList(lst);

	insert(lst, new ListNode(6));
	std::cout << "����ڵ�������Ϊ" << std::endl;
	print_LinkedList(lst);

	remove(lst);
	std::cout << "ɾ���ڵ�������Ϊ" << std::endl;
	print_LinkedList(lst);

	ListNode *node = access(lst, 3);
	std::cout << "���������� 3 ���Ľڵ��ֵ = " << node->val << std::endl;


	/* ���ҽڵ� */
	int index = find(lst, 2);
	std::cout << "������ֵΪ 2 �Ľڵ������ = " << index << std::endl;

	listFree(lst);
}
