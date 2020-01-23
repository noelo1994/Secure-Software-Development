#include "Status.h"
using namespace std;

Status::Status(){}

void Status::print()
{
	//get and print device status information
	cout << "\n	STATUS";
	cout << "\nSupply Voltage : " << getSupplyVoltage() << " volts.";
	cout << "\nInternal Temperature : " << getIntTemp() << " degrees.\n";
	cout << "\nFaults : " << getFaults() << endl;
}

int Status::getSupplyVoltage()
{
	srand(static_cast<unsigned int>(time(NULL)));//initialise random seed
	supplyVoltage = 120 + (rand() % 120);//random number
	return supplyVoltage;
}

int Status::getIntTemp()
{
	srand(static_cast<unsigned int>(time(NULL)));//initialise random seed
	intTemp = 60 + (rand() % 60);//random number
	return intTemp;
}

std::string Status::getFaults()
{
	if (supplyVoltage < 140){//if voltage is low
		fault = "Supply voltage running low";
		if (intTemp > 95){//and the internal temperature is high
			fault = "Supply voltage running low + internal temperature running high";
		}
	}
	else if (supplyVoltage > 215){//if voltage is high
		fault = "Supply voltage is high";
		if (intTemp > 95){//and the internal temperature is high
			fault = "Supply voltage and internal temperature running high";
		}
	}
	else if (intTemp > 95){//if internal temperature is high
		fault = "Internal temperature is high";
	}
	else{//if there are no faults
		fault = "No faults\n";
	}
	return fault;
}

void Status::save()
{
	std::fstream myfile("DevState.txt", ios::out);//creating a text file
	if (myfile.is_open()){//if file is open
		//write information to text file
		myfile << "Device State. ";
		myfile << "\nInternal temperature : " << intTemp;
		myfile << "\nSupply voltage : " << supplyVoltage;
		myfile << "\nFaults : " << fault << endl;
		myfile.close();//close file
		return;
	}
	//next 4 lines protect the file if it hasn't been closed properly
	if (myfile.fail()){//if file failed
		cout << "\nFile failed. ";
		std::terminate();//terminate
	}
}
