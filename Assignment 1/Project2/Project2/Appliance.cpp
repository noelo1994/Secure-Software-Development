#include "Appliance.h"
#include "Authenticator.h"
#include <iostream>
#include <vector>
using namespace std;

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


