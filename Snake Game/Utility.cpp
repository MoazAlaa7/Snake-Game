#include "Utility.h"

sf::RectangleShape makeRectangleAt(sf::Vector2f loc, sf::Color color) {
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(RECT_SIZE, RECT_SIZE));
	rect.setPosition(loc);
	rect.setFillColor(color);
	return rect;
}

bool checkCollision(sf::RectangleShape& h, sf::RectangleShape b) {
	return h.getGlobalBounds().intersects(b.getGlobalBounds());
}