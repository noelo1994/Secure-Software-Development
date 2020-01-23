#ifndef ELECTRIC_H
#define ELECTRIC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

class Electric{//produces electric readings
private:
	//store readings from each room
	std::vector<int> room1, room2, room3, room4;
	//stores whole house readings
	std::vector<int> home;
	int average;//stores average
	
public:
	Electric();//constructor - initialises variables
	void populate();//populates vectors with historical data
	void getData();//works out household usage and average
	void print();//prints information 
	void save();//saves data to a text file
	void setElec();//sets a new reading for each room
	int getElec(int x);//gets household reading from given day
};
#endif