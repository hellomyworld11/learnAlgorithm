#pragma once
#include "SequenList.h"

//��
//���ʣ�
// ���Ǿ����������ʵ���ȫ��������ÿ������ֵ�����ڻ���������Һ��ӽ���ֵ����Ϊ�󶥶�
// ����ÿ������ֵ��С�ڻ���������Һ��ӽ���ֵ����ΪС���ѡ�

class Heap
{
public:
	Heap();
	~Heap();


	void Sort(CSequenList *L);

	//�ѵ���
	void Adjust(CSequenList *L, int s, int m);
};

