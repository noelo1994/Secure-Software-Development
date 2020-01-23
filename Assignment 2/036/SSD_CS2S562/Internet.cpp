#include "Internet.h"
using namespace std;

Internet::Internet(){}

void Internet::populate()
{
	srand(static_cast<unsigned int>(time(NULL)));//initialises random seed
	//create 30 pieces of data(readings)
	for (int i = 0; i < 30; i++){
		int x = 1 + (rand() % 99);//random number
		usage.push_back(x);//store in vector
	}
}

void Internet::save()
{
	std::fstream myfile("IntUsage.txt", ios::out);//creating a text file
	if (myfile.is_open()){//if file is open
		myfile << "Internet Usage Readings (GB)";
		//size_t prevents signed integer from overflow
		for (size_t i = 0; i < usage.size(); i++){
			//write each element into text file
			myfile << i << ": " << usage[i] << endl;
		}
		myfile.close();//close file
		return;
	}
	//next 4 lines protect the file if it hasn't been closed properly
	if (myfile.fail()){//if file fails
		cout << "\nFile failed. " << endl;
	}
	std::terminate();//terminate
}

void Internet::print()
{
	//last element of vector is last reading
	internet = usage[usage.size() - 1];
	cout << "\n	INTERNET";
	cout << "\nInternet Usage : " << internet << " GB\n";

	unsigned exitStatus = 0;//1 = exit, 0 = not exit
	while (!exitStatus){//while user has not exited
		cout << "View previous readings? [Yes = 1, No = 0] : ";
		unsigned option = 0;//variable to store option
		cin >> option;//store option
		if (option){//if user does want to view readings
			int day;//variable to store chosen day
			cout << "    Which day? (" << usage.size() << " available) : ";
			cin >> day;//store chosen day
			cout << "Internet usage on this day was : " << getUsage(day) << " GB\n";
		}
		else if (!option){//they don't want to view readings
			//nothing
		}
		else{//entered invalid input
			//process option again
			cout << "\n Yes = 1, No = 0 : ";
			cin >> option;
		}
		cout << "View all previous readings? [Yes = 1, No = 0] : ";
		cin >> option;//store option
		if (option){//if they want to view readings
			//size_t prevents signed integer from overflow
			for (size_t i = 0; i < usage.size(); i++){
				//print each element
				cout << i << ": " << usage[i] << endl;
			}
		}
		else if (!option){//they don't want to view readings
			exitStatus = 1;//exit user
		}
		else//entered invalid input
		{
			//process option again
			cout << "\n Yes = 1, No = 0 : ";
			cin >> option;
		}
	}
}

void Internet::setUsage()
{
	srand(static_cast<unsigned int>(time(NULL)));//initialises random seed
	int x = 1 + (rand() % 99);//random number
	usage.push_back(x);//store in vector
	internet = x;//set new usage reading
}

int Internet::getUsage(int x)
{
	//day 1 reading stored in vector position 0
	x = x - 1;
	return usage[x];
}