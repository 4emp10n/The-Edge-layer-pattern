#pragma once
#include "State.h"
#include "DHT.h"
#include "ConcreteStateCheck.h"

extern float t_new;
extern DHT dht;

class ConcreteStateMonitoring : public State
{
public:
	void Monitoring() override;
	void Check() override {}
	void Fire() override {}
	void Announce() override {}
	void NextState() override {}
};