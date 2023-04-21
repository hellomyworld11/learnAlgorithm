#include "CArray.h"



CCArray::CCArray(unsigned int num) :
	size{0}, 
	capacity{0},
	p{nullptr}, 
	typesize{sizeof(ElemType)}
{
	alloc(num);
}


CCArray::~CCArray()
{
}

bool CCArray::alloc(unsigned int num)
{
	p = new ElemType[num]{0};
	if (p != nullptr)
	{
		capacity = num;
		return true;
	}
	else
	{
		return false;
	}	
}

int CCArray::insert(ElemType elem)
{
	int idx = 0;
	if (size >= capacity)
	{
		return -1;   //·ÖÅä¿Õ¼ä²»×ã
	}
	for (; idx < size; idx++)
	{
		if (p[idx] > elem)
		{
			break;
		}
	}
	if (idx < size)
	{
		memmove(&p[idx+1],&p[idx],(size - idx)*sizeof(int));
	}
	p[idx] = elem;
	size++;
	return idx;
}

int CCArray::del(int idx)
{
	if (idx < 0 || idx >= size)
	{
		return -1;
	}
	memmove(&p[idx], &p[idx + 1], (size - idx - 1)*sizeof(int));
	size--;
	return 0;
}

int CCArray::search(int val)
{
	for (int idx = 0; idx < size ; idx++)
	{
		if (p[idx] == val)
		{
			return idx;
		}
		if (p[idx] > val)
		{
			return -1;
		}
	}
	return -1;
}

int CCArray::update(int idx, int val)
{
	if (idx < 0 || idx > size)
	{
		return -1;
	}
	p[idx] = val;
	return 0;
}

void CCArray::print()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << p[i];
	}
	std::cout << std::endl;
}

