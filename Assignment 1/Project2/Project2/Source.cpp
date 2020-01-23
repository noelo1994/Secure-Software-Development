#include <iostream>
#include <windows.h>
#include <string>
#include <map>
#include <ctime>
#include <stdlib.h>    
#include <time.h> 
#include <vector>
#include"SmartMeter.h"
#include "Authenticator.h"
#include "Appliance.h"
using namespace std;










//returns user entered password






void startup()
{
	cout << "Starting system..." << endl;
	cout << "Initiating users..." << endl;
	//load user

	//userObject.initalise();
	
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


int main()
{
	uint16_t uint_userchoice = 0;
	startup();
	cout << endl;
	system("pause");
	SmartMeter SM;
	while (uint_userchoice != 7)
	{
		uint_userchoice = SM.
	}

	return 0;
}


