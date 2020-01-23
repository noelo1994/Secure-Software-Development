#include "LoggerFactoryM.h"
#include "TxtFileLogger.h"
#include "ConsoleLogger.h"
#include "BinFileLogger.h"
using namespace std;

Logger *LoggerFactoryM::getLogger(){
	unsigned loggerType;//variable to store input
	cout << "\nChoose logger : [1]-txt file, [2]-bin file, [3]-console : ";
	cin >> loggerType;//store input
	switch (loggerType){//check logger type
	case L_TEXT_FILE:
		return new TxtFileLogger();
		break;//text file logger
	case L_BIN_FILE:
		return new BinFileLogger();
		break;//bin file logger
	case L_CONSOLE:
		return new ConsoleLogger();
		break;//console logger
	default:
		cout << "No Logger" << endl;
		return NULL;//else no logger
		break;
	}
}