#include "HashMapChaining.h"



HashMapChaining::HashMapChaining():size_(0),capacity_(4),loadthres_(2.0/3.0),extendRatio_(2)
{
	buckets_.resize(capacity_);
}


HashMapChaining::~HashMapChaining()
{
	for (auto &bucket : buckets_ )
	{
		for (auto *pair : bucket)
		{
			delete pair;
		}
	}
}

int HashMapChaining::hashFunc(int key)
{
	return key % capacity_;
}

double HashMapChaining::loadFactor()
{
	return (double)size_ / (double)capacity_;
}

std::string HashMapChaining::get(int key)
{
	int index = hashFunc(key);
	for (Pair *pair : buckets_[index])
	{
		if (pair->key == key)
		{
			return pair->val;
		}
	}
	return "";
}

void HashMapChaining::put(int key, string val)
{
	if (loadFactor() > loadthres_)
	{
		//
		extend();
	}
	int index = hashFunc(key);
	for (Pair *pair : buckets_[index])
	{
		if (pair->key == key)
		{
			pair->val = val;
			return;
		}
	}
	buckets_[index].push_back(new Pair(key, val));
	size_++;
}

void HashMapChaining::remove(int key)
{
	int index = hashFunc(key);
	auto &bucket = buckets_[index];
	for (size_t i = 0; i < bucket.size(); i++)
	{
		if (bucket[i]->key == key)
		{
			Pair *tmp = bucket[i];
			bucket.erase(bucket.begin() + i);
			delete tmp;
			size_--;
			return;
		}
	}
}

void HashMapChaining::extend()
{
	vector<vector<Pair *>> bucketsTmp = buckets_;
	capacity_ *= extendRatio_;
	buckets_.clear();
	buckets_.resize(capacity_);
	size_ = 0;
	for (auto& bucket : bucketsTmp )
	{
		for (Pair *pair : bucket)
		{
			put(pair->key, pair->val);
			delete pair;
		}
	}
}

void HashMapChaining::print()
{
	for (auto& bucket : buckets_)
	{
		cout << "[ ";
		for (Pair *pair : bucket)
		{
			cout << pair->key << "->" << pair->val << ", ";
		}
		cout << "]\n";
	}
}

void HashMapChaining::test()
{
	/* 初始化哈希表 */
	HashMapChaining map = HashMapChaining();

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
	string name = map.get(13276);
	cout << "\n输入学号 13276 ，查询到姓名 " << name << endl;

	/* 删除操作 */
	// 在哈希表中删除键值对 (key, value)
	map.remove(12836);
	cout << "\n删除 12836 后，哈希表为\nKey -> Value" << endl;
	map.print();
}
