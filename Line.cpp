#include "Line.h"

Line::Line(sf::Vector2u windowSize) {
	height = windowSize.y;
	width = 1;
	rectangle.setSize(sf::Vector2f(width, height));
	rectanglesCount = windowSize.x;
	this->windowSize = windowSize;
}

void Line::setOffsetX(int offstetMultiply) {
	rectangle.setPosition(width * offstetMultiply, rectangle.getPosition().y);
}

void Line::setHeightDifference(float difference) {
	rectangle.setSize(sf::Vector2f(width, windowSize.y - difference));
	rectangle.setPosition(rectangle.getPosition().x, windowSize.y);
	rectangle.setOrigin(0, rectangle.getSize().y);

}

sf::Vector2f Line::getPosition() {
	return rectangle.getPosition();
}

sf::Vector2f Line::getSize() {
	return rectangle.getSize();
}

void Line::setPosition(sf::Vector2f position) {
	rectangle.setPosition(position);
}
