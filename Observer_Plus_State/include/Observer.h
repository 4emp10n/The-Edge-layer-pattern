#pragma once
#include <iostream>
#include "IObserver.h"
#include "Context.h"

class Observer : public IObserver {
public:
	Observer(Context& context);
	virtual ~Observer();

	void Update(const std::string& message_from_subject) override;
	void PrintInfo();

private:
	std::string message_from_subject_;
	static int static_number_;
	int number_;
	Context& context_;
};