#include <iostream>
#include <string>
#include "WaterType.h"
#include "Lake.h"
#include "WaterTypeFactory.h"
#include "Sensors.h"
#include "Auth.h"
#include "ProofofID.h"
//#include "Permission.h"

using namespace std;

int main()
{
	//Username: Admin = Password: 321
	//Username: User = Password: 123

	User u;
	Auth a;
	ProofofID * proofofID = a.authUser(u);

	if (proofofID != nullptr) //if valid is true
	{
		WaterTypeFactory *factory = new WaterTypeFactory();
		Type *wtype = factory->gettype();

		cout << "Water Type ";
		string msg = " is selected.\n\n";
		wtype->ty(msg);

		Sensor s;		//create sensor object to call sensors
		s.SensorDisplay();

		//POINTER VULNERABILITIES*****************
		delete wtype; //delete pointer after using
		delete factory;	 //delete pointer after using
	}
	delete proofofID; //delete pointer so not pointing to empty memory
	//END OF POINTER VULNERABILITIES****************8

	system("pause");
	return 0;
}