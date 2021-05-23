#include "ConcreteStateMonitoring.h"

void ConcreteStateMonitoring::Monitoring()
{
	t_new = dht.readTemperature();

	if (isnan(t_new))
	{
		Serial.println("Read error");
		return;
	}
	Serial.print("temperature: ");
	Serial.print(t_new);
	Serial.println(" *C ");
	Blynk.virtualWrite(V2, t_new);
	delay(3000);

	if (t_new < 26)
		this->context_->TransitionTo(new ConcreteStateCheck, "ConcreteStateCheck");
}
