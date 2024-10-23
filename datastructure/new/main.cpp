#include "ZArray.h"
#include "ZLinkedlist.h"
#include "LinkedListStack.h"
#include "ArrayStack.h"
#include "LinkerListQueue.h"
#include "ArrayQueue.h"
#include "LinkedlistDeque.h"
#include "ArrayDeque.h"
#include "ArrayHashMap.h"
#include "HashMapChaining.h"
#include "HashMapOpenAddressing.h"

int main(int argc, char **argv)
{
	//ZArray::test();
	//test_linkedlist();
	//LinkedListStack::test();
	//ArrayStack::test();

	//LinkerListQueue::test();
	//ArrayQueue::test();
	//LinkedlistDeque::test();
	//ArrayDeque::test();
	//ArrayHashMap::test();
	//HashMapChaining::test();
	HashMapOpenAddressing::test();

	getchar();
	return 0;
}