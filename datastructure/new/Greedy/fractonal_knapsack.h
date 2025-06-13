#pragma once
#include "../util.h"


class Item {
public:
	int w;
	int v;
	Item(int w, int v) :w(w), v(v) {}
};


double fractionalKnapsack(vector<int> &wgt, vector<int> &val, int cap);



void test_fractional_knapsack();