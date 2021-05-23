#include "Arduino.h"
#include "ConcreteStateFire.h"

unsigned long prev_millis = 0;
unsigned long last_press;
bool butt_flag = 0, butt = 0;
const int rattling = 50;

void ConcreteStateFire::Fire()
{

	digitalWrite(D1, LOW);
	digitalWrite(D2, HIGH);
	std::cout << "!!!!FIRE!!!!\n";

	// butt = !digitalRead(D6);
	// if (butt == 1 && butt_flag == 0 && millis() - last_press > rattling)
	// {
	// 	butt_flag = 1;
	// 	last_press = millis();
	// }

	// if (butt == 0 && butt_flag == 1 && millis() - last_press > rattling)
	// {
	// 	butt_flag = 0;
	// 	last_press = millis();
	// 	Serial.println("Stop");
	// 	but_state = 1;
	// 	this->context_->TransitionTo(new ConcreteStateAnnounce, "ConcreteStateAnnounce");
	//}

	this->context_->TransitionTo(new ConcreteStateAnnounce, "ConcreteStateAnnounce");
}

