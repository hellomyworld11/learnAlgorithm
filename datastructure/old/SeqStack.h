#pragma once

typedef int ElemType;
//Ë³ÐòÕ»
class CSeqStack
{
public:
	CSeqStack(int size = 100);
	~CSeqStack();
	
	bool isEmpty();
	int push(ElemType elem);
	int pop(ElemType &elem);
	int top(ElemType &elem);
private:
	ElemType *_base = nullptr; //Õ»µ×
	ElemType *_top = nullptr;  //Õ»¶¥
	int _size = 0;		
};

