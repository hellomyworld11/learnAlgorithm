#pragma once
#include <iostream>
#include <assert.h>

#define BUFSIZE 64

//������
class ZArray
{
public:
	ZArray(int size = 10);
	~ZArray();

	//����
	void insert(int index, int num);
	//����
	int& operator[](const int index);
	//����
	int find(int num);
	//ɾ��
	void remove(int index);

	int length() { return size_; };

	static void test();
private:
	int *p;
	int size_;
	int capacity_;
};

