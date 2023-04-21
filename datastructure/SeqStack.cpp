#include "SeqStack.h"





CSeqStack::CSeqStack(int size /*= 100*/)
{
	_base = new ElemType[size];
	_top = _base;
	_size = size;
}

CSeqStack::~CSeqStack()
{
	delete[] _base;
	_top = nullptr;
	_base = nullptr;
}

bool CSeqStack::isEmpty()
{
	return _top <= _base;
}



int CSeqStack::push(ElemType elem)
{
	if (_top - _base < _size)
	{
		*_top = elem;
		_top++;
		return 0;
	}
	return -1;
}

int CSeqStack::pop(ElemType &elem)
{
	if (_top > _base)
	{
		_top--;
		elem = *_top;
		return 0;
	}
	else {
		return -1;
	}
}

int CSeqStack::top(ElemType &elem)
{
	if (_top > _base)
	{
		elem = *(_top - 1);
		return 0;
	}
	else {
		return -1;
	}
}
