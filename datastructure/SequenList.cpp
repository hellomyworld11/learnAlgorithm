#include "SequenList.h"



void CSequenList::init()
{
	len = 0;
}

int CSequenList::length()
{
	return len;
}

int CSequenList::insert(ElemType elem, int i)
{
	//  1 2 3 4 5
	if (len >= MaxSize)
	{
		return -1;
	}
	if (i < 0 || i > len)
	{
		return -1;
	}
	for (int j = len; j > i; j--)
	{
		datas[j] = datas[j - 1];
	}
	datas[i] = elem;
	len++;
	return 0;
}

int CSequenList::deleted(int i)
{
	// 1 2 3 4 5
	if (len == 0)
	{
		return -1;
	}
	if (i < 0 || i >= len)
	{
		return -1;
	}
	for (int j = i+1; j < len; j++)
	{
		datas[j-1] = datas[j];
	}
	len--;
	return 0;
}

ElemType CSequenList::get(int i)
{
	if (i < 0 || i >= len)
	{
		return ;
	}
	return datas[i];
}

int CSequenList::find(ElemType elem)
{
	for (int j = 0; j < len; j++)
	{
		if (elem ==  datas[j])
		{
			return j;
		}
	}
	return -1;
}
