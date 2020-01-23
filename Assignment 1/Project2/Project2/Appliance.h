#pragma once
#include<vector>
#include<string>

class Appliance
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