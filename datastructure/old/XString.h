#pragma once

#include <iostream>
#include <vector>
//串
class CSeqString
{
public:
	CSeqString();
	CSeqString(char *s);
	CSeqString(const CSeqString& other);
	~CSeqString();

	//普通匹配
	int strIndex_BF(int k, CSeqString &p);
	//KMP匹配 节省重新遍历次数
	int strIndex_KMP(int k,CSeqString &p);
	void get_next(char *t, std::vector<int>& next);
private:
	char *str = nullptr;
	int size = 0;
};

