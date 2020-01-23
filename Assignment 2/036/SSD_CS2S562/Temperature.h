#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

class Temperature{//produces temperature readings
private:
	std::vector<int> temp;//stores temperature readings
	int temperature;//stores current reading

public:
	Temperature();//constructor - initialises variables
	void populate();//populates vector with historical data
	void print();//prints information
	void setTemp();//sets a new temperature
	int getTemp(int x);//gets temperature on given day
};
#endif