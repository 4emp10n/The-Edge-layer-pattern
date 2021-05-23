#include "Arduino.h"
#include "ConcreteStateBroken.h"

void ConcreteStateBroken::Announce()
{
	digitalWrite(D1, LOW);
	digitalWrite(D2, LOW);
	digitalWrite(D3, HIGH);
	context_->CreateMessage("DHT is broke\n");
	std::cout << "Send info for all users\n";
	Serial.print("DHT is broken");
	do
	{
		if (digitalRead(D6) == 1)
		{
			but_state = 1;
			Serial.println("Button pushed");
			delay(200);
		}
		Blynk.run();
		yield();
	} while (but_state == 0);
	Serial.println("Stop");
	digitalWrite(D3, LOW);
	NextState();
}

void ConcreteStateBroken::NextState()
{
	this->context_->TransitionTo(new ConcreteStateOn, "ConcreteStateOn");
}
