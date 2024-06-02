#ifndef _BOSS_H
#define _BOSS_H
#include "BaseGladiator.h"
class BossGladiator : BaseGladiator {
public:
	enum Action
	{
		IDLE,
		ATTACK,
		POWERUP
	};
	BossGladiator(int x,int y, int scalex,int scaley) : BaseGladiator(x,y,scalex,scaley) {
		rectSourceSprite = sf::IntRect(0,0,100,100);
		if (!texture.loadFromFile("assets/chars/Boss/idle.png")) exit(-1);
		sprite.setTexture(texture);
		sprite.setTextureRect(rectSourceSprite);
		sprite.setScale(scale);
		
	}
	void idle() {
		texture.loadFromFile("assets/chars/Boss/idle.png");
		sprite.setTexture(texture);
		if (rectSourceSprite.left == 700) {
			rectSourceSprite.left = 0;
		}
		else {
			rectSourceSprite.left += 100;
		}
		sprite.setTextureRect(rectSourceSprite);
	}
	void draw(sf::RenderWindow& win) {
		BaseGladiator::draw(win);
	}
};
#endif // !1
