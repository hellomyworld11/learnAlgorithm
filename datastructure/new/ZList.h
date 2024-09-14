#pragma once

//列表实现 


//列表类
class ZList
{
public:
	ZList();

	~ZList();

	int size();

	int capacity();

	int get(int index);

	int& operator[](const int index);

	void insert(int index, int num);

	void push_back(int num);

	int remove(int index);

	void extendCapacity();

	static void test();
private:
	int *arr_;
	int capacity_ = 10;
	int size_ = 0;
	int extendRatio = 2;
};

