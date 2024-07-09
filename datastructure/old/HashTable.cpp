#include "HashTable.h"



HashTable::HashTable()
{
}


HashTable::~HashTable()
{
}

bool HashTable::InitHashTable()
{
	int i;
	m = HASHSIZE;
	this->_count = m;
	this->_elem = (int *)new int[m * sizeof(int)];
	for(i = 0; i < m; i++)
		this->_elem[i] = NULLKEY;
	return true;
}

int HashTable::Hash(int key)
{
	return key % m;  //³ýÁôÓàÊý·¨
}

void HashTable::InsertHash(int key)
{
	int addr = Hash(key);
	while (this->_elem[addr] != NULLKEY)
	{
		addr = (addr + 1) % m;
	}
	this->_elem[addr] = key;
}

bool HashTable::SearchHash(int key, int *addr)
{
	*addr = Hash(key);
	while (this->_elem[*addr] != key)
	{
		*addr = (*addr + 1) % m;
		if (this->_elem[*addr] == NULLKEY || *addr == Hash(key))
		{
			return false;
		}
	}
	true;
}
