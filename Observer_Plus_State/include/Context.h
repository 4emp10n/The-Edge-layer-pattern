#pragma once
#include <iostream>
#include <list>
#include "State.h"
#include "ISubject.h"

class State;

class Context : public ISubject
{
	State* state_;
	std::string* name_;
	std::list<IObserver*> list_observer_;
	std::string message_;

public:
	Context(State* state, std::string name);
	~Context();
	void TransitionTo(State* state, std::string name);
	void Monitoring();
	void Check();
	void Fire();
	void Announce();
	void NextState();

	void Attach(IObserver* observer) override;
	void Detach(IObserver* observer) override;
	void Notify() override;

	void CreateMessage(std::string message = "Empty");

};