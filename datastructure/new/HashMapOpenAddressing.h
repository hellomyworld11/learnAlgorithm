#pragma once
#include "ArrayHashMap.h"

//哈希冲突:开放地址法
class HashMapOpenAddressing
{
public:
	HashMapOpenAddressing();

	~HashMapOpenAddressing();

	int hashFunc(int key);

	double loadFactor();

	int findBucket(int key);

	string get(int key);

	void put(int key, string val);

	void remove(int key);

	void extend();

	void print();

	static void test();
private:
	int capacity_ = 4;	
	int size_;
	const double loadThres_ = 2.0 / 3.0;
	const int extendRatio_ = 2;
	vector<Pair *> buckets_;
	Pair* TOMBSTONE = new Pair(-1, "-1");
};

