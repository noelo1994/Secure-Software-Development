#include "User.h"
#include <fstream>

User::User(string authID, string authpass)
: ID(authID), password(authpass)
{
	proofID = "";
}

User::User()
{
	cout << "\nEnter ID : ";
	cin >> ID;
	cout << "\nEnter password :";
	cin >> password;
}
string User::getId(){ return ID; };
string User::getPassword(){ return password; };

void User::setproofofID(string proof)
{
	proofID = proof;
}

string User::getproofofID()
{
	return proofID;
}

