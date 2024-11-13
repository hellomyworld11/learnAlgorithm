#include "ZList.h"
#include "../util.h"

ZList::ZList()
{
	arr_ = new int[capacity_];
}


ZList::~ZList()
{
	delete[] arr_;
}

int ZList::size()
{
	return size_;
}

int ZList::capacity()
{
	return capacity_;
}

int ZList::get(int index)
{
	if (index < 0 || index >= size())
		throw std::out_of_range("索引越界");
	return arr_[index];
}

int& ZList::operator[](const int index)
{
	if (index < 0 || index >= size())
		throw std::out_of_range("索引越界");

	return arr_[index];
}

void ZList::insert(int index, int num)
{
	if (index < 0 || index >= size())
		throw std::out_of_range("索引越界");
	// 元素数量超出容量时，触发扩容机制
	if (size() == capacity())
		extendCapacity();
	// 将索引 index 以及之后的元素都向后移动一位
	for (int j = size() - 1; j >= index; j--) {
		arr_[j + 1] = arr_[j];
	}
	arr_[index] = num;
	// 更新元素数量
	size_++;
}

void ZList::push_back(int num)
{
	if (size() == capacity())
	{
		extendCapacity();
	}
	arr_[size()] = num;
	size_++;
}

int ZList::remove(int index)
{
	if (index < 0 || index >= size())
		throw std::out_of_range("索引越界");
	int num = arr_[index];
	// 将索引 index 之后的元素都向前移动一位
	for (int j = index; j < size() - 1; j++) {
		arr_[j] = arr_[j + 1];
	}
	// 更新元素数量
	size_--;
	// 返回被删除的元素
	return num;
}

void ZList::extendCapacity()
{
	int newCapacity = capacity() * extendRatio;

	int *tmp = arr_;

	arr_ = new int[newCapacity];

	for (int i = 0; i < size(); i++)
	{
		arr_[i] = tmp[i];
	}
	delete[] tmp;
	capacity_ = newCapacity;
}

void ZList::test()
{
	//
}
