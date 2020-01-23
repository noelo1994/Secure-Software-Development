#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
using namespace std;

enum LoggerType {L_TEXT_FILE = 1, L_BIN_FILE, L_CONSOLE};//declares logger type
enum FormatType {NO_FORMAT = 1, HTML_FORMAT, ENC_FORMAT};//declares format type

class Logger{
	unsigned formatType;//stores format type
public:
	virtual void log(string msg) = 0;//logs a message
};
#endif