#include "Authenticator.h"
#include "Interface.h"
#include "Internet.h"
#include "LoggerDecorator.h"
#include "LoggerFactoryM.h"
using namespace std;

int main()//cleaned
{
	unsigned exitStatus = 0; //1 = exit, 0 = no exit
	unsigned formatType; //store chosen format type
	while (!exitStatus)//loop as long as user has not exited
	{
		LoggerFactoryM *factory = new LoggerFactoryM();//initialise logger
		Logger *logger = factory->getLogger();//get logger file type
		
		cout << "Choose format : [1]-No format, [2]-HTML, [3]-Encrypt : ";
		cin >> formatType;//get logger format type

		logger = new LoggerDecorator(logger, formatType);//process new logger and format type

		std::string msg = "a message to log";
		logger->log(msg);//output message with relevant format type

		Subject s; //initialise subject class
		Authenticator a; //initialise authenticator class
		//verify user credentials 
		ProofofID *proofofID = a.authenticateUser(s);
		if (proofofID != nullptr)//if verified
		{
			//provide subject/system proof of ID
			cout << " Subject proof of ID : " << s.getproofofID() << endl;
			cout << " System proof of ID : " << proofofID->getProofID() << endl;

			//program
			Interface b;//constructor
			b.print();//prints interface
			b.optionSelect(b.getOption());
			//processes the user' selection
		}
		cout << endl << " EXIT --> Yes = 1, No = 0 : ";
		cin >> exitStatus;
		//below line shows memory being freed
		std::free(proofofID);
		//std::free(proofofID);
		//below 3 lines show destruction of objects
		delete factory;
		delete logger;
	}
	return 0;
}