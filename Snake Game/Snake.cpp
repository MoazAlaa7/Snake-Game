#include "Snake.h"

Snake::Snake(sf::RenderWindow* screen)
{
	this->screen = screen;
	this->bodyColor = sf::Color::Blue;
	this->headColor = sf::Color::White;
	this->snakeLength = 1;
	this->movementScale = 5;
	this->updateLength = false;
	
	snakeShape.push_back(makeRectangleAt(sf::Vector2f(300, 300), headColor));
	snake_direction_list.push_front(sf::Vector2<int>(0, 0));

	srand(time(NULL));
}

void Snake::drawSnake()
{
	for (int i = 1; i < snakeLength; i++) {
		screen->draw(snakeShape[i]);
	}
	screen->draw(snakeShape[0]);
}

bool Snake::died()
{
	// Check if the snake hit itself
	for (int i = 9; i < snakeLength; i++) {
		if (checkCollision(snakeShape[0], snakeShape[i]))
			return true;
	}

	// Check if the snake hit a wall
	int x = snakeShape[0].getGlobalBounds().left;
	int y = snakeShape[0].getGlobalBounds().top;
	int screenx = screen->getSize().x;
	int screeny = screen->getSize().y;
	return (x > screenx-RECT_SIZE || x < 0) || (y > screeny-RECT_SIZE || y < 0);
}

bool Snake::ateFood(Food* fd)
{
	if (updateLength) {
		snakeLength++;
		updateLength = false;
	}
	if (checkCollision(snakeShape[0], fd->getFood())) {
		updateLength = true;
		sf::Vector2f new_loc = snakeShape[snakeLength - 1].getPosition();
		snakeShape.push_back(makeRectangleAt(new_loc, bodyColor));
		snake_direction_list.push_back(lastDirection);
		return true;
	}
	return false;
}

void Snake::moveSnake(sf::Vector2<int> direction, bool pause)
{
	int index = 0;

	// Pause the snake 
	if (pause) {
		while (index < snakeLength) {
			snakeShape[index].move(0, 0);
			index++;
		}
	}
	// Move the snake
	else {
		snake_direction_list.push_front(direction);
		lastDirection = snake_direction_list.back();
		snake_direction_list.pop_back();
		std::list<sf::Vector2<int>>::iterator i = snake_direction_list.begin();
		while (i != snake_direction_list.end() && index < snakeLength) {
			snakeShape[index].move(movementScale * (*i).x, movementScale * (*i).y);
			index++;
			i++;
		}
	}
}

sf::Vector2f Snake::getNextFoodLocation()
{
	bool notOnSnakeBody = true;
	while (notOnSnakeBody) {
		int x = rand() % ((screen->getSize().x - RECT_SIZE) - 0 + 1) + 0; 																	
		int y = rand() % ((screen->getSize().y - RECT_SIZE) - 0 + 1) + 0;
		sf::Vector2f newFoodLocation(x, y);
		for (int i = 0; i < snakeLength; ++i) {
			if (snakeShape[i].getGlobalBounds().contains(newFoodLocation))
				notOnSnakeBody = false;
		}
		if (notOnSnakeBody) return newFoodLocation;
		else notOnSnakeBody = true;
	}
}