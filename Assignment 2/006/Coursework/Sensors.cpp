#include "Sensors.h"
#include <cstdlib>
#include <string>
using namespace std;

static string login; //variable to save the ID (not secure)


void Sensor::SensorDisplay()
{
	Sensor::Temperature();
	Sensor::Current();
	Sensor::Depth();
	
}
void Sensor::checkAdmin(string ID) //function to take the ID and store in a variable within this class
{
	login = ID;
}
void Sensor::Temperature()
{
 	srand(time(NULL));

	int16_t temp = rand() % 30; //random number 0-29

	//****INT SECURITY*******************************
	if ((temp > INT16_MAX) || (temp < INT16_MIN)) //if for some reason int is larger than allocated (shouldn't be)
	{
		cout << "OVERFLOW! CLOSING DOWN!";
		terminate();
	}
	//***********************************************


	//To check for admin(not secure)*****************************
	int measurement = 0;
	if (login == "Admin")
	{
		cout << "Which temperature to display [1 = C, 2 = F] :";
		cin >> measurement;

		if (measurement == 1)
		{
			cout << "TEMP = " << temp << "(C)" << endl; //output temp

		}
		else if (measurement == 2)
		{
			int tempF = (temp * 1.8) + 32;
			cout << "TEMP = " << tempF << "(F)" << endl;
		}
	}
	else
	{
		cout << "TEMP = " << temp << "(C)" << endl;
	}
	//**********************************************
	


	

	if (temp < 10) // if temp is lower than 10, call heater function
	{
		Sensor::Heater();
	}

	//START OF FILE I/O*****************************
	//precaution
	const int MAX_INPUT = 10;
	const int MAX_TIMES = 1;

	//structure definition
	typedef struct
	{
		char name[MAX_INPUT];
		int displayTemp;
	}Temp_t;

	//creating array
	Temp_t TemptoSave[MAX_INPUT];

	//seeding data
	//STRING SECURITY*********
	strncpy_s(TemptoSave[0].name, "Temp:", MAX_INPUT); //secure version to copy to a string.
	//*********************
	TemptoSave[0].displayTemp = temp;

	//serialising struct 
	ofstream output_file("temperature.data", ios::binary);
	if (output_file.fail())
	{
		cout << "Could not open file for writing" << endl;
	}
	else
	{
		if (!output_file.write((char*)&TemptoSave, sizeof(TemptoSave)))
		{
			cout << "Could not write file" << endl;
		}
		else
		{
			streamsize bytesWritten = output_file.tellp();
			if (bytesWritten != sizeof(TemptoSave))
			{
				cout << "Could not write expected number of bytes" << endl;
			}
			else
			{
				cout << "\t**file written OK**" << endl;
				output_file.close();
			}
		}
	}
	//STRING SECURITY + MEMORY MANAGEMENT*************
	char *input = (char*)malloc(100);
	cout << "Would you like to display temp.data? [yes/no] "; //does user want to view the file?
	cin >> input;

	if (input == nullptr) //if it is a null pointer, should never be!
	{
		cout << "ERROR! NULL POINTER";
		terminate();
	}

	string validation(input); //pass into string to check validation

	if (validation == "yes") //if user wants to view the file
	{
		free(input);
	//END OF STRING SECURITY + MEMORY MANAGEMENT ******************
		//create struct array to hold data
		Temp_t tempLoaded[MAX_INPUT];


		//reading from file again
		ifstream input_file("temperature.data", ios::binary);
		if (input_file.fail())
		{
			cout << "Could not open file" << endl;

		}
		else
		{
			if (!input_file.read((char*)&tempLoaded, sizeof(tempLoaded)))
			{
				cout << "Could not read file" << endl;
			}
			else
			{
				streamsize bytesRead = input_file.gcount();
				if (bytesRead != sizeof(tempLoaded))
				{
					cout << "Could not read expected number of bytes" << endl;
				}
				else
				{
					input_file.close();
					//dislaying data

					for (size_t i = 0; i < MAX_TIMES; i++)
					{
						cout << "*******DATA FILE*********\n";
						cout << "Record # " << i << endl;
						cout << "Temp : " << tempLoaded[i].displayTemp << endl;
						cout << "*************************";
					}
				}
			}
		}
	}
	//END OF FILE I/O**********************************

}
void Sensor::Current()
{
	float currentspeed[5] = { 1.2343, 5.93462, 7.223, 2.12, 4.00 };
	uint16_t counter = rand() % 5;
	
	cout << "\nCurrent speed = " << setprecision(2) << currentspeed[counter] << "mph\n"; //Formatted I/O (setprecision) to display 2 bits.
}
void Sensor::Depth()
{
	//depending on the time in which the sonar signal gets back to the device 
	//distance = speed * time
	uint32_t distance;
	const uint32_t speed = 1400;
	uint32_t time[5] = { 5, 10, 13, 22, 31 };

	uint16_t count = rand() % 5; //random to select random element in array

	distance = (speed * time[count]) / 100;

	//INTEGER SECURITY***********************
	if ((UINT32_MAX / speed) * 100 < time[count]) //if to check buffer overflow
	{
		///overflow therefore handle
		cout << "OVERFLOW";
	}
	else
	{
		cout << "\nDistance = " << distance << "m" << endl;
	}
	//****************************************
}
void Sensor::Heater()
{
	cout << "Heater turned on.\n ";

}







