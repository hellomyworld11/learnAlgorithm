#pragma once


#define HASHSIZE 12			/* ����ɢ�б�Ϊ����ĳ��� */
#define NULLKEY -32768

int m = 0;					/* ɢ�б����ȫ�ֱ��� */


//��ϣ��

class HashTable
{
public:
	HashTable();
	~HashTable();

	/* ��ʼ��ɢ�б� */
	bool InitHashTable();
	/* ɢ�к��� */
	int Hash(int key);
	
	void InsertHash(int key);

	bool SearchHash(int key, int *addr);
private:
	int *_elem;       /* ����Ԫ�ش洢��ַ����̬�������� */
	int _count;       /* ��ǰ����Ԫ�ظ��� */
};

