#ifndef BINFILELOGGER_H
#define BINFILELOGGER_H

#include "Logger.h"

class BinFileLogger : public Logger {
public: 
	void log(string msg);//logs a message
};
#endif