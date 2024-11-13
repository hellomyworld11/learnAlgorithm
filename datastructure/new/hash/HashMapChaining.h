#pragma once
#include "ArrayHashMap.h"

//��ϣ��ͻ���:����ַ��
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
	double loadthres_; //���ݵĸ���������ֵ
	int	extendRatio_; //���ݱ���
	vector<vector<Pair*>> buckets_;
};

