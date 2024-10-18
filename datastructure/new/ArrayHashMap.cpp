#include "ArrayHashMap.h"
#include <iostream>


ArrayHashMap::ArrayHashMap()
{
	buckets_ = std::vector<Pair*>(100);
}


ArrayHashMap::~ArrayHashMap()
{
	for (auto& bucket : buckets_ )
	{
		delete bucket;
	}
	buckets_.clear();
}

int ArrayHashMap::hashFunc(int key)
{
	int index = key % 100;
	return index;
}

std::string ArrayHashMap::get(int key)
{
	int index = hashFunc(key) % buckets_.size();
	Pair *pair = buckets_[index];
	if (pair == nullptr)
	{
		return "";
	}
	return pair->val;
}

void ArrayHashMap::put(int key, string val)
{
	Pair *pair = new Pair(key, val);
	int index = hashFunc(key);
	buckets_[index] = pair;
}

void ArrayHashMap::remove(int key)
{
	int index = hashFunc(key);
	delete buckets_[index];
	buckets_[index] = nullptr;
}

std::vector<Pair *> ArrayHashMap::pairSet()
{
	return buckets_;
}

void ArrayHashMap::print()
{
	for (Pair* kv : buckets_)
	{
		if (kv != nullptr) 
			cout << kv->key << "->" << kv->val << endl;
	}
}

void ArrayHashMap::test()
{
	/* 初始化哈希表 */
	ArrayHashMap map = ArrayHashMap();

	/* 添加操作 */
	// 在哈希表中添加键值对 (key, value)
	map.put(12836, "小哈");
	map.put(15937, "小啰");
	map.put(16750, "小算");
	map.put(13276, "小法");
	map.put(10583, "小鸭");
	cout << "\n添加完成后，哈希表为\nKey -> Value" << endl;
	map.print();

	/* 查询操作 */
	// 向哈希表中输入键 key ，得到值 value
	string name = map.get(15937);
	cout << "\n输入学号 15937 ，查询到姓名 " << name << endl;

	/* 删除操作 */
	// 在哈希表中删除键值对 (key, value)
	map.remove(10583);
	cout << "\n删除 10583 后，哈希表为\nKey -> Value" << endl;
	map.print();

}
