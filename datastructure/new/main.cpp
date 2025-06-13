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
#include "Divide_Conquer/divide_conquer.h"
#include "Backtracking/preorder_traversal_compact.h"
#include "Backtracking/permutations.h"
#include "Backtracking/subset_sum.h"
#include "Backtracking/n_queens.h"
#include "dynamicprograming/climbing_stairs.h"
#include "dynamicprograming/minpath_sum.h"
#include "dynamicprograming/knapsack.h"
#include "dynamicprograming/coin_change.h"
#include "Greedy/coin_change.h"

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
	//test_divide_conquer();
	//test_buildtree();
	//test_hanota();
	//testPreOrder_traversal_compact();
	//testPermutations();
	//testSubsetsum();
	//testNqueens();
	//testClimbingStairs();
	//testMinPath();

	//testKnapsack();
	//test_coin_change();
	test_coinChange_greedy();

	getchar();
	return 0;
}