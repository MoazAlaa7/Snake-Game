#pragma once

#include "Utility.h"

class Food
{
public:
	Food(sf::RenderWindow* ,sf::Vector2f);
	void drawFood();
	sf::RectangleShape getFood();

private:
	sf::RenderWindow* screen;
	sf::RectangleShape foodShape;
	sf::Color foodColor;
	sf::Vector2f foodLoc;
};