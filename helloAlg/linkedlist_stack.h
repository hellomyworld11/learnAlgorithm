#pragma once

typedef struct ListNode {
	int val;
	struct ListNode *next;
};

//¡¥±Ì µœ÷’ª  TODO
class LindedListStack {
private:
	ListNode *stackTop;  
	int		  stkSize;
public:
	LindedListStack() {
		stackTop = nullptr;
		stkSize = 0;
	}

};