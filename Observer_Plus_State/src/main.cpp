#include "Arduino.h"
#include "Observer.h"
#include "Context.h"
#include "ConcreteStateOn.h"
#include "DHT.h"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkWifi Blynk(_blynkTransport);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "RBriTm0zV1YEI2fuEXo1rDGNbCtUwLMD";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "373";
char pass[] = "2899117fifc";

DHT dht(D7, DHT11);

const int timer = 5000;
bool second_sensor = 1;
bool but_state = 0;
unsigned long curr_time = millis();

const int num = 3;
const int first_led = D1;
const int second_led = D2;
const int arr[num] = {D1, D2, D3};

float t_new = 0, tmp = 1.0;

int Observer::static_number_ = 0;

Context *context = new Context(new ConcreteStateOn, "ConcreteStateOn"); //Create context with off state
Observer *observer1 = new Observer(*context);

BLYNK_WRITE(V1)
{
	if (param.asInt() == 1)
	{
		but_state = 1;
		Serial.println("Virt Butt");
	}
}

void setup()
{
	Serial.begin(9600);
	Blynk.begin(auth, ssid, pass);
	for (auto i : arr)
		pinMode(i, OUTPUT);
	for (auto i : arr)
		digitalWrite(i, LOW);
	pinMode(D6, INPUT_PULLUP);
	digitalWrite(D6, LOW);
	dht.begin();
}

void loop()
{
	but_state = 0;
	
	if (millis() - curr_time > timer)
	{
		context->NextState(); //moving on to a new state (ConcreteStateMonitoring)
		delay(2000);
		context->Monitoring(); //Montirong temperature and humidity and moving on to a new state (ConcreteStateMonitoring)
		delay(2000);
		context->Check();
		delay(2000);
		if (second_sensor == 1)
		{
			context->Fire(); //inform you that the house is on fire and moving on to a new state (ConcreteStateObserver)
			delay(2000);
			context->Announce(); //send warning message to observers
		}
		else
			context->Announce();

		curr_time = millis();
	}
}