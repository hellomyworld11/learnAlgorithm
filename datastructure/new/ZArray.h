#pragma once
#include <iostream>
#include <assert.h>

#define BUFSIZE 64

//数组类
class ZArray
{
public:
	ZArray(int size = 10);
	~ZArray();

	//插入
	void insert(int index, int num);
	//访问
	int& operator[](const int index);
	//查找
	int find(int num);
	//删除
	void remove(int index);

	int length() { return size_; };

	static void test();
private:
	int *p;
	int size_;
	int capacity_;
};

