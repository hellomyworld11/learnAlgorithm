#include "Heap.h"



Heap::Heap(Type type, vector<int> nums):type_(type)
{
	heap_ = nums;
	// ���ѣ��������� �ѻ���Ҷ�ڵ�������������нڵ� 
	for (int i = parent(size() - 1); i >= 0; i--) {		
		siftDown(i);	
	}
}


Heap::~Heap()
{
}

int Heap::peek()
{
	return heap_[0];
}

int Heap::left(int i)
{
	return 2 * i + 1;
}

int Heap::right(int i)
{
	return 2 * i + 2;
}

int Heap::parent(int i)
{
	return (i - 1) / 2;
}

int Heap::size()
{
	return heap_.size();
}

void Heap::push(int val)
{
	heap_.push_back(val);
	siftUp(size() - 1);
}

void Heap::siftUp(int i)
{
	while (true)
	{
		int p = parent(i);
		if ( p < 0 )
		{
			break;
		}
		if (type_ == Type::Max)
		{
			if (heap_[p] >= heap_[i])
			{
				break;
			}
		}
		else if (type_ == Type::Min)
		{
			if (heap_[p] <= heap_[i])
			{
				break;
			}
		}
	
		swap(p, i);
		i = p;
	}
}

void Heap::pop()
{
	if (size() == 0)
	{
		throw out_of_range("��״̬Ϊ��");
	}
	//�����ѵ׺ͶѶ�
	swap(0, size()-1);
	//ɾ�����һ��
	heap_.pop_back();	
	siftDown(0);
}

void Heap::siftDown(int i)
{
	while (true)
	{
		int l = left(i);
		int r = right(i);
		int m = i;

		
		if (l < size() )
		{
			if (type_ == Type::Max)
			{
				if (heap_[l] > heap_[m])
				{
					m = l;
				}
			}
			else {
				if (heap_[l] < heap_[m])
				{
					m = l;
				}
			}	
		}

		if (r < size()  )
		{
			if (type_ == Type::Max)
			{
				if (heap_[r] > heap_[m])
				{
					m = r;
				}
			}
			else {
				if (heap_[r] < heap_[m])
				{
					m = r;
				}
			}
		}

		if (m == i) break;

		swap(m, i);

		i = m;
	}
}

bool Heap::isEmpty()
{
	return heap_.empty();
}

void Heap::swap(int i, int j)
{
	int temp = heap_[i];
	heap_[i] = heap_[j];
	heap_[j] = temp;
}

void Heap::test()
{
	/* ��ʼ���󶥶� */
	vector<int> vec{ 9, 8, 6, 6, 7, 5, 2, 1, 4, 3, 6, 2 };
	Heap maxHeap(Heap::Type::Min, vec);
	cout << "\n�����б����Ѻ�" << endl;
	maxHeap.print();

	/* ��ȡ�Ѷ�Ԫ�� */
	int peek = maxHeap.peek();
	cout << "\n�Ѷ�Ԫ��Ϊ " << peek << endl;

	/* Ԫ����� */
	int val = 7;
	maxHeap.push(val);
	cout << "\nԪ�� " << val << " ��Ѻ�" << endl;
	maxHeap.print();

	/* �Ѷ�Ԫ�س��� */
	peek = maxHeap.peek();
	maxHeap.pop();
	cout << "\n�Ѷ�Ԫ�� " << peek << " ���Ѻ�" << endl;
	maxHeap.print();

	/* ��ȡ�Ѵ�С */
	int size = maxHeap.size();
	cout << "\n��Ԫ������Ϊ " << size << endl;

	/* �ж϶��Ƿ�Ϊ�� */
	bool isEmpty = maxHeap.isEmpty();
	cout << "\n���Ƿ�Ϊ�� " << isEmpty << endl;

}

void Heap::test_topk()
{
	vector<int> nums = { 1, 7, 6, 3, 2 };
	int k = 3;

	priority_queue<int, vector<int>, greater<int>> res = topKHeap(nums, k);
	cout << "���� " << k << " ��Ԫ��Ϊ: ";

	while (!res.empty()) {
		cout << res.top() << endl;
		//cout<<pq.top().x<<" "<<pq.top().y<<endl;
		res.pop();
	}
}

std::priority_queue<int, std::vector<int>, std::greater<int>> Heap::topKHeap(vector<int> &nums, int k)
{
	priority_queue<int, vector<int>, greater<int>> minheap;
	//�����ǰk��Ԫ�طŽ�ȥ
	for (int i = 0; i < k; i++)
	{
		minheap.push(nums[i]);
	}

	//�����������ͶѶ����бȽ�
	for (int i = k; i < nums.size(); i++)
	{
		if (nums[i] > minheap.top())
		{
			minheap.pop();
			minheap.push(nums[i]);
		}
	}

	return minheap;
}