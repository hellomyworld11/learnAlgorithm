#pragma once

typedef int ElemType;
//˳��ջ
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
	ElemType *_base = nullptr; //ջ��
	ElemType *_top = nullptr;  //ջ��
	int _size = 0;		
};

