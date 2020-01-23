#ifndef LOGGERDECORATOR_H
#define LOGGERDECORATOR_H

#include "Logger.h"

class LoggerDecorator : public Logger {
	unsigned formatType;//stores format type
	Logger * contents;//stores contents
	void log(string msg);//logs a message
	string encryptDecrypt(string toEncrypt);//encrypts/decrypts string

public:
	LoggerDecorator(Logger * contents, unsigned formatType);//constructor
	virtual string formatMessage(string msg);//processes format message
};
#endif