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
	//��ϣ����
	int hashFunc(int key);
	//ͨ������ȡֵ
	string get(int key);
	//���
	void put(int key, string val);
	//ɾ��
	void remove(int key);
	//��ȡ����
	vector<Pair *> pairSet();
	//��ӡ
	void print();

	static void test();
private:
	std::vector<Pair*> buckets_;

};

