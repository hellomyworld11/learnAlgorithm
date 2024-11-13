#include "HashMapOpenAddressing.h"



HashMapOpenAddressing::HashMapOpenAddressing():size_(0), buckets_(capacity_, nullptr)
{
}


HashMapOpenAddressing::~HashMapOpenAddressing()
{
	for (Pair *pair: buckets_)
	{
		if (pair != nullptr && pair != TOMBSTONE)
		{
			delete pair;
		}
	}
	delete TOMBSTONE;
}

int HashMapOpenAddressing::hashFunc(int key)
{
	return key % capacity_;
}

double HashMapOpenAddressing::loadFactor()
{
	return (double)size_ / capacity_;
}

int HashMapOpenAddressing::findBucket(int key)
{
	int index = hashFunc(key);
	int firstTombstone = -1;
	while (buckets_[index] != nullptr)
	{
		if (buckets_[index]->key == key)
		{
			if (firstTombstone != -1)
			{
				buckets_[firstTombstone] = buckets_[index];
				buckets_[index] = TOMBSTONE;
				return firstTombstone;
			}
			return index;
		}
		if (firstTombstone == -1 && buckets_[index] == TOMBSTONE)
		{
			firstTombstone = index;
		}
		index = (index + 1) % capacity_;
	}
	return firstTombstone == -1 ? index : firstTombstone;
}

std::string HashMapOpenAddressing::get(int key)
{
	int index = findBucket(key);
	if (buckets_[index] != nullptr && buckets_[index] != TOMBSTONE)
	{
		return buckets_[index]->val;
	}
	return "";
}

void HashMapOpenAddressing::put(int key, string val)
{
	if (loadFactor() > loadThres_)
	{
		extend();
	}
	int index = findBucket(key);
	if (buckets_[index] != nullptr && buckets_[index] != TOMBSTONE)
	{
		buckets_[index]->val = val;
		return;
	}
	buckets_[index] = new Pair(key ,val);
	size_++;
}

void HashMapOpenAddressing::remove(int key)
{
	int index = hashFunc(key);
	if (buckets_[index] != nullptr && buckets_[index] != TOMBSTONE)
	{
		delete buckets_[index];
		buckets_[index] = TOMBSTONE;
		size_--;
	}
}

void HashMapOpenAddressing::extend()
{
	vector<Pair*> bucketTmp = buckets_;
	capacity_ *= extendRatio_;
	buckets_ = vector<Pair*>(capacity_, nullptr);
	size_ = 0;
	for (Pair *pair : bucketTmp)
	{
		if (pair != nullptr && pair != TOMBSTONE)
		{
			put(pair->key, pair->val);
			delete pair;
		}
	}
}

void HashMapOpenAddressing::print()
{
	for (Pair *pair : buckets_)
	{
		if (pair == nullptr)
		{
			cout << "nullptr" << endl;
		}
		else if (pair == TOMBSTONE)
		{
			cout << "TOMBSTONE" << endl;
		}
		else {
			cout << pair->key << "->" << pair->val << endl;
		}
	}
}

void HashMapOpenAddressing::test()
{
	// 初始化哈希表
	HashMapOpenAddressing hashmap;

	// 添加操作
	// 在哈希表中添加键值对 (key, val)
	hashmap.put(12836, "小哈");
	hashmap.put(15937, "小啰");
	hashmap.put(16750, "小算");
	hashmap.put(13276, "小法");
	hashmap.put(10583, "小鸭");
	cout << "\n添加完成后，哈希表为\nKey -> Value" << endl;
	hashmap.print();

	// 查询操作
	// 向哈希表中输入键 key ，得到值 val
	string name = hashmap.get(13276);
	cout << "\n输入学号 13276 ，查询到姓名 " << name << endl;

	// 删除操作
	// 在哈希表中删除键值对 (key, val)
	hashmap.remove(16750);
	cout << "\n删除 16750 后，哈希表为\nKey -> Value" << endl;
	hashmap.print();

	hashmap.remove(15937);
	cout << "\n删除 15937 后，哈希表为\nKey -> Value" << endl;
	hashmap.print();

	hashmap.put(13111, "小旭");
	cout << "\n增加 13111 后，哈希表为\nKey -> Value" << endl;
	hashmap.print();
}
