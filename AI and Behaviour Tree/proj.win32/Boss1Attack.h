#pragma once
#include <math/Vec2.h>
#include <2d/CCSprite.h>


class Boss;

class Boss1LavaAttack
{
public:
	virtual ~Boss1LavaAttack();
	virtual void update(const float &deltaT) = 0;
};

class LavaBall: public Boss1LavaAttack
{
public:
	LavaBall(/*Need the position of the hero*/);
	~LavaBall();

	//Functions
	void update(const float &deltaT) override;
private:
	float initVelocity;
	float theta;
	cocos2d::Sprite *ballSprite;

	//Utility function(s)
	float calculateAngle();
};

class FlameThrower : public Boss1LavaAttack
{
public:
	FlameThrower();
	~FlameThrower();
	void update(const float& deltaT) override;
private:
	cocos2d::Vec2 startPoint;
	float length;
};