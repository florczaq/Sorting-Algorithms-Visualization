#pragma once
#include "SFML/Graphics.hpp"



class Line : public sf::Drawable
{
private:
	sf::RectangleShape rectangle;
	float width = 0, height = 0;
	int rectanglesCount = 0;
	sf::Vector2u windowSize;
public:
	Line(sf::Vector2u windowSize);

	void setOffsetX(int offstetMultiply);

	void setHeightDifference(float difference);

	sf::Vector2f getPosition();

	sf::Vector2f getSize();

	void setPosition(sf::Vector2f position);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(rectangle);
	}
};
