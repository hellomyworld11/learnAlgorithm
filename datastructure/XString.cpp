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
	char *s = str + k - 1;  //����
	char *t = p.str;        //�ִ�
	int pos = k;
	if (k < 1 || k > size)
	{
		std::cout << "out of bound" << std::endl;
	}
	while (*t != '\0' && *s != '\0')
	{
		if (*s != *t)
		{
			t = p.str;				//�ִ�ƥ��λ���� ��ͷ��ʼһλһλ�Ƚ�
			s = str + (++pos) - 1;  //������ʼƥ��λ�����ƶ�
		}
		else
		{
			++t;
			++s;
		}
	}
	if (*t == '\0')  //�ִ�������˵����ͬ�� 
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
	int i = k - 1;   //k �� 1 �� i = 0  �����±�
	int j = 0;       //�ִ��±�
	int m = size;    // ������С
	int n = p.size;  // �Ӵ���С
	std::vector<int> next;
	get_next(p.str,next); //��ȡnext����
	while (i < m && j < n)//��û������
	{
		if (j == 0 || str[i] == p.str[j])  
		{
			i++;				
			j++;
		}
		else
		{
			j = next[j];  //����λ��
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
			j = next[j];  //��תλ��
		}
	}
}
