#include "Interface.h"
#include "Temperature.h"
#include "Electric.h"
#include "Internet.h"
#include "Status.h"
using namespace std;

Interface::Interface(){}

void Interface::print()
{
	//print interface options
	cout << "\n	MENU	";
	cout << "\n(0) - Temperature ";
	cout << "\n(1) - Electricity ";
	cout << "\n(2) - Internet ";
	cout << "\n(3) - Device Status ";
	cout << "\n(4) - Quit\n";
	cin >> option;//get users option
}

void Interface::optionSelect(char a)
{
	if (a == '0'){//0 - temperature
		Temperature c;//constructor
		c.populate();//populate vector
		c.setTemp();//set new temperature
		c.print();//print information
	}
	else if (a == '1'){//1 - electricity
		Electric d;//constructor
		d.populate();//populate vectors
		d.setElec();//set new readings
		d.getData();//calculate data based on current readings
		d.save();//save data to text file
		d.print();//print information
	}
	else if (a == '2'){//2 - internet
		Internet e;//constructor
		e.populate();//populate vector
		e.setUsage();//set new reading
		e.save();//save data to a text file	
		e.print();//print information
	}
	else if (a == '3'){//3 - device status
		Status f;//constructor
		f.getFaults();//check data for faults
		f.print();//print information
		f.save();//save data to text file
	}
	else if (a == '4'){//4 - quit
		//nothing
	}
	else{//entered invalid option
		cout << "\nThat is not an option.\n";
		//process option again
		cin >> option;
		optionSelect(getOption());
	}
}

char Interface::getOption()
{
	return option;
}