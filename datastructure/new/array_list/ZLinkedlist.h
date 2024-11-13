#pragma once

//链表实现
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {
	}
};

//链表初始化
ListNode* listCreate(int num, ...);

//链表插入
void insert(ListNode* node, ListNode* P);

//链表删除
void remove(ListNode* node);

//链表访问
ListNode* access(ListNode* head, int index);

//链表查找
int find(ListNode* head, int target);

void print_LinkedList(ListNode * head);

void listFree(ListNode *lst);

void test_linkedlist();