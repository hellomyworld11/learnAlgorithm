#pragma once
#include <iostream>
#include <string>


class CCArray
{
public:
	typedef int ElemType;
public:
	CCArray(unsigned int num);
	~CCArray();
	bool  alloc(unsigned int num);
	int insert(ElemType elem);
	int del(int idx);
	int search(int val);
	int update(int idx, int val);
	void print();
private:
	size_t capacity;
	size_t size;
	size_t typesize;
	ElemType *p;
};





