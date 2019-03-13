#include "FirstBossState.h"
#include "Boss.h"
#include "Boss1Attack.h"

FirstBossSmallerState::FirstBossSmallerState(Boss* aBossInstance): bossPointer(aBossInstance)
{
}

void FirstBossSmallerState::update(float deltaT)
{
}

/**********************************************************************
 *
 *
 *                    Default Boss Attack State
 *
 *
 **********************************************************************/
FirstBossState::~FirstBossState()
{
	delete currentState;
}

void FirstBossState::setSmallerState(FirstBossSmallerState* newState)
{
	currentState = newState;
}


//@brief Change to Idle state
void FirstBossState::changeToIdleState(Boss* boss)
{
	boss->setState(new Idling4FirstBoss(boss));
}

//@brief Change and perform Flame Split ability
void FirstBossState::changeToFlameSplit(Boss* boss)
{
	boss->setState(new FlameSplit4FirstBoss(boss));
}


/**********************************************************************
 *
 *
 *                            Idling State
 *
 *
 **********************************************************************/
Idling4FirstBoss::Idling4FirstBoss(Boss *boss) : cooldownBeforeNextAbility{ 5.f }
{/*Empty*/}

void Idling4FirstBoss::update(const float &deltaT, Boss *bossInstance)
{
	cooldownBeforeNextAbility -= deltaT;
	//Play some animation

	if (cooldownBeforeNextAbility <= 0)
	{
		//chooseRandomAbility(bossInstance);
		changeToFlameSplit(bossInstance);
	}
}

void Idling4FirstBoss::chooseRandomAbility(Boss *bossInstance)
{
	////const int randomNum = cocos2d::RandomHelper::random_int(1, 3);
	//switch (cocos2d::RandomHelper::random_int(1, 3))
	//{
	//case 1:
	//	changeToFlameThrower(bossInstance);
	//	break;
	//case 2:
	//	changeToFlameSplit(bossInstance);
	//	break;
	//case 3:
	//	changeToSuckingBullet(bossInstance);
	//	break;
	//default:
	//	throw;
	//}
}


/**********************************************************************
 *
 *
 *                            Flame Split States
 *
 *
 **********************************************************************/
void FlameSplitCharging::changeToPerforming()
{
	//Change to performing state
	//bossPointer->getCurrentState()->setSmallerState();
}

FlameSplitCharging::FlameSplitCharging(Boss* boss): FirstBossSmallerState(boss)
{
	auto action = cocos2d::Animate::create(cocos2d::AnimationCache::getInstance()->getAnimation("boss_spit_tell_animation_key"));

	boss->getSprite()->runAction
	(
		cocos2d::Sequence::create
		(
			cocos2d::Repeat::create(action,1),
			cocos2d::CallFunc::create([&] {this->changeToPerforming(); }),
			nullptr
		)
	);
}


FlameSplit4FirstBoss::FlameSplit4FirstBoss(Boss *boss)
{
	currentState = new FlameSplitCharging(boss);
}

void FlameSplit4FirstBoss::update(const float &deltaT, Boss *bossInstance)
{
	currentState->update(deltaT);
}


