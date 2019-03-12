#include "Boss1Attack.h"


FlameThrower::FlameThrower()
	: acceleration(1250, 0), velocity(750, 0), position(100, 600), sprite(cocos2d::Sprite::create("LavaBall.png")), height(50), width(50),
	hitBoxRect(cocos2d::DrawNode::create())
{
	sprite->setPosition(position);
}

void FlameThrower::update(const float& deltaT)
{
	velocity += acceleration * deltaT;
	position += velocity * deltaT;
	sprite->setPosition(position);

	redrawHitBoxRect();
}

cocos2d::Sprite* FlameThrower::getSprite() const
{
	return sprite;
}

cocos2d::DrawNode* FlameThrower::getHitBox() const
{
	return hitBoxRect;
}

void FlameThrower::redrawHitBoxRect()
{
	//Change the hit box
	hitBox.setRect(position.x - width/2,position.y-height/2, width, height);

	//redraw the hit box
	hitBoxRect->clear();
	hitBoxRect->drawRect(cocos2d::Vec2(hitBox.getMinX(),hitBox.getMinY()),cocos2d::Vec2(hitBox.getMaxX(), hitBox.getMaxY()), cocos2d::Color4F(0.0f, 1.0f, 0.0f, 1.0f));
}
