#include "Arduino.h"
#include "ConcreteStateOn.h"

void ConcreteStateOn::NextState() {
	digitalWrite(D1, HIGH);
	digitalWrite(D3, LOW);
	this->context_->TransitionTo(new ConcreteStateMonitoring, "ConcreteStateMonitoring");
}
