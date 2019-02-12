#include "FirstBossState.h"
#include "Boss.h"


FirstBossState::FirstBossState()
{
	currentState = new State;
}

FirstBossState::~FirstBossState()
{
	delete currentState;
}

void FirstBossState::changeToIdleState(Boss* boss)
{
}

void FirstBossState::changeToFlameSplit(Boss* boss)
{
}

Idling4FirstBoss::Idling4FirstBoss(): cooldownBeforeNextAbility{5.f}
{

}

void Idling4FirstBoss::update(const float &deltaT, Boss *bossInstance)
{
	cooldownBeforeNextAbility -= deltaT;
	//Play some animation

	if (cooldownBeforeNextAbility <= 0)
	{
		changeToFlameSplit(bossInstance);
	}
}

void Idling4FirstBoss::chooseRandomAbility()
{

}

void Idling4FirstBoss::changeToFlameSplit(Boss* boss)
{
	boss->setState(new FlameSplit4FirstBoss);
	delete this;
}

FlameSplit4FirstBoss::FlameSplit4FirstBoss()
{
	*currentState = performingAbility;
}

void FlameSplit4FirstBoss::update(const float &deltaT, Boss *bossInstance)
{
	if (*currentState == charging)
	{
		//Add animation for the boss charging before shooting
	}
	else if (*currentState == performingAbility)
	{
		//Shoot a lava ball

		//return to idle state
		changeToIdleState(bossInstance);
	}
}

void FlameSplit4FirstBoss::changeToIdleState(Boss* boss)
{
	boss->setState(new Idling4FirstBoss);
	delete this;
}
