#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Simple
{
public:
	
public:
	Simple();
	~Simple();

public:
	//数组相关
	//485
	int findMaxConsecutiveOnes(vector<int>& nums);
	//283
	void moveZeroes(vector<int>& nums);
	//27 
	int removeElement(vector<int>& nums, int val);
	//链表
	//19
	ListNode* removeNthFromEnd(ListNode* head, int n);

};

