#pragma once

#include <SFML/Graphics.hpp>

const int RECT_SIZE = 25;

sf::RectangleShape makeRectangleAt(sf::Vector2f, sf::Color);

bool checkCollision(sf::RectangleShape&, sf::RectangleShape);


