#pragma once


#define HASHSIZE 12			/* 定义散列表长为数组的长度 */
#define NULLKEY -32768

int m = 0;					/* 散列表表长，全局变量 */


//哈希表

class HashTable
{
public:
	HashTable();
	~HashTable();

	/* 初始化散列表 */
	bool InitHashTable();
	/* 散列函数 */
	int Hash(int key);
	
	void InsertHash(int key);

	bool SearchHash(int key, int *addr);
private:
	int *_elem;       /* 数据元素存储基址，动态分配数组 */
	int _count;       /* 当前数据元素个数 */
};

