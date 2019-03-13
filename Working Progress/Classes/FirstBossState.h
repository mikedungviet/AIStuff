#pragma once

//Foward declare
class Boss;
class FirstBossState;

/*
 *
 */
class FirstBossSmallerState
{
protected:
	Boss* bossPointer;

	FirstBossSmallerState(Boss *aBossInstance);
public:
	virtual void update(float deltaT);
};

class FirstBossState
{
public:
	//Destructor
	virtual ~FirstBossState();

	//Setter
	void setSmallerState(FirstBossSmallerState *newState);

	//Functions
	virtual void update(const float &deltaT, Boss *bossInstance) = 0;
	virtual void changeToIdleState(Boss *boss); //Only Idle state is allow to change publicly
protected:
	FirstBossSmallerState *currentState{ nullptr };

	//Utility Functions
	virtual void changeToFlameSplit(Boss *boss);
};

/*
 *
 */
class Idling4FirstBoss : public FirstBossState
{
public:
	Idling4FirstBoss(Boss *boss);
	void update(const float &deltaT, Boss *bossInstance) override;

private:
	float cooldownBeforeNextAbility;

	//Utility functions
	/*
	 * List	of utility functions
	 * 1. Choose a random ability
	 */
	void chooseRandomAbility(Boss *bossInstance);
};

/*
 *This class
 */
class FlameSplitCharging : public FirstBossSmallerState
{
	void changeToPerforming();
public:
	FlameSplitCharging(Boss *boss);
	
};



class FlameSplit4FirstBoss : public FirstBossState
{
public:
	FlameSplit4FirstBoss(Boss *boss);
	void update(const float &deltaT, Boss *bossInstance) override;

};
