#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "Logger.h"

class ConsoleLogger : public Logger {
public:
	void log(string msg);//logs a message
};
#endif