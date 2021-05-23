#include "Arduino.h"
#include "ConcreteStateCheck.h"

void ConcreteStateCheck::Check() {
	if (second_sensor == 1) this->context_->TransitionTo(new ConcreteStateFire, "ConcreteStateFire");
	else this->context_->TransitionTo(new ConcreteStateBroken, "ConcreteStateBroken");
}