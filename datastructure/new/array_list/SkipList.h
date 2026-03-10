#pragma once
#include "../util.h"

#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <random>

template<typename K, typename V>
class SkipList {
private:
	// 跳表节点定义
	struct Node {
		K key;
		V value;
		std::vector<Node*> forward;  // 向前指针数组

		Node(const K& k, const V& v, int level)
			: key(k), value(v), forward(level + 1, nullptr) {}
	};

	Node* head;           // 头节点
	int maxLevel;         // 最大层数
	int currentLevel;     // 当前层数
	float probability;    // 层数生成概率
	std::mt19937 rng;     // 随机数生成器

						  // 生成随机层数
	int randomLevel() {
		int level = 0;
		while (level < maxLevel &&
			std::generate_canonical<float, 10>(rng) < probability) {
			level++;
		}
		return level;
	}

public:
	SkipList(int maxLevel = 16, float prob = 0.5)
		: maxLevel(maxLevel), probability(prob), currentLevel(0) {
		// 初始化头节点
		head = new Node(K(), V(), maxLevel);

		// 初始化随机数生成器
		std::random_device rd;
		rng.seed(rd());
	}

	~SkipList() {
		Node* current = head->forward[0];
		while (current != nullptr) {
			Node* next = current->forward[0];
			delete current;
			current = next;
		}
		delete head;
	}

	// 插入键值对
	void insert(const K& key, const V& value) {
		// 用于存储每层需要更新的节点
		std::vector<Node*> update(maxLevel + 1);
		Node* current = head;

		// 从最高层开始查找插入位置
		for (int i = currentLevel; i >= 0; i--) {
			while (current->forward[i] != nullptr &&
				current->forward[i]->key < key) {
				current = current->forward[i];
			}
			update[i] = current;
		}

		// 移动到第0层
		current = current->forward[0];

		// 如果key已存在，更新值
		if (current != nullptr && current->key == key) {
			current->value = value;
			return;
		}

		// 生成随机层数
		int newLevel = randomLevel();

		// 如果新层数大于当前层数，更新头节点指针
		if (newLevel > currentLevel) {
			for (int i = currentLevel + 1; i <= newLevel; i++) {
				update[i] = head;
			}
			currentLevel = newLevel;
		}

		// 创建新节点
		Node* newNode = new Node(key, value, newLevel);

		// 更新各层的指针
		for (int i = 0; i <= newLevel; i++) {
			newNode->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = newNode;
		}
	}

	// 查找键对应的值
	bool find(const K& key, V& value) {
		Node* current = head;

		// 从最高层开始查找
		for (int i = currentLevel; i >= 0; i--) {
			while (current->forward[i] != nullptr &&
				current->forward[i]->key < key) {
				current = current->forward[i];
			}
		}

		// 移动到第0层
		current = current->forward[0];

		// 检查是否找到
		if (current != nullptr && current->key == key) {
			value = current->value;
			return true;
		}
		return false;
	}

	// 删除键
	bool remove(const K& key) {
		std::vector<Node*> update(maxLevel + 1);
		Node* current = head;

		// 从最高层开始查找待删除节点的位置
		for (int i = currentLevel; i >= 0; i--) {
			while (current->forward[i] != nullptr &&
				current->forward[i]->key < key) {
				current = current->forward[i];
			}
			update[i] = current;
		}

		// 移动到待删除节点
		current = current->forward[0];

		// 如果没有找到key
		if (current == nullptr || current->key != key) {
			return false;
		}

		// 更新各层的指针
		for (int i = 0; i <= currentLevel; i++) {
			if (update[i]->forward[i] != current) {
				break;
			}
			update[i]->forward[i] = current->forward[i];
		}

		// 删除节点
		delete current;

		// 更新当前层数
		while (currentLevel > 0 && head->forward[currentLevel] == nullptr) {
			currentLevel--;
		}

		return true;
	}

	// 打印跳表
	void display() {
		std::cout << "Skip List (当前层数: " << currentLevel << ")" << std::endl;

		for (int i = currentLevel; i >= 0; i--) {
			Node* node = head->forward[i];
			std::cout << "Level " << i << ": ";
			while (node != nullptr) {
				std::cout << "(" << node->key << "," << node->value << ") ";
				node = node->forward[i];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};

int testSkipList();