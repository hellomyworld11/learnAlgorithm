#pragma once
//���Ա�˳��洢�ṹ

const int MaxSize = 100;
typedef int ElemType;

class CSequenList
{
public:
	void init();
	int length();
	int insert(ElemType elem,int i);
	int deleted(int i);
	int find(ElemType elem);
	ElemType get(int i);
private:
	ElemType datas[MaxSize];
	int len;
};

