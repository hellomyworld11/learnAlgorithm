#include "LoopQue.h"




CLoopQue::CLoopQue(int s /*= 100*/)
{
	base = new ElemType[s];
	front = 0;
	rear = 0;
	size = s;
}

CLoopQue::~CLoopQue()
{
	delete []base;
}

bool CLoopQue::empty_queue()
{
	return front == rear;
}

bool CLoopQue::en_queue(ElemType elem)
{
	if ((rear + 1)%size != front)//¶ÓÁÐ²»Âú
	{
		rear = (rear + 1) % size;
		base[rear] = elem;
		return true;
	}
	else
	{
		return false;
	}
}

bool CLoopQue::de_queue(ElemType &elem)
{
	if (rear != front)
	{
		front = (front + 1) % size;
		elem = base[front];
		return true;
	}
	return false;
}
