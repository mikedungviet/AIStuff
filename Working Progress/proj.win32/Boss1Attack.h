#pragma once
#include <2d/CCSprite.h>


class FlameThrower
{
public:
	FlameThrower();
	//~FlameThrower();
	void update(const float& deltaT);

	//Getters
	cocos2d::Sprite* getSprite() const;
	cocos2d::DrawNode* getHitBox() const;
private:
	cocos2d::Vec2 position, velocity;
	const cocos2d::Vec2  acceleration;
	cocos2d::Sprite *sprite;
	cocos2d::Rect hitBox;
	const float height, width;
	cocos2d::DrawNode *hitBoxRect;

	//Utility functions
	void redrawHitBoxRect();
};
