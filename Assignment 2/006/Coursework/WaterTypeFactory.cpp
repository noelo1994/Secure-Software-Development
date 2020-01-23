#include "WaterTypeFactory.h"
#include "Lake.h"
#include "Sea.h"
#include "River.h"
#include<fstream>
using namespace  std;

Type *WaterTypeFactory::gettype()
{
	unsigned waterType;		//variable to store input
	bool valid = true;
	cout << "Please select a water type : [1 = Lake, 2 = Sea, 3 = River] : ";
	cin >> waterType;
	
	//**************************VALIDATION
	if (waterType > 3)
	{
		valid = false;
	}
	while (valid == false)
	{
		cout << "INVALID. Please select a water type : [1 = Lake, 2 = Sea, 3 = River] : ";
		cin >> waterType;
		if ((waterType < 4) && (waterType > 0))
		{
			valid = true;
		}
	}
	//****************************VALIDATION

	switch (waterType)
	{
	case LAKE:
		return new Lake();
		break;
	case SEA:
		return new Sea();
		break;
	case RIVER:
		return new River();
		break;
	default:
		cout << "no water\n";
		return NULL;
		break;
	}
}