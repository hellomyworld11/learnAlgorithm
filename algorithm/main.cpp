
#include <iostream>
#include "UtilSort.h"



int main()
{
	vector<int> arr = {5, 4, 4, 0, 6};
	//BubbleSort(arr);
	QuickSort(arr);
	PrintVec(arr);
	system("pause");
	return 0;
}