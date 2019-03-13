#pragma once
#include "FirstBossState.h"

template <class T>
class State
{
protected:
	T *entity;
	State();
public:
	~State();

	virtual void update(float deltaT) = 0;
	virtual void changeToChargingState();
};

template <class T>
class ChargingState:public State<T>
{
	float waitingTime;
public:
	ChargingState(T* enityToPass);
};