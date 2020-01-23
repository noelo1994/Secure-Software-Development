#include "Logger.h"
#include <string>
#include <iostream>

using namespace std;



void ConsoleLogger::log(string msg)
{
	cout << "writing " << msg << " to console\n";
}


void TxtFileLogger::log(string msg)
{
	cout << "writing " << msg << " to a text file\n";
}


void BinFileLogger::log(string msg)
{
	cout << " writing " << msg << " to a bin file\n";
}


LoggerDecorator::LoggerDecorator(Logger * alogger)
{
}
void LoggerDecorator::log(string msg)
{
	cout << "Adding " << msg << " to log.";
	//msg = formatMessage(msg);
	//contents->log(msg);
}




HTMLLogger::HTMLLogger(Logger * alogger) : LoggerDecorator(alogger)
{
}
void HTMLLogger::log(string msg)
{
	msg = makeHTML(msg);
	LoggerDecorator::log(msg);
}
string HTMLLogger::makeHTML(string msg)
{
	//make into html doc
	//cout << "Adding " << "<HTML><BODY><b>" + msg + "</b></BODY></HTML> to log." << endl;
	return "<HTML><BODY><b>" + msg + "</b></BODY></HTML>";

}


EncryptLogger::EncryptLogger(Logger * alogger) : LoggerDecorator(alogger)
{
}
void EncryptLogger::log(string msg)
{
	msg = encryptDecrypt(msg);
	LoggerDecorator::log(msg);
}
string EncryptLogger::encryptDecrypt(string toEncrypt)
{
	char key = 'F';
	string output = toEncrypt;
	for (int i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key;

	}
	cout << "Adding " << output << " to log.";
	return output;
}
