#include <string>
#include<iostream>
#include<map>
#include <ctime>
#include"time.h"
#include <vector>
#include <stdlib.h> 
#include <windows.h>

#include "Authenticator.h"
#include "Logger.h"

using namespace std;
class Clock
{
public:

	void getTime();
	Clock() {}
};

void Clock::getTime()
{
/*	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("Current local time and date: %s", asctime(timeinfo));*/
	cout << "THE TIME ISSSSSSSS" << endl;

	
}

//Subject::Subject(string aId, string aPass) : id(aId), password(aPass) {}


class Appliance //: public SmartMeter
{

public:
	//void setGasUsage(double gasPH);//set how much gas appliance uses per hour (meters cubed)
	//void setElecUsage(double elecPH);//set how much electric appliance uses per hour (kw/h)
	//void setWaterUsage(double waterPH);//set how much water appliance uses per hour (meters cubed)
	//void setName(string name);
	Appliance();



	double getGasUsage();//return gas usage per hour
	double getElecUsage();//return electric useage per hour
	double getWaterUsage();//return water usage per hour
	double getTotalUsage();

	double getTotalGasPrice();
	double getTotalElecPrice();
	double getTotalWaterPrice();
	double getTotalUsagePrice();

	double getGasPricePerUnit();
	double getElecPricePerUnit();
	double getWaterPricePerUnit();


private:


	//string name;
	double TotalGasPHour = 0;
	double TotalElecPHour = 0;
	double TotalWaterPHour = 0;

	double TotalGasPrice = 0;
	double TotalElecPrice = 0;
	double TotalWaterPrice = 0;
	double totalPricePHour = 0;

	vector<string>name;
	vector<double>gasPHour;
	vector<double>elecPHour;
	vector<double>waterPHour;
	vector<bool>state;

	double totalPHour;
	double gasPricePUnit = 3.87;
	double elecPricePUnit = 16.17;
	double waterPricePUnit = 1.35;
	//
};
Appliance::Appliance()
{
	name.push_back("Heating"); gasPHour.push_back(4.5); elecPHour.push_back(0); waterPHour.push_back(0.00227); state.push_back(1);////////////
	name.push_back("Hob1"); gasPHour.push_back(0.7); elecPHour.push_back(0); waterPHour.push_back(0); state.push_back(1);
	name.push_back("Hob2"); gasPHour.push_back(0.8); elecPHour.push_back(0); waterPHour.push_back(0); state.push_back(1);
	name.push_back("Hob3"); gasPHour.push_back(0.9); elecPHour.push_back(0); waterPHour.push_back(0); state.push_back(1);/////////////////////
	name.push_back("Hob4"); gasPHour.push_back(1.0); elecPHour.push_back(0); waterPHour.push_back(0); state.push_back(1);
	name.push_back("Shower"); gasPHour.push_back(0); elecPHour.push_back(12), waterPHour.push_back(0.02); state.push_back(1);
	name.push_back("Bedroom TV"); gasPHour.push_back(0); elecPHour.push_back(0.3), waterPHour.push_back(0); state.push_back(1);
	name.push_back("Computer"); gasPHour.push_back(0); elecPHour.push_back(0.2), waterPHour.push_back(0); state.push_back(1);
	name.push_back("Ustairs Lights"); gasPHour.push_back(0); elecPHour.push_back(0.1), waterPHour.push_back(0); state.push_back(1);
	name.push_back("Downstairs Lights"); gasPHour.push_back(0); elecPHour.push_back(0.1), waterPHour.push_back(0); state.push_back(1);///////////////////////////
	name.push_back("Livingroom TV"); gasPHour.push_back(0); elecPHour.push_back(0.3); waterPHour.push_back(0); state.push_back(1);
	name.push_back("Game Console"); gasPHour.push_back(0); elecPHour.push_back(0.17); waterPHour.push_back(0); state.push_back(1);
	name.push_back("Washing Machine"); gasPHour.push_back(0); elecPHour.push_back(3.0); waterPHour.push_back(0); state.push_back(1);
	name.push_back("Dishwasher"); gasPHour.push_back(0); elecPHour.push_back(1.0); waterPHour.push_back(0); state.push_back(1);
	name.push_back("Tumble Drier"); gasPHour.push_back(0); elecPHour.push_back(3.0); waterPHour.push_back(0); state.push_back(1);//////////////////////
	name.push_back("Hoover"); gasPHour.push_back(0); elecPHour.push_back(0.75); waterPHour.push_back(0.00227); state.push_back(1);
	name.push_back("Oven"); gasPHour.push_back(0); elecPHour.push_back(2.3); waterPHour.push_back(0.00227); state.push_back(1);
	name.push_back("Toilet"); gasPHour.push_back(0); elecPHour.push_back(0); waterPHour.push_back(0.022); state.push_back(1);
	name.push_back("Hose pipe"); gasPHour.push_back(0); elecPHour.push_back(0); waterPHour.push_back(0.36); state.push_back(1);
	name.push_back("Kitchen Cold"); gasPHour.push_back(0); elecPHour.push_back(0); waterPHour.push_back(0.36); state.push_back(1);
	name.push_back("Kitchen Hot"); gasPHour.push_back(3.4); elecPHour.push_back(0); waterPHour.push_back(0.36); state.push_back(1);////////////////
	name.push_back("Bathroom Cold"); gasPHour.push_back(0); elecPHour.push_back(0); waterPHour.push_back(0.3); state.push_back(1);
	name.push_back("Bathroom Hot"); gasPHour.push_back(3.2); elecPHour.push_back(0); waterPHour.push_back(0.3); state.push_back(1);
	name.push_back("Bath Cold"); gasPHour.push_back(0); elecPHour.push_back(0); waterPHour.push_back(0.4); state.push_back(1);
	name.push_back("Bath Hot"); gasPHour.push_back(3.5); elecPHour.push_back(0); waterPHour.push_back(0.4); state.push_back(1);

	getGasUsage();//return gas usage per hour
	getElecUsage();//return electric useage per hour
	getWaterUsage();//return water usage per hour
	getTotalUsage();

	getTotalGasPrice();
	getTotalElecPrice();
	getTotalWaterPrice();
	getTotalUsagePrice();
}

