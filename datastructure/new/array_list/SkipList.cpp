#include "SkipList.h"




int testSkipList() {
	// 创建跳表实例
	SkipList<int, std::string> skipList(8, 0.5);

	// 插入一些数据
	skipList.insert(3, "Three");
	skipList.insert(6, "Six");
	skipList.insert(7, "Seven");
	skipList.insert(9, "Nine");
	skipList.insert(12, "Twelve");
	skipList.insert(19, "Nineteen");
	skipList.insert(17, "Seventeen");

	std::cout << "=== 插入后的跳表 ===" << std::endl;
	skipList.display();

	// 查找数据
	std::string value;
	if (skipList.find(7, value)) {
		std::cout << "找到键 7: " << value << std::endl;
	}

	if (skipList.find(19, value)) {
		std::cout << "找到键 10: " << value << std::endl;
	}
	else {
		std::cout << "键 10 不存在" << std::endl;
	}

	// 更新数据
	skipList.insert(7, "Seven Updated");
	skipList.find(7, value);
	std::cout << "更新后键 7: " << value << std::endl;

	// 删除数据
	skipList.remove(12);
	std::cout << "\n=== 删除键12后的跳表 ===" << std::endl;
	skipList.display();

	return 0;
}