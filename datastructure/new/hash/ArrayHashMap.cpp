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
	/* ��ʼ����ϣ�� */
	ArrayHashMap map = ArrayHashMap();

	/* ��Ӳ��� */
	// �ڹ�ϣ������Ӽ�ֵ�� (key, value)
	map.put(12836, "С��");
	map.put(15937, "С��");
	map.put(16750, "С��");
	map.put(13276, "С��");
	map.put(10583, "СѼ");
	cout << "\n�����ɺ󣬹�ϣ��Ϊ\nKey -> Value" << endl;
	map.print();

	/* ��ѯ���� */
	// ���ϣ��������� key ���õ�ֵ value
	string name = map.get(15937);
	cout << "\n����ѧ�� 15937 ����ѯ������ " << name << endl;

	/* ɾ������ */
	// �ڹ�ϣ����ɾ����ֵ�� (key, value)
	map.remove(10583);
	cout << "\nɾ�� 10583 �󣬹�ϣ��Ϊ\nKey -> Value" << endl;
	map.print();

}
