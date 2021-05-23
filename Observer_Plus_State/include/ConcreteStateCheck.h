#pragma once
#include "State.h"
#include "ConcreteStateFire.h"
#include "ConcreteStateBroken.h"

extern bool second_sensor;

class ConcreteStateCheck : public State {
public:
	void Monitoring() override {}
	void Check() override;
	void Fire() override {}
	void Announce() override {}
	void NextState() override {}
};