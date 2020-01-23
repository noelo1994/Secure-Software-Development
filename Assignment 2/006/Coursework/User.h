#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
using namespace std;

//user class
class User
{
private:
	string ID;
	string password;
	string proofID;
public:
	User(string aID, string pass);
	User();
	string getId();
	string getPassword();
	void setproofofID(string proof);
	string getproofofID();
};


#endif