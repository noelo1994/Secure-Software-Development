#include "Clock.h"
#include<iostream>
#include <ctime>
using namespace std;
void Clock::getTime()
{
	time_t now;//new object for time

	struct tm nowLocal;
	now = time(NULL);
	nowLocal = *localtime(&now);
	cout << "Today is: " << nowLocal.tm_mday/*displays day*/ << "/" << nowLocal.tm_mon/*displays month*/ << "/" << nowLocal.tm_year + 1900 /*displays year*/ << endl;
	cout << "Time is: " << nowLocal.tm_hour/*displays current hour*/ << ":" << nowLocal.tm_min /*displays current minute*/ << ":" << nowLocal.tm_sec /*displays current second*/ << endl;

}