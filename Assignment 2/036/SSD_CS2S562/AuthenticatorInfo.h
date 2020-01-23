#ifndef AUTHENTICATORINFO_H
#define AUTHENTICATORINFO_H

#include <string>
#include <map>
using namespace std;

class AuthenticatorInfo{//checks credentials
private:
	map<std::string, std::string> Users;//holds credentials

public:
	AuthenticatorInfo();//contructor 
	//checks credentials match
	bool validateUser(std::string name, std::string password);
};
#endif