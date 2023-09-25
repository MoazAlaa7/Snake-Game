#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Snake", sf::Style::Close);
    GameController gamecontroller(&window);
    gamecontroller.start();
    return 0;
}