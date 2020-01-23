#include "AuthenticatorInfo.h"

AuthenticatorInfo::AuthenticatorInfo(){
	Users.insert(pair<std::string, std::string>("user", "pass"));//store user credentials
	Users.insert(pair<std::string, std::string>("admin", "password"));//store admin credentials
};

bool AuthenticatorInfo::validateUser(std::string name, std::string password){
	bool validUser = false;
	map<std::string, std::string>::iterator it;
	it = Users.find(name);
	if (it != Users.end()){
		if (!(it->second.compare(password))){
			validUser = true;
		}
	}
	return validUser;
}