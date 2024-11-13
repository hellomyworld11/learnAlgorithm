#pragma once

//����ʵ��
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {
	}
};

//�����ʼ��
ListNode* listCreate(int num, ...);

//�������
void insert(ListNode* node, ListNode* P);

//����ɾ��
void remove(ListNode* node);

//�������
ListNode* access(ListNode* head, int index);

//�������
int find(ListNode* head, int target);

void print_LinkedList(ListNode * head);

void listFree(ListNode *lst);

void test_linkedlist();