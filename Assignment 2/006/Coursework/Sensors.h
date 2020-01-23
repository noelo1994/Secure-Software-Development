#ifndef SENSORS_H
#define SENSORS_H
#include <iostream>
#include <time.h>
#include <random>
#include <iomanip>
#include <inttypes.h>
#include <fstream>
#include <string>
using namespace std;

//Sensor class
class Sensor
{
private:
	void Temperature();
	void Depth();
	void Current();
	void Heater();
public:
	void SensorDisplay();
	static void checkAdmin(string); //function called from Authinfo to pass through ID
};

#endif