#include "Temperature.h"
using namespace std;

Temperature::Temperature(){}

void Temperature::populate(){
	srand(static_cast<unsigned int>(time(NULL)));//initialise random seed
	//create 30 pieces of data(readings)
	for (int i = 0; i < 29; i++){
		int x = 10 + (rand() % 15);//random number
		temp.push_back(x);//store in vector
	}
}

void Temperature::print()
{
	//last element of vector is last reading
	temperature = temp[temp.size() - 1];
	cout << "\n	TEMPERATURE";
	cout << "\nTemperature : " << temperature << " degrees ";

	unsigned exitStatus = 0;//0 = not exit, 1 = exit
	while (!exitStatus){//as long as user has not chosen to exit
		cout << "\nView previous readings? [Yes = 1, No = 0] : ";
		unsigned option = 0;//variable to store option
		cin >> option;//store option
		if (option){//if user wants to view readings
			int day;//variable to store day chosen
			cout << "    Which day? (" << temp.size() << " days available) : ";
			cin >> day;//store chosen day
			cout << "Temperature on this day was : " << getTemp(day) << " degrees\n";
		}
		else if (!option){//if they don't want to view readings
			//nothing
		}
		else{//entered invalid option
			//process input option again
			cout << "\n Yes = 1, No = 0 : ";
			cin >> option;
		}
		cout << "Would you like to change the temperature? [Yes = 1, No = 0] : ";
		cin >> option;//store option
		if (option){//if user wants to change temperature
			cout << "    Set to : ";
			cin >> temperature;//set new temperature
			while (temperature > 30 || temperature < 5){//while not in range
				cout << "This device only supports temperatures between 5-30 degrees : ";
				cin >> temperature;//store new temperature
			}
			cout << "The temperature is being changed to " << temperature << " degrees. ";
			temp.push_back(temperature);//store new temperature
		}
		else if (!option){//if user doesn't want to change temperature
			exitStatus = 1;//exit the user
		}
		else{//entered invalid option
			//process input option again
			cout << "\n Yes = 1, No = 0 : ";
			cin >> option;
		}
	}
}

void Temperature::setTemp()
{
	int x = 10 + (rand() % 15);//random number
	temp.push_back(x);//store in vector
	temperature = x;//set as new temperature
}

int Temperature::getTemp(int x)
{
	//day 1 reading stored in vector position 0
	x = x - 1;
	return temp[x];
}