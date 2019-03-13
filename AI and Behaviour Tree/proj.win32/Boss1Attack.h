#pragma once
#include <math/Vec2.h>
#include <2d/CCSprite.h>
#include "HitBox.h"


class Boss;

class Boss1LavaAttack
{
protected:
	//Data variables
	Boss *bossPointer;
	cocos2d::Vec2 position, velocity, acceleration;
	cocos2d::Sprite *sprite;
	HitBox *hitBox;

	//Protected Variables
	Boss1LavaAttack(Boss *bossInstance);
public:
	virtual ~Boss1LavaAttack();
	virtual void update(const float &deltaT) = 0;
	//Getters
	cocos2d::Rect getHitBox() const;

};

/*
 * @brief
 */
class LavaBall: public Boss1LavaAttack
{
public:
	LavaBall(const cocos2d::Vec2& heroPosition,int order, Boss *bossInstance);
	~LavaBall();

	//Functions
	void update(const float &deltaT) override;
private:
	float waitingTime;
};

class FlameThrower : public Boss1LavaAttack
{
public:
	FlameThrower(Boss *bossInstance);
	~FlameThrower();
	void update(const float& deltaT) override;
private:
	cocos2d::Vec2 startPoint;
	float onTime, waitingTime;
	cocos2d::DrawNode *drawNode;
};

class SuckerBullet: public Boss1LavaAttack
{
public:
	SuckerBullet(const cocos2d::Vec2 &heroLocation, Boss *bossInstance);
	~SuckerBullet();
	void update(const float& deltaT) override;

private:
	cocos2d::Vec2 bulletVelocity, currentPosition, lastPosition, heroLocation;
	float traveledLength{0}, lengthVector{0};
};