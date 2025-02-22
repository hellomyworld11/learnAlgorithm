#pragma once
#include "../util.h"

//≈≈–ÚÀ„∑®
class CSort
{
public:
	CSort()=default;

	~CSort()=default;

	//1.—°‘Ò≈≈–Ú
	void selectSort(vector<int>& nums);
	//2.√∞≈›≈≈–Ú
	void bubbleSort(vector<int>& nums);
	//3.≤Â»Î≈≈–Ú
	void insertSort(vector<int>& nums);

	static void test();

};

