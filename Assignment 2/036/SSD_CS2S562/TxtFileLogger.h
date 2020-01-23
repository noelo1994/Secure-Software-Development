#ifndef TXTFILELOGGER_H
#define TXTFILELOGGER_H
	
#include "Logger.h"

class TxtFileLogger : public Logger {
public:
	void log(string msg);//log a message
};
#endif