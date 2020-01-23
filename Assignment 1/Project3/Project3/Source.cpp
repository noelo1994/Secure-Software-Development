#include <string>
#include<iostream>
#include<map>
#include <ctime>
#include"time.h"
#include <chrono>
#include <thread>
#include <vector>
#include <stdlib.h> 
#include <windows.h>
#include <iomanip>
#include <fstream>


using namespace std;
class Clock
{
public:
	double logInterval = 120000;
	//chrono::steady_clock duration;
	chrono::duration<double>duration;

	void timer() 
	{
		chrono::time_point<chrono::steady_clock>start, end;
		start = chrono::high_resolution_clock::now();
		end = chrono::high_resolution_clock::now();
		duration = end - start;
		
		//if (duration > logInterval)
		//{

		//}
	}
	string getTime();
	struct Timer
	{

		Timer()
		{
	

		}
		~Timer()
		{
			//end = chrono::high_resolution_clock::now();
			//duration = end - start;

			//double ms = duration.count() * 1000.0f;
			//cout << "Timer took " << ms << "ms\n";
		}
	};
	Clock() {}
};

string Clock::getTime()
{
	string currentTime;
	struct tm newtime;
	__time64_t long_time;
	char timebuf[26];
	errno_t err;
	// Get time as 64-bit integer.
	_time64(&long_time);
	// Convert to local time.
	err = _localtime64_s(&newtime, &long_time);
	if (err)
	{
		printf("Invalid argument to _localtime64_s.");
		exit(1);
	}

	// Convert to an ASCII representation.
	err = asctime_s(timebuf, 26, &newtime);
	if (err)
	{
		printf("Invalid argument to asctime_s.");
		return "Time ERROR.\n";
	}
	currentTime = timebuf;
	currentTime = currentTime;
	return currentTime;
}
enum LoggerType { L_TEXT_FILE = 1,L_BINARY_FILE,L_CONSOLE};
enum Format { NO_FORMAT = 1, HTML_FORMAT, ENC_FORMAT };
LoggerType LOG = L_TEXT_FILE;
//Logger class 
class Logger
{
public:

	virtual void log(string msg) = 0;
private:

};

class ConsoleLogger : public Logger
{
public:
	void log(string msg);
};
void ConsoleLogger::log(string msg)
{}

class TxtFileLogger : public Logger
{
public:
	void log(std::string msg);
};
void TxtFileLogger::log(string msg)
{}

class BinFileLogger : public Logger
{
public:
	void log(string msg);
};
void BinFileLogger::log(string msg)
{
	
	
}

class LoggerDecorator : public Logger
{
private:
	//unsigned formatType;
	Logger* contents;
	

public:
	
	LoggerDecorator(Logger * alogger);
	void log(string msg);
	//virtual string formatMessage(string msg);
};
LoggerDecorator::LoggerDecorator(Logger * alogger)
{}
void LoggerDecorator::log(string msg)
{
	ofstream logTXT("SystemLog.txt", ios::app);
	if (!logTXT)
	{
		cout << "Error opening log file." << endl;
	}
	logTXT << msg;


if (LOG == L_TEXT_FILE)
{
	ofstream logTXT("UserLog.txt", ios::app);
	if (!logTXT)
	{
		cout << "Error opening log file." << endl;
	}
	logTXT << msg;


}
if (LOG == L_BINARY_FILE)
{
	ofstream logTXT("UserLog.bin", ios::app);
	if (!logTXT)
	{
		cout << "Error opening log file." << endl;
	}
	logTXT << msg;
}
if (LOG == L_CONSOLE)
{
	cout << msg;
}
}


class LoggerFactory 
{
public:
	Logger *getLogger();
};
Logger * LoggerFactory::getLogger()
{
	switch (LOG)
	{
	case L_TEXT_FILE:
		return new TxtFileLogger();
		break;
	case L_BINARY_FILE:
		return new BinFileLogger();
		break;
	case L_CONSOLE:
		return new ConsoleLogger();
		break;
	default:
		cout << "NO LOGGER";
		return NULL;
		break;
	}
}
class HTMLLogger : public LoggerDecorator
{
public:
	HTMLLogger(Logger * logger);
	void log(string msg);
	string makeHTML(string msg);
};
HTMLLogger::HTMLLogger(Logger * alogger) : LoggerDecorator(alogger)
{}
void HTMLLogger::log(string msg)
{
	msg = makeHTML(msg);
	LoggerDecorator::log(msg);
}
string HTMLLogger::makeHTML(string msg)
{
	return "<HTML><BODY><b>" + msg + "</b></BODY></HTML>";
}

