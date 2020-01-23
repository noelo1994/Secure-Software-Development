#include <iostream>
#include <string>

using namespace std;

const uint16_t MENU_QUIT = 9;
class User
{
public:
	void initalise()
	{
		cout << "User Initialising..." << endl;
		cout << "Loading prefrences..." << endl;

		cout << "Done!" << endl;
	}
	bool isAdmin()
	{
		//check if user is admin
		return false;
	}
	void authenticate()
	{
		cout << "Please enter a username: ";
		string username;
		cin >> username;
		cout << "Please enter your password: ";
		string password;
		cin >> password;
		//check details rerun value indicating sucess or fail

	}
private:
	string username = "";
	uint16_t permissionsLevel = 0;
};

User userObject;


void startup()
{
	cout << "Starting system..." << endl;
	cout << "Initiating users..." << endl;
	//load user
	userObject.initalise();

	cout << "Initiating logger..." << endl;
	//load logger

	cout << "initiating water sensor..." << endl;
	//load sensor 1

	cout << "initiating gas sensor..." << endl;
	//load sensor 2

	cout << "initiating electric sensor..." << endl;
	//load sensor 3

	cout << endl << "System startup complete!" << endl;
}
uint16_t mainMenu()
{

	uint16_t input = 0;
	system("cls");
	cout << "Welcome to the smartest smart meter in town!" << endl;
	cout << "Select from the following options" << endl;
	cout << "/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/" << endl;
	cout << "1: System Information" << endl;
	cout << "2: Live usage" << endl;
	cout << "3: Targets" << endl;
	cout << "4: History" << endl;
	cout << "9: Logout" << endl;

	cout << "Please type your choice: ";
	cin >> input;
	return input;
}
int main()
{
	uint16_t uint_userchoice = 0;
	while (uint_userchoice != MENU_QUIT)
	{
		uint_userchoice = mainMenu();
	}




	system("pause");
	return 0;
}