#include "Authenticator.h"


Subject::Subject()
{

}
string Subject::getId() { return id; };//returns user entered id
string Subject::getPassword() { return password; }
void Subject::setId()
{
	cout << "Enter UserID :";//message to request username
	cin >> id;//saves to id;
}
void Subject::setPassword()
{
	cout << "Enter Password :";//message to request password
	cin >> password;//saves to password
}
void Subject::setDetails()
{
	setId();
	setPassword();
	system("cls");//clear screen
}

AuthenticationInfo::AuthenticationInfo()//function that saves user details
{
	Users.insert(pair<string, string>("Noel", "1234"));//
	Users.insert(pair<string, string>("Meg", "4321"));// adds new user
};

bool AuthenticationInfo::validateUser(string name, string password)//function to compare user entered id and password to stored id and pass. User id and pass is passed to function
{

	bool validUser = false;//declaring bool to false for is the user if validated
	map<string, string>::iterator it;
	it = Users.find(name);
	if (it != Users.end())//if entered id exists as a saved user
	{
		if (!(it->second.compare(password)))//if entered password matches saved user
		{
			validUser = true;//user is validated
		}
	}
	return validUser;//return valid user
}

Authenticator::Authenticator() {};

bool Authenticator::authenticateUser(Subject &s)
{
	AuthenticationInfo ainfo;
	string Id = s.getId();//setting local variable to entered id
	string pass = s.getPassword();//setting local variable to entered pass
	bool authenticated = false;//initialising authenticated to be false
	if (ainfo.validateUser(Id, pass))//if validuser is returned true
	{
		cout << "Welcome " << s.getId() << "!" << endl;//welcome message to user including their name

		authenticated = true;
	}
	else
		cout << "Invalid user ID or password. " << endl;//mesage to tell user incorrect infromation entered
	return authenticated;
}