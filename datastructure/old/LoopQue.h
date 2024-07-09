#pragma once

//—≠ª∑∂”¡–

typedef int ElemType;

class CLoopQue
{
public:
	CLoopQue(int s = 100);
	~CLoopQue();
	bool empty_queue();
	bool en_queue(ElemType elem);
	bool de_queue(ElemType &elem);
	bool front_queue(ElemType &elem);
private:
	ElemType *base;
	int front;
	int rear;
	int size;
};

