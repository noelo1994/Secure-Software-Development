#pragma once
#include<string>
#include <iostream>

using namespace std;




enum LoggerType { L_TEXT_FILE = 1, L_CONSOLE, L_BINARY_FILE };
enum Formate { NO_FORMAT = 1, HTML_FORMAT, ENC_FORMAT };

//Logger class 
class Logger
{
public:

	virtual void log(string msg);

private:

};
class ConsoleLogger : public Logger
{
public:
	void log(std::string msg);
};
class TxtFileLogger : public Logger
{
public:
	void log(std::string msg);
};
class BinFileLogger : public Logger
{
public:
	void log(std::string msg);
};
class LoggerDecorator : public Logger
{
private:
	//unsigned formatType;
	Logger* contents;

public:
	LoggerDecorator(Logger * alogger);
	void log(string msg);
	//virtual string formatMessage(string msg);
};
class LoggerFactory
{
public:
	Logger *getLogger();
};
Logger * LoggerFactory::getLogger()
{
	unsigned loggerType;
	cout << "\n SELECT LOGGER TYPE [1:TXT FILE, 2:BIN FILE, 3:CONSOLE] :";
	cin >> loggerType;
	switch (loggerType)
	{
	case L_TEXT_FILE:
		return new TxtFileLogger();
		break;
	case L_BINARY_FILE:
		return new BinFileLogger();
		break;
	case L_CONSOLE:
		return new ConsoleLogger();
		break;
	default:
		cout << "NO LOGGER";
		return NULL;
		break;
	}
}
class HTMLLogger : public LoggerDecorator
{
public:
	HTMLLogger(Logger * logger);
	void log(string msg);
	string makeHTML(string msg);
};
class EncryptLogger : public LoggerDecorator
{
public:
	void log(string msg);
	EncryptLogger(Logger * logger);
private:
	string encryptDecrypt(string toEncrypt);
};
