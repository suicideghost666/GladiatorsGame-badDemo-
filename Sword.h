#ifndef _SWORD_H
#define _SWORD_H
#include "BaseWeapon.h"
class Sword : BaseWeapon{
public:
	Sword() {
		damage = 1;
		hitPossibiblity = 0.8;
	}
};
#endif // !_DAGGER_H
