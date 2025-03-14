#include "array_list/ZArray.h"
#include "array_list/ZLinkedlist.h"
#include "array_list/LinkedListStack.h"
#include "array_list/ArrayStack.h"
#include "array_list/LinkerListQueue.h"
#include "array_list/ArrayQueue.h"
#include "array_list/LinkedlistDeque.h"
#include "array_list/ArrayDeque.h"
#include "hash/ArrayHashMap.h"
#include "hash/HashMapChaining.h"
#include "hash/HashMapOpenAddressing.h"
#include "tree/binary_tree.h"
#include "tree/ArrayBinaryTree.h"
#include "tree/BinarySearchTree.h"
#include "tree/AVLTree.h"
#include "heap/Heap.h"
#include "graph/GraphAdjMat.h"
#include "graph/GraphAdjList.h"
#include "searching/Searching.h"
#include "sort/Sort.h"
#include "Divide_Conquer/binary_search_recur.h"

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
	//HashMapOpenAddressing::test();

	//test1();
	//ArrayBinaryTree::test();
	//BinarySearchTree::test();
	//AVLTree::test();
	//Heap::test_topk();
	//GraphAdjMat::test();
	//GraphAdjList::test();
	//GraphAdjList::test_bfs();
	//GraphAdjList::test_dfs();
	//CSearching::test();
	//CSort::test();
	test_divide_conquer();

	getchar();
	return 0;
}