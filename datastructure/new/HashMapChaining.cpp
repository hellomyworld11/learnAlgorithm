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
