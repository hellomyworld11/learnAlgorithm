#pragma once

#include <iostream>
#include <vector>
//��
class CSeqString
{
public:
	CSeqString();
	CSeqString(char *s);
	CSeqString(const CSeqString& other);
	~CSeqString();

	//��ͨƥ��
	int strIndex_BF(int k, CSeqString &p);
	//KMPƥ�� ��ʡ���±�������
	int strIndex_KMP(int k,CSeqString &p);
	void get_next(char *t, std::vector<int>& next);
private:
	char *str = nullptr;
	int size = 0;
};

