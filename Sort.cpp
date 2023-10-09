#include "Sort.h"

vector<Line> Sort::sortowanie_babelkowe(vector<Line> lines, int& i)
{

	for (int j = 0; j < lines.size() - 1; j++) {
		if (lines[j].getSize().y < lines[j + 1].getSize().y) {
			swapPositions(lines[j], lines[j + 1]);
			swap(lines[j], lines[j + 1]);
		}
	}
	i++;
	return lines;
}

void Sort::sortowanie_szybkie(vector<Line> lines, float left, float right)
{
	float i = left;
	float j = right;
	float x = lines[(left + right) / 2].getSize().y;
	do
	{
		while (lines[i].getSize().y < x)
			i++;

		while (lines[j].getSize().y > x)
			j--;

		if (i <= j)
		{
			swap(lines[i], lines[j]);
			swapPositions(lines[i], lines[j]);

			i++;
			j--;
		}
	} while (i <= j);

	if (left < j) sortowanie_szybkie(lines, left, j);

	if (right > i) sortowanie_szybkie(lines, i, right);

}

void Sort::swapPositions(Line& rect1, Line& rect2)
{
	Line temp = rect1;
	rect1.setPosition(rect2.getPosition());
	rect2.setPosition(temp.getPosition());
}

vector<Line> Sort::shuffleElements(vector<Line> lines, int rectanglesCount)
{
	for (int i = 0; i < rectanglesCount; i++) {
		int random = rand() % rectanglesCount;
		swapPositions(lines[i], lines[random]);
		swap(lines[i], lines[random]);
	}
	return lines;
}


