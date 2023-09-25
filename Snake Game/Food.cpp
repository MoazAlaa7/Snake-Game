#include "Food.h"

Food::Food(sf::RenderWindow* screen, sf::Vector2f loc)
{
	this->screen = screen;
	this->foodLoc = loc;
	this->foodColor = sf::Color::Red;
	this->foodShape = makeRectangleAt(loc, foodColor);
}

void Food::drawFood()
{
	screen->draw(foodShape);
}

sf::RectangleShape Food::getFood()
{
	return foodShape;
}