#include <iostream>
#include "Simple.h"

void CreateListNode(ListNode*& list)
{
	list = new ListNode(1);
	ListNode* list1 = new ListNode(2);
	ListNode* list2 = new ListNode(3);
	ListNode* list3 = new ListNode(4);
	//ListNode* list4 = new ListNode(5);
	list->next = list1;
	list1->next = list2;
	list2->next = list3;
 	list3->next = nullptr;
}

void PrintList(ListNode* list)
{
	while (list)
	{
		cout << " " << list->val << " ";
		list = list->next;
	}
}




int main(int argc, char *argv[])
{
	Simple simple;
	vector<int> v = { 3,2,2,3 };

	//int ret = simple.removeElement(v, 2);
	ListNode *list;
	CreateListNode(list);
	PrintList(simple.swapPairs(list));

	getchar();
	return 0;
}