#pragma once
#include<iostream>
#include <map>
#include <string>

using namespace std;

class Subject//subject class
{
private:
	string id;//string to hold user entered id
	string password;//string to hold user entered passwoed
public:
	//Subject(string a, string pass);
	Subject();
	string getId();
	string getPassword();
	void setId();
	void setPassword();
	void setDetails();

};

class AuthenticationInfo
{


private:
	map<string, string>Users;//created map called user to accept 2 strings for id and pass

public:
	AuthenticationInfo();//function that saves user details
	bool validateUser(string name, string password);
};

class Authenticator
{
public:
	Authenticator();
	bool authenticateUser(Subject&s);
};