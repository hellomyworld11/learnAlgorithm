#include "TestCArray.h"



CTestCArray::CTestCArray()
{
}


CTestCArray::~CTestCArray()
{
}

bool CTestCArray::run()
{
	CCArray aArray(5);
	aArray.print();
	
	aArray.insert(1);
	aArray.insert(2);
	aArray.insert(5);
	aArray.insert(4);
	aArray.print();
	std::cout << "========\n";
	aArray.del(1);
	aArray.update(0, 6);
	aArray.print();
	return true;
}
