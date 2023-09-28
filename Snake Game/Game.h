#pragma once

#include "Snake.h"

#include <fstream>

class GameController {
public:
	GameController(sf::RenderWindow* w);
	void start();

private:
	void gameLoop();
	void renderScene();
	void displayScore(int);
	void welcomeMessage();

	sf::RenderWindow* screen;
	Food* food;
	Snake snake;
	int score;
};



