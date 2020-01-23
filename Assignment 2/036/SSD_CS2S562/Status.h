#ifndef STATUS_H
#define STATUS_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

class Status{//produces device status information
private:
	int supplyVoltage;//stores supply voltage
	int intTemp;//stores internal temperature
	std::string fault;//stores any faults 

public:
	Status();//constructor - initialises variables
	void print();//prints information
	int getSupplyVoltage();//gets supply voltage
	int getIntTemp();//gets internal temperature
	std::string getFaults();//checks for faults
	void save();//saves data to a text file
};
#endif