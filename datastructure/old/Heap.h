#pragma once
#include "SequenList.h"

//堆
//性质：
// 堆是具有下列性质的完全二叉树：每个结点的值都大于或等于其左右孩子结点的值，称为大顶堆
// 或者每个结点的值都小于或等于其左右孩子结点的值，称为小顶堆。

class Heap
{
public:
	Heap();
	~Heap();


	void Sort(CSequenList *L);

	//堆调整
	void Adjust(CSequenList *L, int s, int m);
};

