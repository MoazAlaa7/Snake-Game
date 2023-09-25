#include "game.h"

#include <iostream>
#include <thread>
using namespace std;

GameController::GameController(sf::RenderWindow* w) : snake(w)
{
	screen = w;
	food = new Food(screen, snake.getNextFoodLocation());
	score = 0;
}

void GameController::start()
{
	welcomeMessage();
	gameLoop();
}

void GameController::gameLoop()
{
	bool gameOver = false;
	sf::Vector2<int> direction(0, 0);
	while (!gameOver) {
		renderScene();
		sf::Event event;
		while (screen->pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					direction.y = -1;
					direction.x = 0;
				}
				else if (event.key.code == sf::Keyboard::Down) {
					direction.y = 1;
					direction.x = 0;
				}
				else if (event.key.code == sf::Keyboard::Left) {
					direction.x = -1;
					direction.y = 0;
				}
				else if (event.key.code == sf::Keyboard::Right) {
					direction.x = 1;
					direction.y = 0;
				}
			}
			if (event.type == sf::Event::Closed) {
				exit(0);
			}
		}
		snake.moveSnake(direction);

		if (snake.died()) {
			gameOver = true;
			displayScore();
			std::this_thread::sleep_for(4s);
		}
		if (snake.ateFood(food)) {
			score++;
			delete food;
			sf::Vector2f nextFdLoc = snake.getNextFoodLocation();
			food = new Food(screen, nextFdLoc);
		}
		screen->display();
		screen->setFramerateLimit(60);
	}
}

void GameController::renderScene()
{
	screen->clear();
	snake.drawSnake();
	food->drawFood();
}

void GameController::displayScore()
{
	cout << "Your Score:\n" << score;
}

void GameController::welcomeMessage()
{
	cout << "Welcome!\n" <<
		"Use arrow buttons to move the snake\n\n";
}