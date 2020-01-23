#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <iostream>

class Subject{//gets and stores user credentials
private:
	std::string username;//stores user input
	std::string password;//stores user input
	std::string proofID;//stores proof of ID

public:
	Subject(std::string a, std::string pass);
	Subject();//contructor - gets username and password
	std::string getUsername();//gets username input
	std::string getPassword();//gets password input
	void setproofofID(std::string proof);//sets proof of ID
	std::string getproofofID();//gets proof of ID
};
#endif