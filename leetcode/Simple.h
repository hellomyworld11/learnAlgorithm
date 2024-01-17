#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Simple
{
public:
	Simple();
	~Simple();

public:
	//485
	int findMaxConsecutiveOnes(vector<int>& nums);
	//283
	void moveZeroes(vector<int>& nums);
	//27 
	int removeElement(vector<int>& nums, int val);
};

