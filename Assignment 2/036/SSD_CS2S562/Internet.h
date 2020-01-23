#ifndef INTERNET_H
#define INTERNET_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>

class Internet{//produces internet usage readings
private:
	int internet;//stores current reading
	std::vector<int> usage;//stores each days usage

public:
	Internet();//constructor - initialises variables
	void populate();//populates vectors with historical data
	void print();//prints information
	void save();//saves data to a text file
	void setUsage();//sets a new reading
	int getUsage(int x);//gets reading from given day
};
#endif