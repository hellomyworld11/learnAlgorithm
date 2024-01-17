#include <iostream>
#include "Simple.h"

int main(int argc, char *argv[])
{
	Simple simple;
	vector<int> v = { 3,2,2,3 };

	int ret = simple.removeElement(v, 2);
	cout << "col : " << ret << endl;

	getchar();
	return 0;
}