double Appliance::getGasUsage()
{	/*gasPHour = rand() % 100 + 1;
	gasPHour = gasPHour / 100;*/
	//return gasPHour;
	for (int i = 0; i < gasPHour.size(); i++)
	{
		if (state[i] == 1)
		{
			TotalGasPHour = TotalGasPHour + gasPHour[i];
		}
	}
	return TotalGasPHour;
}
//
double Appliance::getElecUsage()
{	/*elecPHour = rand() % 100 + 1;
	elecPHour = elecPHour / 100;*/
	//return elecPHour;
	for (int i = 0; i < elecPHour.size(); i++)
	{
		if (state[i] == 1)
		{
			TotalElecPHour = TotalElecPHour + elecPHour[i];
		}
	}
	return TotalElecPHour;
}

double Appliance::getWaterUsage()
{	/*waterPHour = rand() % 100 + 1;
	waterPHour = waterPHour / 100;*/
	//return gasPHour;
	for (int i = 0; i < waterPHour.size(); i++)
	{
		if (state[i] == 1)
		{
			TotalWaterPHour = TotalWaterPHour + waterPHour[i];
		}
	}
	return TotalWaterPHour;
}
double Appliance::getTotalUsage()
{
	totalPHour = TotalWaterPHour + TotalGasPHour + TotalElecPHour;
	return totalPHour;
}
double Appliance::getTotalGasPrice()
{
	TotalGasPrice = (TotalGasPHour / 100 * gasPricePUnit);
	return TotalGasPrice;
}
double Appliance::getTotalElecPrice()
{
	TotalElecPrice = (TotalElecPHour / 100 * elecPricePUnit);
	return TotalElecPrice;
}
double Appliance::getTotalWaterPrice()
{
	TotalWaterPrice = (TotalWaterPHour * waterPricePUnit);
	return TotalWaterPrice;
}
double Appliance::getTotalUsagePrice()
{
	totalPricePHour = totalPricePHour + TotalGasPrice + TotalElecPrice + TotalWaterPrice;
	return totalPricePHour;
}

double Appliance::getGasPricePerUnit()
{
	return gasPricePUnit;
}

double Appliance::getElecPricePerUnit()
{
	return elecPricePUnit;
}

double Appliance::getWaterPricePerUnit()
{
	return waterPricePUnit;
}






class SmartMeter
{
public:
	SmartMeter()
	{
	
	}

	uint16_t mainMenu();
private:
	Appliance app;
	Authenticator a;
	Subject s;
	Clock c;

	bool authenticated = false;

	double gasServiceCharge =0;
	double elecServiceCharge = 0;
	double waterServiceCharge = 0;

	void display();
	void gasMenu();
	void elecMenu();
	void waterMenu();
	void applianceMode();
};
const uint16_t MENU_QUIT = 7;

void SmartMeter::display()
{

	


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
	cout << endl << "* 1.Price/KWh: " << app.getGasPricePerUnit()<<"                                                                                                *"; 
	cout << endl << "*                                                                                                  *";
	cout << endl << "* 2.Service Charge/Day: "<<gasServiceCharge <<"                                                                            *";
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
	system("pause");
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
		cout << "In appliance mode you can turn on/off appliances and see the meter ajust. \nNote this mode is to simulate the user switching appliances on/off." << endl << endl;


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
			this->gasMenu();
		}
		if (input == 2)
		{
			system("cls");
			this->elecMenu();
		}
		if (input == 3)
		{
			system("cls");
			this->waterMenu();
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
		uint_userchoice = SM.mainMenu();
	}

	unsigned userExited = 0;
	unsigned formatType;

	while (!userExited)
	{
		LoggerFactory *factory = new LoggerFactory();
		Logger *logger = factory->getLogger();

		cout << "\n SELECT FORMAT [1:NO FORMAT, 2:HTML, 3:ENCRYPT]: ";
		cin >> formatType;

		switch (formatType)
		{
		case NO_FORMAT:
			logger = new LoggerDecorator(logger);
			break;
		case HTML_FORMAT:
			logger = new HTMLLogger(logger);
			break;
		case ENC_FORMAT:
			logger = new EncryptLogger(logger);
			break;
		default:
			cout << "NO LOGGER";
			break;
		}


		string msg = "a message to log";
		logger->log(msg);
		cout << "\n EXIT Yes = 1, No = 0 : ";
		cin >> userExited;

	}
	return 0;
}



