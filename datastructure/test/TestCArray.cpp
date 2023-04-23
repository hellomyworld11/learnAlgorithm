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
// 	aArray[-1] = 1;
// 	aArray[0] = 1;
// 	aArray[3] = 2;
// 	std::cout << aArray[3];
	aArray.print();
	return true;
}
