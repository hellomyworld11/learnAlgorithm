#include "XString.h"



CSeqString::CSeqString()
{
	size = 1;
	str = new char[size];
	if (str == nullptr)
	{
		std::cout << "new error" << std::endl;
		exit(1);
	}
	str[0] = '\0';
}


CSeqString::CSeqString(char *s)
{
	size = strlen(s) + 1;
	str = new char[size];
	if (str == nullptr)
	{
		std::cout << "new error" << std::endl;
		exit(1);
	}
	strcpy_s(str,size,s);
}

CSeqString::CSeqString(const CSeqString& other)
{
	size = other.size;
	str = new char[size];
	if (str == nullptr)
	{
		std::cout << "new error" << std::endl;
		exit(1);
	}
	strcpy_s(str, size, other.str);
}

CSeqString::~CSeqString()
{
	delete str;
}

int CSeqString::strIndex_BF(int k, CSeqString &p)
{
	char *s = str + k - 1;  //主串
	char *t = p.str;        //字串
	int pos = k;
	if (k < 1 || k > size)
	{
		std::cout << "out of bound" << std::endl;
	}
	while (*t != '\0' && *s != '\0')
	{
		if (*s != *t)
		{
			t = p.str;				//字串匹配位重置 从头开始一位一位比较
			s = str + (++pos) - 1;  //主串起始匹配位往后移动
		}
		else
		{
			++t;
			++s;
		}
	}
	if (*t == '\0')  //字串遍历完说明相同了 
	{
		return pos;
	}
	else
	{
		return -1;
	}
}
// a b a b a b a b c a
// a b a b a b c a
int CSeqString::strIndex_KMP(int k, CSeqString &p)
{
	int i = k - 1;   //k 设 1 则 i = 0  主串下标
	int j = 0;       //字串下标
	int m = size;    // 主串大小
	int n = p.size;  // 子串大小
	std::vector<int> next;
	get_next(p.str,next); //获取next数组
	while (i < m && j < n)//都没遍历完
	{
		if (j == 0 || str[i] == p.str[j])  
		{
			i++;				
			j++;
		}
		else
		{
			j = next[j];  //回溯位置
		}
	}
	return (j == m) ? i - m : -1;
}
//t		a b a b a b c a
//j		0 1 2 3 4 5 6 7 
//pmt	0 0 1 2 3 4 0 1
//next -1 0 0 1 2 3 4 0
void CSeqString::get_next(char *t, std::vector<int>& next)
{
	int i = 1, j = 0;
	int len = strlen(t); 
	next.resize(len+1);
	next[1] = 0;
	while (i < len)
	{
		if (j == 0 || t[i] == t[j])
		{
			++i;
			++j;
			next[i] = j;     //
		}
		else
		{
			j = next[j];  //跳转位置
		}
	}
}
