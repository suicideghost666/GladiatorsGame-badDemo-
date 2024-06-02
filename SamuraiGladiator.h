#ifndef _SAMURAI_H
#define _SAMURAI_H
#include "BaseGladiator.h"
class SamuraiGladiator : BaseGladiator {
public:
	SamuraiGladiator(int x, int y, int scalex, int scaley) : BaseGladiator(x,y,scalex,scaley) {
		rectSourceSprite = sf::IntRect(0, 0, 128, 128);
		if (!texture.loadFromFile("assets/chars/samurai/idle.png")) exit(-1);
		sprite.setTexture(texture);
		sprite.setTextureRect(rectSourceSprite);
		sprite.setScale(scale);
	}
	void idle() {
		texture.loadFromFile("assets/chars/samurai/idle.png");
		sprite.setTexture(texture);
		if (rectSourceSprite.left == 640) {
			rectSourceSprite.left = 0;
		}
		else {
			rectSourceSprite.left += 128;
		}
		sprite.setTextureRect(rectSourceSprite);
		std::cout << "X " << sprite.getPosition().x;
		std::cout << "Y " << sprite.getPosition().y;
	}
	void draw(sf::RenderWindow& win) {
		BaseGladiator::draw(win);
	}
};
#endif // !1

