#pragma once

#include <string>
#include <vector>
using namespace std;

struct	Pair {
public:
	int key;
	std::string val;
	Pair(int key, std::string val){
		this->key = key;
		this->val = val;
	}

};

class ArrayHashMap
{
public:
	ArrayHashMap();

	~ArrayHashMap();
	//哈希函数
	int hashFunc(int key);
	//通过键获取值
	string get(int key);
	//添加
	void put(int key, string val);
	//删除
	void remove(int key);
	//获取所有
	vector<Pair *> pairSet();
	//打印
	void print();

	static void test();
private:
	std::vector<Pair*> buckets_;

};