class EncryptLogger : public LoggerDecorator

{
public:
	void log(string msg);
	EncryptLogger(Logger * logger);
private:
	string encryptDecrypt(string toEncrypt);
};
EncryptLogger::EncryptLogger(Logger * alogger) : LoggerDecorator(alogger)
{
}
void EncryptLogger::log(string msg)
{
	msg = encryptDecrypt(msg);
	LoggerDecorator::log(msg);
}
string EncryptLogger::encryptDecrypt(string toEncrypt)
{
	char key = 'F';
	string output = toEncrypt;
	for (uint16_t i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key;
	}
	return output;
}

class Subject//subject class
{
private:
	string id;//string to hold user entered id
	string password;//string to hold user entered passwoed
public:
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
//Subject::Subject(string aId, string aPass) : id(aId), password(aPass) {}

Subject::Subject()
{}
string Subject::getId() { return id; };//returns user entered id
string Subject::getPassword() { return password; }
void Subject::setId()
{
	cout << "Enter UserID: ";//message to request username
	cin >> id;//saves to id;
}
void Subject::setPassword()
{
	cout << "Enter Password: ";//message to request password
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
class Appliance// : public SmartMeter
{

public:
	Appliance();

	void calculateGasUsage();//return gas usage per hour
	void calculateElecUsage();//return electric useage per hour
	void calculateWaterUsage();//return water usage per hour
	void calculateTotalUsage();

	void calculateTotalGasPrice();//calculates the total gas price per hour by multiplying the usage by the price per unit
	void calculateTotalElecPrice();//calculates the total electric price per hour by multiplying the usage by the price per unit
	void calculateTotalWaterPrice();//calculates the total gas price per hour by multiplying the usage by the price per unit
	void calculateTotalUsagePrice();

	void calculateTotalGasPriceWithService();
	void calculateTotalElecPriceWithService();
	void calculateTotalWaterPriceWithService();
	void calculateTotalUsagePriceWithService();

	double getGasUsage() { return totalGasUsedPHour; }
	double getElecUsage() { return totalElecUsedPHour; }
	double getWaterUsage() { return totalWaterUsedPHour; }

	double getTotalGasPricePHour() { return totalGasPrice; }
	double getTotalElecPricePHour() { return totalElecPrice; }
	double getTotalWaterPricePHour() { return totalWaterPrice; }
	double getTotalPricePHour() { return totalCombinedPrice; }

	double getGasPricePerUnit() { return gasPricePUnit; }
	double getElecPricePerUnit() { return elecPricePUnit; }
	double getWaterPricePerUnit() { return waterPricePUnit; }

	double getGasServiceCharge() { return gasServiceCharge; }
	double getElecServiceCharge() { return elecServiceCharge; }
	double getWaterSewageCharge() { return waterSewageCharge; }

	double getTotalGasPriceWithService() { return totalGasPriceWithService; }
	double getTotalElecPriceWithService() { return totalElecPriceWithService; }
	double getTotalWaterPriceWithService() { return totalWaterPriceWithService; }
	double getTotalPriceWithService() { return totalPriceWithService; }

	void setGasServiceCharge(double newNum) { gasServiceCharge = newNum; }
	void setElecServiceCharge(double newNum) { elecServiceCharge = newNum; }
	void setWaterSewageCharge(double newNum) { waterSewageCharge = newNum; }

	void setGasPricePUnit(double newNum);
	void setElecPricePUnit(double newNum);
	void setWaterPricePUnit(double newNum);

	void reCalculate();

private:
	double totalGasUsedPHour = 0;//Total units of gas being used
	double totalElecUsedPHour = 0;//Total units of electric used
	double totalWaterUsedPHour = 0;//Total units of water being used

	double totalGasPrice = 0;//T
	double totalElecPrice = 0;
	double totalWaterPrice = 0;
	double totalCombinedPrice = 0;

	double totalGasPriceWithService = 0;
	double totalElecPriceWithService = 0;
	double totalWaterPriceWithService = 0;
	double totalPriceWithService = 0;
	
	//Vectors to hold the appliances
	vector<string>name;//name of appliances
	vector<double>gasPHour;//gas energy used per hour
	vector<double>elecPHour;//electric energy used per hour
	vector<double>waterPHour;//water used per hour
	vector<bool>state;//to store if the appliance is on or off
	double totalPHour;
	//price per unit, as per energy supplier, these are example values that can be changed
	double gasPricePUnit = 3.87;
	double elecPricePUnit = 16.17;
	double waterPricePUnit = 1.35;

	double gasServiceCharge = 0.1601;
	double elecServiceCharge = 0.15;
	double waterSewageCharge = 0;

	uint32_t size;
	//
};
Appliance::Appliance()
{
	name.push_back("Heating");gasPHour.push_back(4.5);elecPHour.push_back(0); waterPHour.push_back(0.00227); state.push_back(0);////////////
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

	calculateGasUsage();//return gas usage per hour
	calculateElecUsage();//return electric useage per hour
	calculateWaterUsage();//return water usage per hour
	calculateTotalUsage();

	calculateTotalGasPrice();
	calculateTotalElecPrice();
	calculateTotalWaterPrice();
	calculateTotalUsagePrice();
}

//NUMBER OF UNITS USED
void Appliance::calculateGasUsage()
{	
	size = gasPHour.size();
	totalGasUsedPHour = 0;
	for (uint16_t i = 0; i < size; i++)
	{
		if (state[i] == 1)
		{
			totalGasUsedPHour = totalGasUsedPHour + gasPHour[i];
		}
	}
	
}
void Appliance::calculateElecUsage()
{
	size = elecPHour.size();
	totalElecUsedPHour = 0;
	for (uint16_t i = 0; i < size; i++)
	{
		if (state[i] == 1)
		{
			totalElecUsedPHour = totalElecUsedPHour + elecPHour[i];
		}
	}

}
void Appliance::calculateWaterUsage()
{	
	size = waterPHour.size();
	totalWaterUsedPHour = 0;
	for (uint16_t i = 0; i < size; i++)
	{
		if (state[i] == 1)
		{
			totalWaterUsedPHour = totalWaterUsedPHour + waterPHour[i];
		}
	}
}
void Appliance::calculateTotalUsage()
{
	totalPHour = totalWaterUsedPHour + totalGasUsedPHour + totalElecUsedPHour;
}
//PRICE PER HOUR 
void Appliance::calculateTotalGasPrice()//calculates the price of your gas usage from your price per unit and how much you have used
{
	totalGasPrice = 0;
	totalGasPrice = (totalGasUsedPHour / 100 * gasPricePUnit);
}
void Appliance::calculateTotalElecPrice()//calculates the price of your electric usage from your price per unit and how much you have used
{
	totalElecPrice = 0;
	totalElecPrice = (totalElecUsedPHour / 100 * elecPricePUnit);
}
void Appliance::calculateTotalWaterPrice()//calculates the price of your water usage from your price per unit and how much you have used
{
	totalWaterPrice = 0;
	totalWaterPrice = (totalWaterUsedPHour * waterPricePUnit);
}
void Appliance::calculateTotalUsagePrice()//calculates and saves total price per hour
{
	totalCombinedPrice = 0;
	totalCombinedPrice = totalCombinedPrice + totalGasPrice + totalElecPrice + totalWaterPrice;
}

void Appliance::calculateTotalGasPriceWithService()
{
	totalGasPriceWithService = totalGasPrice + gasServiceCharge;
}

void Appliance::calculateTotalElecPriceWithService()
{
	totalElecPriceWithService = totalElecPrice + elecServiceCharge;
}

void Appliance::calculateTotalWaterPriceWithService()
{
	waterSewageCharge = (totalWaterPrice / 100) * 80;
	totalWaterPriceWithService = totalWaterPrice + waterSewageCharge;
}

void Appliance::calculateTotalUsagePriceWithService()
{
	totalPriceWithService = totalGasPriceWithService + totalElecPriceWithService + totalWaterPriceWithService;	
}

void Appliance::setGasPricePUnit(double newNum)//sets gas unit price to value passed in
{
	this->gasPricePUnit = newNum;
}
void Appliance::setElecPricePUnit(double newNum)//sets electric unit price to value passed in
{
	this->elecPricePUnit = newNum;
}
void Appliance::setWaterPricePUnit(double newNum)//sets water unit price to value passed in
{
	this->waterPricePUnit = newNum;
}

void Appliance::reCalculate()
{
	calculateElecUsage();
	calculateGasUsage();
	calculateWaterUsage();
	calculateTotalUsage();

	calculateTotalGasPrice();
	calculateTotalElecPrice();
	calculateTotalWaterPrice();
	calculateTotalUsagePrice();

	calculateTotalGasPriceWithService();
	calculateTotalElecPriceWithService();
	calculateTotalWaterPriceWithService();
	calculateTotalGasPriceWithService();
}

class SmartMeter : public Appliance
{
public:
	SmartMeter()
	{}
	uint16_t mainMenu();
private:

	Appliance app;
	Authenticator a;
	Subject s;
	Clock c;

	string log;
	uint16_t userChoice;
	unsigned userExited = 0;
	unsigned formatType=1;
	bool authenticated = false;
	void logMessage(string);
	void changeLogger();
	void display();
	uint16_t settingsMenu();
	void gasMenu();
	void elecMenu();
	void waterMenu();
	void applianceMode();
	void recordGasHistory(string);
	void recordElecHistory(string);
	void recordWaterHistory(string);
	void diaplayGasHistory();
	void diaplayElecHistory();
	void diaplayWaterHistory();
	void logHistory();
};
const uint16_t MENU_QUIT = 7;

void SmartMeter::logMessage(string passedMessage)
{
			LoggerFactory *factory = new LoggerFactory();
			Logger *logger = factory->getLogger();
			
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
			string msg = passedMessage + c.getTime();
			logger->log(msg);
}

void SmartMeter::changeLogger()
{
	cout << "\n SELECT FORMAT [1:NO FORMAT, 2:HTML, 3:ENCRYPT]: ";
	uint16_t input;
	cin >> formatType;

	cout << "\n SELECT LOGGER TYPE [1:TXT FILE, 2:BIN FILE, 3:CONSOLE]: ";
	cin >> userChoice;
	LoggerFactory *factory = new LoggerFactory();
	LOG = static_cast<LoggerType>(userChoice);
}

void SmartMeter::display()
{
	reCalculate();
	cout << c.getTime() << endl;
	cout << "Please select from the following options: " << endl;
	cout << "****************************************************************************************************" << endl;
	cout << "*                                                                                                  *";
	cout << endl << "*";
	cout << "				Total Utility Cost:                                                * " << endl << "*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << "					" << (char)156<< setprecision(3) << app.getTotalPricePHour();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "						   *";
	cout << endl << "*                                                                                                  *";
	cout << endl << "*                                                                                                  *" << endl << "*";
	cout << "1.Gas Price			2.Electric Price			3.Water price" << "              *" << endl;
	cout << "*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << setprecision(3) << app.getGasUsage() << "kWh" << "				" << setprecision(3) << app.getElecUsage() << "kWh" << "				" << setprecision(3) << app.getWaterUsage() << "M" << (char)252 << "   		   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "*" << endl << "*";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	cout << setprecision(3) << (char)156 << app.getTotalGasPricePHour() << " P/Hour" << "			" << (char)156 << setprecision(3)<< app.getTotalElecPricePHour() << " P/Hour" << "				" << (char)156 << setprecision(3) << app.getTotalWaterPricePHour() << " P/Hour            ";
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
	logHistory();

}
uint16_t SmartMeter::settingsMenu()
{
	system("cls");
		cout << c.getTime() << endl;
		cout << "***************************************************************************************************" << endl;
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                     Settings                                                     *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "* 1.Logger                                                                                         *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "* 2.Users                                                                                          *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl << "*                                                                                                  *";
		cout << endl<< "***************************************************************************************************" << endl;
		cin >> userChoice;
		return userChoice;
}
void SmartMeter::gasMenu()
{
	double newNumber;
	do {
		app.reCalculate();
		system("cls");
		cout << c.getTime() << endl;
		cout << "***************************************************************************************************" << endl;
		cout << "*                                                                                                 *";
		cout << endl << "*                                    Gas Menu							  *";
		cout << endl << "*Units In Use:                                                                                    *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getGasUsage();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                                              *";
		cout << endl << "*Hourly Cost:                                                                                     *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getTotalGasPricePHour();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)  ;
		cout <<"                                                                                          *";
		cout << endl << "*Hourly Cost with service charge:                                                                 *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getTotalGasPriceWithService();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                                          *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 1.Price/KWh: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getGasPricePerUnit();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                               *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 2.Service Charge/Day: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getGasServiceCharge();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                    *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 3.History                                                                                       *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 7.Back                                                                                          *";
		cout << endl << "*                                                                                                 *";
		cout << endl<< "***************************************************************************************************" << endl;
		cin >> userChoice;
		if (userChoice == 1)
		{
			cout << "What would you like the new Price/KWh to be: ";
			cin >> newNumber;
			app.setGasPricePUnit(newNumber);
			log = "Set new gas price per unit to " + to_string(newNumber), logMessage(log);
			app.reCalculate();
		}
		if (userChoice == 2)
		{
			cout << "What would you like the new daily service charge to be in pounds: ";
			cin >> newNumber;
			log = "Set new daily gas service charge  to " + to_string(newNumber), logMessage(log);
			app.setGasServiceCharge(newNumber);
			app.reCalculate();
		}
		if (userChoice == 3)
		{
			diaplayGasHistory();
		}
		logHistory();
	}
	while (userChoice != MENU_QUIT);
}
void SmartMeter::elecMenu()
{
	double newNumber;
	do {
		app.reCalculate();
		system("cls");
		cout << c.getTime() << endl;
		cout << "***************************************************************************************************" << endl;
		cout << "*                                                                                                 *";
		cout << endl << "*                                   Electric Menu							  *";
		cout << endl << "*Units In Use:                                                                                    *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getElecUsage();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                                              *";
		cout << endl << "*Hourly Cost:                                                                                     *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getTotalElecPricePHour();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                                          *";
		cout << endl << "*Hourly Cost with service charge:                                                                 *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getTotalElecPriceWithService();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                                          *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 1.Price/KWh: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getElecPricePerUnit();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                               *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 2.Service Charge/Day: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getElecServiceCharge();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                    *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 3.History                                                                                       *";
		cout << endl << "* 4.Targets                                                                                       *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 7.Back                                                                                          *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "***************************************************************************************************" << endl;
		cin >> userChoice;
		if (userChoice == 1)
		{
			cout << "What would you like the new Price/KWh to be: ";
			cin >> newNumber;
			app.setElecPricePUnit(newNumber);
			log = "Set electric price per unit " + to_string(newNumber), logMessage(log);
			app.reCalculate();
		}
		if (userChoice == 2)
		{
			cout << "What would you like the new daily service charge to be in pounds: ";
			cin >> newNumber;
			log = "Set new electric service charge " + to_string(newNumber), logMessage(log);
			app.setElecServiceCharge(newNumber);
			app.reCalculate();
		}
		if (userChoice == 4)
		{

		}
		logHistory();
	} while (userChoice != MENU_QUIT);
}
void SmartMeter::waterMenu()
{
	double newNumber;
	do {
		app.reCalculate();
		system("cls");
		cout << c.getTime() << endl;
		cout << "***************************************************************************************************" << endl;
		cout << "*                                                                                                 *";
		cout << endl << "*                                    Water Menu							  *";
		cout << endl << "*Units In Use:                                                                                    *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getWaterUsage();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                                              *";
		cout << endl << "*Hourly Cost:                                                                                     *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getTotalWaterPricePHour();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                                          *";
		cout << endl << "*Hourly Cost with service charge:                                                                 *";
		cout << endl << "* ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getTotalWaterPriceWithService();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                                          *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 1.Price/KWh: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getWaterPricePerUnit();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                               *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 2.Service Charge/Day: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
		cout << setprecision(3) << app.getWaterSewageCharge();
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "                                                                    *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 3.History                                                                                       *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "* 7.Back                                                                                          *";
		cout << endl << "*                                                                                                 *";
		cout << endl << "***************************************************************************************************" << endl;
		cin >> userChoice;
		if (userChoice == 1)
		{
			cout << "What would you like the new Price/KWh to be: ";
			cin >> newNumber;
			app.setWaterPricePUnit(newNumber);
			log = "Set new water price per unit to " + to_string(newNumber), logMessage(log);
			app.reCalculate();
		}
		if (userChoice == 2)
		{
			cout << "What would you like the new sewage charge to be in pounds: ";
			cin >> newNumber;
			app.setWaterSewageCharge(newNumber);
			log = "Set new Sewage charge  to " + to_string(newNumber), logMessage(log);
			app.reCalculate();
		}
		logHistory();
	} while (userChoice != MENU_QUIT);
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

void SmartMeter::recordGasHistory(string recordToInput)
{
	ofstream gHistory("gasHistory.txt", ios::app);
	if (!gHistory)
	{
		cout << "Error opening log file." << endl;
	}
	gHistory << recordToInput;
}

void SmartMeter::recordElecHistory(string recordToInput)
{
	ofstream eHistory("elecHistory.txt", ios::app);
	if (!eHistory)
	{
		cout << "Error opening log file." << endl;
	}
	eHistory << recordToInput;
}

void SmartMeter::recordWaterHistory(string recordToInput)
{
	ofstream wHistory("waterHistory.txt", ios::app);
	if (!wHistory)
	{
		cout << "Error opening log file." << endl;
	}
	wHistory << recordToInput;
}

void SmartMeter::diaplayGasHistory()
{
	system("cls");
	string line;
	ifstream historyFile("gasHistory.txt");
	if (historyFile.is_open())
	{
		while (getline(historyFile, line))
		{
			cout << line << '\n';
		}
		historyFile.close();
	}
	else cout << "Unable to open file";

	cout << endl;
	system("pause");
}

void SmartMeter::diaplayElecHistory()
{
	system("cls");
	string line;
	ifstream historyFile("elecHistory.txt");
	if (historyFile.is_open())
	{
		while (getline(historyFile, line))
		{
			cout << line << '\n';
		}
		historyFile.close();
	}
	else cout << "Unable to open file";

	cout << endl;
	system("pause");
}

void SmartMeter::diaplayWaterHistory()
{
	system("cls");
	string line;
	ifstream historyFile("waterHistory.txt");
	if (historyFile.is_open())
	{
		while (getline(historyFile, line))
		{
			cout << line << '\n';
		}
		historyFile.close();
	}
	else cout << "Unable to open file";

	cout << endl;
	system("pause");
}

void SmartMeter::logHistory()
{
	reCalculate();
	string msg = "Total gas price per hour = " + to_string(getTotalGasPricePHour()) + c.getTime(); recordGasHistory(msg);
	msg = "Total elec price per hour = " + to_string(getTotalElecPricePHour()) + c.getTime(); recordElecHistory(msg);
	msg = "Total water price per hour = " + to_string(getTotalWaterPricePHour()) + c.getTime(); recordWaterHistory(msg);
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
			log = "Failed login by " + s.getId() + "\t\t";
			logMessage(log);
		}
		if (authenticated == true)
		{
			cout << "If you want to enter appliance mode type 555" << endl;
			log = "Sucessfull login by " + s.getId() + "\t\t";
			logMessage(log);
		}
		display();

		cin >> input;
		if (input == 1 && authenticated == true)
		{
			system("cls");
			this->gasMenu();
			system("cls");
		}
		if (input == 2 && authenticated == true)
		{
			system("cls");
			this->elecMenu();
			system("cls");
		}
		if (input == 3 && authenticated == true)
		{
			system("cls");
			this->waterMenu();
			system("cls");
		}
		if (input == 4 && authenticated == false)
		{
			system("cls");
			s.setDetails();
			authenticated = a.authenticateUser(s);
			system("cls");
		}
		if(input == 4 && authenticated == true)
		{
			system("cls");
			cout << "You are already logged in " << s.getId() << endl;
		}
		if (input == 5)
		{
			if (this->settingsMenu()==1)
			{
				this->changeLogger();
			}
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
		else
			cout << "You need to log in to use these options. \n";
	} while (input != MENU_QUIT);

	return input;
}
void startup()
{
	cout << "Starting system..." << endl;
	cout << "Initiating users..." << endl;
	cout << "Initiating logger..." << endl;
	cout << "initiating water sensor..." << endl;
	cout << "initiating gas sensor..." << endl;
	cout << "initiating electric sensor..." << endl;
	cout << endl << "System startup complete!" << endl;
}
uint16_t main()
{
	uint16_t uint_userchoice = 0;
	startup();
	cout << endl;
	system("pause");
	SmartMeter SM;
	Clock T;
	
	while (uint_userchoice != 7)
	{
		uint_userchoice = SM.mainMenu();
	}
	return 0;
}



