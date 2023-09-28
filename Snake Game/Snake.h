#pragma once

#include "Food.h"

#include <random>
#include <list>

class Snake
{
public:
	Snake(sf::RenderWindow *);
	void drawSnake();
	bool died();
	bool ateFood(Food *);
	void moveSnake(sf::Vector2<int>, bool);
	sf::Vector2f getNextFoodLocation();

private:
	sf::RenderWindow* screen;
	std::vector<sf::RectangleShape> snakeShape;
	sf::Color bodyColor;
	sf::Color headColor;
	int snakeLength;
	std::list<sf::Vector2<int> > snake_direction_list;
	sf::Vector2<int> lastDirection;
	float movementScale;
	bool updateLength;
};