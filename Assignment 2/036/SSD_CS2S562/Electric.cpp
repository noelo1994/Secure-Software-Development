#include "Electric.h"
using namespace std;

Electric::Electric(){}

void Electric::populate()
{
	srand(static_cast<unsigned int>(time(NULL)));//initialise random seed
	//create 30 pieces of data(readings)
	for (int i = 0; i < 30; i++){
		room1.push_back(rand() % 200);//store random number in vector
		room2.push_back(rand() % 200);//store random number in vector
		room3.push_back(rand() % 200);//store random number in vector
		room4.push_back(rand() % 200);//store random number in vector
	}
}

void Electric::getData()
{
	for (size_t i = 0; i < room1.size(); i++){
		//size_t prevents signed integer from overflow
		//add all rooms to get household usage
		int x = room1[i] + room2[i] + room3[i] + room4[i];
		home.push_back(x);//store in vector
		average = average + x;//each loop keep adding to total
	}
	average = average / home.size();//divide by amount of readings giving average
}

void Electric::save()
{
	std::fstream myfile("ElecUsage.txt", ios::out);//creating a text file
	if (myfile.is_open()){//if file is open
		myfile << "Household Electricity Readings (watts)";
		//line below shows how signed integer overflow is prevented
		for (size_t i = 0; i < home.size(); i++){
			//write each element to text file
			myfile << i << ": " << home[i] << endl;
		}
		myfile.close();//close file
		return;
	}
	if (myfile.fail()){//if file fails
		cout << "\nFile failed. " << endl;
	}
	std::terminate();//terminate
}

void Electric::print()
{
	//output readings for each room
	cout << "\n	ELECTRIC";
	cout << "\n    Livingroom : " << room1[room1.size() - 1] << " watts";
	cout << "\n    Kitchen : " << room2[room2.size() - 1] << " watts";
	cout << "\n    Bedroom : " << room3[room3.size() - 1] << " watts";
	cout << "\n    Bathroom : " << room4[room4.size() - 1] << " watts";
	//output household usage and average
	cout << "\nHousehold usage today : " << home[home.size() - 1] << " watts";
	cout << "\nAverage usage is : " << average << " watts per day\n";

	unsigned exitStatus = 0;//1 = exit, 0 = not exit
	while (!exitStatus){//while user has not exited 
		cout << "View previous readings? [Yes = 1, No = 0] : ";
		unsigned option = 0;//variable to store option
		cin >> option;//store option
		if (option){//if user wants to view readings
			int day;//variable to store chosen day
			cout << "    Which day? (" << home.size() << " days available) : ";
			cin >> day;//store chosen day
			cout << "Household usage on this day was : " << getElec(day) << " watts\n";
		}
		else if (!option){//if user doesn't want to view readings
			//nothing
		}
		else{//entered invalid input
			//process option again
			cout << "\n Yes = 1, No = 0 : ";
			cin >> option;
		}
		cout << "View all previous readings? [Yes = 1, No = 0] : ";
		cin >> option;//store option
		if (option){//if user wants to view readings
			//size_t used to stop unsigned integer overflow
			for (size_t i = 0; i < home.size(); i++){
				//loop for each element
				cout << i << ": " << home[i] << endl;
			}
		}
		else if (!option){//if user doesn't want to view readings
			exitStatus = 1;//exit user
		}
		else{//entered invalid option
			//process option again
			cout << "\n Yes = 1, No = 0 : ";
			cin >> option;
		}
	}
}

void Electric::setElec()
{
	room1.push_back(rand() % 200);//store random number in vector
	room2.push_back(rand() % 200);//store random number in vector
	room3.push_back(rand() % 200);//store random number in vector
	room4.push_back(rand() % 200);//store random number in vector
}

int Electric::getElec(int x)
{
	//day 1 reading stored in vector position 0
	x = x - 1;
	return home[x];
}