#pragma once
#include "../util.h"

//��  
class Heap
{
public:
	enum class Type
	{	
		Max,   //����
		Min    //��С��
	};

	Heap(Type type, vector<int> nums);

	~Heap();

	int peek();

	int left(int i);

	int right(int i);

	int parent(int i);

	int size();

	void push(int val);
	//�ӵ������ѻ�
	void siftUp(int i);

	void pop();
	//�Ӷ����׶ѻ�
	void siftDown(int i);

	bool isEmpty();

	void print() {
		cout << "�ѵ������ʾ��";
		printVector(heap_);
	}

	//���Ժ���
	static void test();

	//Ӧ��
	static void test_topk();

	static priority_queue<int, vector<int>, greater<int>> topKHeap(vector<int> &nums, int k);
private:
	void swap(int i, int j);
private:
	Type type_;
	vector<int> heap_;
};

