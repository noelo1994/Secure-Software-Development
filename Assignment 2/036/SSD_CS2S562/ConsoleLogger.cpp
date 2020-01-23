#include <iostream>
#include "ConsoleLogger.h"
using namespace std;

void ConsoleLogger::log(string msg){
	cout << "Writing " << msg << " to console\n";
}