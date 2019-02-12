#include "Boss.h"

Boss::Boss(): bossSprite(cocos2d::Sprite::createWithSpriteFrameName("First Boss Concept.png"))
{
	state = new Idling4FirstBoss;
}

Boss::~Boss()
{
	delete state;
}

void Boss::setState(FirstBossState* newState)
{
	state = newState;
}

cocos2d::Sprite* Boss::getSprite() const
{
	return bossSprite;
}

void Boss::update(const float &deltaT)
{
	state->update(deltaT, this);
}
