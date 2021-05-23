#include "Arduino.h"
#include "ConcreteStateAnnounce.h"

void ConcreteStateAnnounce::Announce()
{
	do
	{
		Sound();
		context_->CreateMessage("Fire");
		std::cout << "Send info for all users\n";
		if (digitalRead(D6) == 1)
		{
			but_state = 1;
			delay(200);
		}

		yield();
	} while (but_state == 0);

	Serial.println("Stop");
	digitalWrite(D2, LOW);
	NextState();
}

void ConcreteStateAnnounce::NextState()
{
	this->context_->TransitionTo(new ConcreteStateOn, "ConcreteStateOn");
}
void ConcreteStateAnnounce::Sound()
{
	go();
}