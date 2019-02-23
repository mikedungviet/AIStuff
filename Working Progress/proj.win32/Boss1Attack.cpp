#include "Boss1Attack.h"


FlameThrower::FlameThrower() : startPoint(100, 600), sprite(cocos2d::Sprite::create("LavaBall.png")), velocity(250,/*Gravity */-50), acceleration(50,0)
{
	sprite->setPosition(startPoint);
}

void FlameThrower::update(const float& deltaT)
{
	if(velocity.y == 0)
	{
		//Accelerate in x direction
		velocity += acceleration * deltaT;
	}
	else
	{
		//Free fall
		
		
	}
}

cocos2d::Sprite* FlameThrower::getSprite() const
{
	return sprite;
}
