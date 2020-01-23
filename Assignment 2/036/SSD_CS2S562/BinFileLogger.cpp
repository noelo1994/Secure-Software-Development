#include <iostream>
#include "BinFileLogger.h"
using namespace std;

void BinFileLogger::log(string msg){
	cout << "Writing " << msg << " to a bin file\n";
}