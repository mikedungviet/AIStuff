#pragma once
#include <2d/CCSprite.h>


class FlameThrower
{
public:
	FlameThrower();
	//~FlameThrower();
	void update(const float& deltaT);

	cocos2d::Sprite* getSprite() const;
private:
	cocos2d::Vec2 startPoint, acceleration, velocity;
	cocos2d::Sprite *sprite;
};
