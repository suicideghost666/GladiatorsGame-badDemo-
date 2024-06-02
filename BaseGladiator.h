#ifndef _BASEGLADIATOR_H_
#define _BASEGLADIATOR_H_
#include "BaseWeapon.h"
#include "SFML/Graphics.hpp"
class BaseGladiator {
protected:
	int health;
	int damage;
	int actionAmount;
	sf::Texture texture;
	sf::Vector2f scale;
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::IntRect rectSourceSprite;
	int spriteLastLeftEdge, frameWidth;
	BaseWeapon* gladWeapon;
	
	

public:
	BaseGladiator(int x, int y, float scalex, float scaley) {
		position = sf::Vector2f(x, y);
		scale = sf::Vector2f(scalex, scaley);
		sprite.setPosition(position);
		texture = sf::Texture();
	}
	void addWeapon(BaseWeapon* weapon) {
		gladWeapon = weapon;
	}
	void attack(sf::RenderWindow& win, sf::Clock clock) {
		if (clock.getElapsedTime().asSeconds() > 0.4f) {
			if (rectSourceSprite.left == spriteLastLeftEdge) {
				rectSourceSprite.left = 0;
			}
			else {
				rectSourceSprite.left += frameWidth;
			}
			sprite.setTextureRect(rectSourceSprite);
			clock.restart();
			
		}
		win.draw(sprite);
	}
	void draw(sf::RenderWindow& win) {
		win.draw(sprite);
	}
	
};
#endif // !_BASEGLADIATOR_H_
