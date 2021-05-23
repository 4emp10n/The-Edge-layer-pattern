#pragma once
#include "State.h"
#include "ConcreteStateOn.h"

class ConcreteStateBroken : public State {
public:
	void Monitoring() override {}
	void Check() override {}
	void Fire() override {}
	void Announce() override;
	void NextState() override;
};