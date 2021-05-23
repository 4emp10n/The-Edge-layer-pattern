#pragma once
#include "State.h"
#include "ConcreteStateMonitoring.h"

class ConcreteStateOn : public State {
public:
	void Monitoring() override {}
	void Check() override {}
	void Fire() override {}
	void Announce() override {}
	void NextState() override;
};