#include"SmartMeter.h"
#include "Appliance.h"
#include "Authenticator.h"
#include "Clock.h"
#include <iostream>
#include <windows.h>
#include <stdlib.h> 
#include <string>

using namespace std;

const uint16_t MENU_QUIT = 7;

void SmartMeter::display()
{

	Appliance app;


	cout << "Please select from the following options: " << endl;
	cout << "****************************************************************************************************" << endl;
	cout << "*                                                                                                  *";
	cout << endl << "*";
	cout << "				Total Utility Cost:                                                * " << endl << "*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "					" << (char)156 << app.getTotalUsagePrice();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "						   *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *" << endl << "*";
	cout << "1.Gas Price			2.Electric Price			3.Water price" << "              *" << endl;
	cout << "*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << app.getGasUsage() << "kWh" << "				" << app.getElecUsage() << "kWh" << "				" << app.getWaterUsage() << "M" << (char)252 << "   		   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "*" << endl << "*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << (char)156 << app.getTotalGasPrice() << " P/Hour" << "			" << (char)156 << app.getTotalElecPrice() << " P/Hour" << "				" << (char)156 << app.getTotalWaterPrice() << " P/Hour            ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "*";

	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*";
	cout << "4.Login                                                                                           *" << endl;
	cout << "*                                                                                                  *" << endl << "*";
	cout << "5.Settings                                                                                        *" << endl;
	cout << "*                                                                                                  *" << endl << "*";
	cout << "7.Quit                                                                                            *" << endl;
	cout << "*                                                                                                  *" << endl << "*";



	cout << "***************************************************************************************************" << endl;
}
void SmartMeter::gasMenu()
{
	cout << "***************************************************************************************************" << endl;
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                    Gas Menu                                                         *";
	cout << endl << "*                                                                                                 *";
	cout << endl << "*                                                                                                  *";
	//cout << endl << "* 1.Price/KWh:" << app.gas                                                                                                 *";
		cout << endl << "*                                                                                                  *";
	cout << endl << "* 2.Service Charge/Day                                                                            *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "* 3.History                                                                                         *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *";
	cout << "***************************************************************************************************" << endl;
}
void SmartMeter::elecMenu()
{

	cout << "***************************************************************************************************" << endl;

	cout << "***************************************************************************************************" << endl;
}
void SmartMeter::waterMenu()
{
	cout << "***************************************************************************************************" << endl;

	cout << "***************************************************************************************************" << endl;

}
void SmartMeter::applianceMode()
{
	string input;
	do
	{
		system("cls");
		cout << "In appliance mode you can turn on/off appliances and see the meter ajust. Note this mode is to simulate the user switching appliances on/off." << endl << endl;


		display();
		cin >> input;
	} while (input != "7");

}

uint16_t SmartMeter::mainMenu()
{
	system("cls");
	uint16_t input;
	//
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	Authenticator a;
	Subject s;
	Clock c;

	bool authenticated = false;
	s.setDetails();
	authenticated = a.authenticateUser(s);
	do
	{




		input = 0;

		cout << "Welcome to the smartest smart meter!" << endl;




		if (authenticated != true)
		{
			cout << "You are not logged in, please login to make any changes." << endl;
		}
		c.getTime();

		if (authenticated == true)
		{
			cout << "If you want to enter appliance mode type 555" << endl;
		}

		this->display();

		cin >> input;
		if (input == 1)
		{
			system("cls");
		}
		if (input == 2)
		{
			system("cls");
		}
		if (input == 3)
		{
			system("cls");
		}
		if (input == 4 && authenticated == false)
		{
			system("cls");
			s.setDetails();
			authenticated = a.authenticateUser(s);
		}
		else
		{
			system("cls");
			cout << "You are already logged in " << s.getId() << endl;
		}
		if (input == 5)
		{
			system("cls");
		}
		if (input == 6)
		{
			system("cls");
		}
		if (input == 7)
		{
			system("cls");
		}
		if (input == 555 && authenticated == true)
		{
			applianceMode();
		}
	} while (input != MENU_QUIT);

	return input;

}

