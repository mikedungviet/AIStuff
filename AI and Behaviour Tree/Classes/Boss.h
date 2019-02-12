#pragma once
#include "FirstBossState.h"
#include <2d/CCSprite.h>

class Boss
{
private:
	FirstBossState *state{ nullptr };
	cocos2d::Sprite *bossSprite{ nullptr };
public:
	Boss();
	~Boss();

	//Setters
	virtual void setState(FirstBossState *newState);

	//Getters
	cocos2d::Sprite* getSprite()const;
	
	//Change the state
	//void changeToIdleState();

	//
	void update(const float &deltaT);
	
};

