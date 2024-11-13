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
	// ��ʼ����ϣ��
	HashMapOpenAddressing hashmap;

	// ��Ӳ���
	// �ڹ�ϣ������Ӽ�ֵ�� (key, val)
	hashmap.put(12836, "С��");
	hashmap.put(15937, "С��");
	hashmap.put(16750, "С��");
	hashmap.put(13276, "С��");
	hashmap.put(10583, "СѼ");
	cout << "\n�����ɺ󣬹�ϣ��Ϊ\nKey -> Value" << endl;
	hashmap.print();

	// ��ѯ����
	// ���ϣ��������� key ���õ�ֵ val
	string name = hashmap.get(13276);
	cout << "\n����ѧ�� 13276 ����ѯ������ " << name << endl;

	// ɾ������
	// �ڹ�ϣ����ɾ����ֵ�� (key, val)
	hashmap.remove(16750);
	cout << "\nɾ�� 16750 �󣬹�ϣ��Ϊ\nKey -> Value" << endl;
	hashmap.print();

	hashmap.remove(15937);
	cout << "\nɾ�� 15937 �󣬹�ϣ��Ϊ\nKey -> Value" << endl;
	hashmap.print();

	hashmap.put(13111, "С��");
	cout << "\n���� 13111 �󣬹�ϣ��Ϊ\nKey -> Value" << endl;
	hashmap.print();
}
