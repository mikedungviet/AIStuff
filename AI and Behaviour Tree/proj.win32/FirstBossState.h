#pragma once

//Foward declare
class Boss;


/*
 *
 */
class FirstBossState
{
public:
	FirstBossState();
	virtual ~FirstBossState();
	virtual void update(const float &deltaT, Boss *bossInstance) = 0;

protected:
	enum State
	{
		charging, performingAbility
	};

	State *currentState{nullptr};

	//Utility Functions
	virtual void changeToIdleState(Boss *boss);
	virtual void changeToFlameSplit(Boss *boss);
};

/*
 *
 */
class Idling4FirstBoss: public FirstBossState
{
public:
	Idling4FirstBoss();
	void update(const float &deltaT, Boss *bossInstance) override;

private:
	float cooldownBeforeNextAbility;

	//Utility functions
	/*
	 * List	of utility functions
	 * 1. Choose a random ability
	 */
	void chooseRandomAbility();


	void changeToFlameSplit(Boss* boss) override;
};

/*
 *This class  
 */
class FlameSplit4FirstBoss: public FirstBossState
{
public:
	FlameSplit4FirstBoss();
	void update(const float &deltaT, Boss *bossInstance) override;
private:
	void changeToIdleState(Boss* boss) override;
};