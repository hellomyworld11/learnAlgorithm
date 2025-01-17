#pragma once
#include "../util.h"

//堆  
class Heap
{
public:
	enum class Type
	{	
		Max,   //最大堆
		Min    //最小堆
	};

	Heap(Type type, vector<int> nums);

	~Heap();

	int peek();

	int left(int i);

	int right(int i);

	int parent(int i);

	int size();

	void push(int val);
	//从底至顶堆化
	void siftUp(int i);

	void pop();
	//从顶至底堆化
	void siftDown(int i);

	bool isEmpty();

	void print() {
		cout << "堆的数组表示：";
		printVector(heap_);
	}

	//测试函数
	static void test();

	//应用
	static void test_topk();

	static priority_queue<int, vector<int>, greater<int>> topKHeap(vector<int> &nums, int k);
private:
	void swap(int i, int j);
private:
	Type type_;
	vector<int> heap_;
};

