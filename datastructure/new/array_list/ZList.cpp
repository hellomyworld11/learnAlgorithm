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
		throw std::out_of_range("����Խ��");
	return arr_[index];
}

int& ZList::operator[](const int index)
{
	if (index < 0 || index >= size())
		throw std::out_of_range("����Խ��");

	return arr_[index];
}

void ZList::insert(int index, int num)
{
	if (index < 0 || index >= size())
		throw std::out_of_range("����Խ��");
	// Ԫ��������������ʱ���������ݻ���
	if (size() == capacity())
		extendCapacity();
	// ������ index �Լ�֮���Ԫ�ض�����ƶ�һλ
	for (int j = size() - 1; j >= index; j--) {
		arr_[j + 1] = arr_[j];
	}
	arr_[index] = num;
	// ����Ԫ������
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
		throw std::out_of_range("����Խ��");
	int num = arr_[index];
	// ������ index ֮���Ԫ�ض���ǰ�ƶ�һλ
	for (int j = index; j < size() - 1; j++) {
		arr_[j] = arr_[j + 1];
	}
	// ����Ԫ������
	size_--;
	// ���ر�ɾ����Ԫ��
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
