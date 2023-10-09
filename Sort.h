#pragma once
#include<vector>
#include "Line.h"

using std::vector, std::swap;

struct Sort
{
	vector<Line> sortowanie_babelkowe(vector<Line> lines, int& i);
	vector<Line> shuffleElements(vector<Line> lines, int rectanglesCount);
	void sortowanie_szybkie(vector<Line> lines, float left, float right);
	void swapPositions(Line& rect1, Line& rect2);
};
