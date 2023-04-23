#pragma once

typedef int ElemType;
typedef struct Node {
	ElemType data;
	Node *next = nullptr;
};

//��ʽջ
class CLinkStack
{
public:
	CLinkStack();
	~CLinkStack();
	void clear();
	bool isEmpty();
	bool push(ElemType elem);
	bool pop(ElemType &elem);
	bool gettop(ElemType &elem);
private:
	Node* top = nullptr;
};

