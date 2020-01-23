#include "AuthInfo.h"
#include <iostream>

AuthInfo::AuthInfo()
{
	Users.insert(pair<string, string>("Admin", "321"));
	Users.insert(pair<string, string>("User", "123"));
};

bool AuthInfo::validation(string name, string pass)
{
	bool valid = false;
	map<string, string>::iterator it;
	it = Users.find(name);
	if (it != Users.end())
	{
		if (!(it->second.compare(pass)))
		{
			valid = true;
		}
	}	
	Sensor s;
	s.checkAdmin(name); //send name through into Sensors::checkAdmin
	return valid;
}
