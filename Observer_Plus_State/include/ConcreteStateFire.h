#pragma once
#include "State.h"
#include "ConcreteStateAnnounce.h"
#include "Sounds.h"

extern bool but_state;

class ConcreteStateFire : public State {
public:
	void Monitoring() override {}
	void Check() override {}
	void Fire() override;
	void Announce() override {}
	void NextState() override {}
	
};