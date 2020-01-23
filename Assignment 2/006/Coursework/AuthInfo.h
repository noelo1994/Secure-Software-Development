#ifndef AUTHINFO_H
#define AUTHINFO_H

#include <sstream>
#include <string>
#include <map>
#include "Sensors.h"
//#include "Permission.h"
using namespace std;
//Authinfo Class

class AuthInfo
{
private:
	map<string, string> Users;

public:
	AuthInfo(); //constructor
	bool validation(string name, string pass);
};

#endif