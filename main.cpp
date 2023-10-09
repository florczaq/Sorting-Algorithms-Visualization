#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include "Line.h"
#include "Sort.h"

constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 800;

using std::vector, std::swap;

void swapPositions(Line& rect1, Line& rect2) {
	Line temp = rect1;
	rect1.setPosition(rect2.getPosition());
	rect2.setPosition(temp.getPosition());
}

vector<Line> shuffleElements(vector<Line> lines) {
	for (int i = 0; i < WINDOW_WIDTH; i++) {
		int random = rand() % WINDOW_WIDTH;
		swapPositions(lines[i], lines[random]);
		swap(lines[i], lines[random]);
	}
	return lines;
}

enum Options {
	BUBBLE, QUICK
};

int main()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Algorithms");
	sf::Clock clock;
	Sort sort;
	vector<Line> lines;
	Options option = Options::BUBBLE;

	for (int i = 0; i < WINDOW_WIDTH; i++)
		lines.push_back(Line(window.getSize()));
	window.setFramerateLimit(60);
	clock.restart();

	for (int i = 0; i < WINDOW_WIDTH; i++) {
		lines[i].setHeightDifference(i);
		lines[i].setOffsetX(i);
	}

	lines = shuffleElements(lines);

	int i = 0;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime().asMilliseconds() > 5) {

			switch (option) {
			case BUBBLE:
				lines = sort.sortowanie_babelkowe(lines, i);
				std::cout << i << "\t";
				if (i == lines.size()) {
					system("pause");
					exit(1);
				}
				break;
			case QUICK:
				break;
			}

			window.clear();
			for (auto rectangle : lines)
				window.draw(rectangle);
			window.display();
			clock.restart();
		}
	}

	return 0;
}