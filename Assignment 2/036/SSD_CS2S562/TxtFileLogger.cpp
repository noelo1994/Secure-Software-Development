#include <iostream>
#include "TxtFileLogger.h"
using namespace std;

void TxtFileLogger::log(string msg){
	cout << "Writing " << msg << " to a text file\n";
}