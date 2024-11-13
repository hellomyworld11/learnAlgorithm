#pragma once
#include "ArrayHashMap.h"

//哈希冲突解决:链地址法
class HashMapChaining
{
public:
	HashMapChaining();

	~HashMapChaining();

	int hashFunc(int key);

	double loadFactor();

	string get(int key);

	void put(int key, string val);

	void remove(int key);

	void extend();

	void print();

	static void test();
private:
	int size_;
	int capacity_;
	double loadthres_; //扩容的负载因子阈值
	int	extendRatio_; //扩容倍数
	vector<vector<Pair*>> buckets_;
};

