#include "ZArray.h"



ZArray::ZArray(int size):size_(size),
	capacity_(size)
{
	p = new int[size] {0};
	assert(p != nullptr);
}


ZArray::~ZArray()
{
	delete[] p;
	p = nullptr;
}

void ZArray::insert(int index, int num)
{
	//size不够重新分配
	if (size_ + 1 > capacity_)
	{
		capacity_ = size_ + BUFSIZE;
		int *pNew = new int[capacity_] {0};
		assert(pNew != nullptr);
		memcpy(pNew, p, size_*sizeof(int));
		delete[] p;
		p = pNew;
	}
	//往后移动
	for (int i = size_ - 1; i >= index; i--)
	{
		p[i + 1] = p[i];
	}
	p[index] = num;
	size_++;
}

int& ZArray::operator[](const int index)
{
	assert(index >= 0 && index < size_);
	return p[index];
}

int ZArray::find(int num)
{
	for (int i = 0; i < size_; i++)
	{
		if (p[i] == num)
		{
			return i;
		}
	}
	return -1;
}

void ZArray::remove(int index)
{
	if (size_ == 0
		|| index < 0 || index >= size_
		)
	{
		return ;
	}

	for (int i = index; i < size_; i++)
	{
		p[i] = p[i + 1];
	}
	size_--;
}

void ZArray::test()
{
	using namespace std;
	ZArray obj;
	for (int i = 0; i < obj.length(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << "********\n";

	obj.insert(3, 5);
	obj.insert(9, 2);
	obj[3] = 4;

	for (int i = 0; i < obj.length(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << "********\n";
	obj.remove(2);

	for (int i = 0; i < obj.length(); i++)
	{
		cout << obj[i] << " ";
	}
	cout << endl;

}
