#pragma once
#include "Context.h"
class Context;
class State
{
protected:
	Context* context_;
	std::string name;

public:
	virtual ~State() {}

	void set_context(Context* context);

	virtual void Monitoring() = 0;
	virtual void Check() = 0;
	virtual void Fire() = 0;
	virtual void Announce() = 0;
	virtual void NextState() = 0;
};