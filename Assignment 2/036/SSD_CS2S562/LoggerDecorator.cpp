#include <iostream>
#include "LoggerDecorator.h"
using namespace std;

LoggerDecorator::LoggerDecorator(Logger * acontents, unsigned aformatType) : contents(acontents), formatType(aformatType){}

void LoggerDecorator::log(string msg){
	msg = formatMessage(msg);
	contents->log(msg);
}

string LoggerDecorator::encryptDecrypt(string toEncrypt){
	char key = 'A';
	string output = toEncrypt;
	for (size_t i = 0; i < toEncrypt.size(); i++){
		output[i] = toEncrypt[i] ^ key;
	}
	return output;
}

string LoggerDecorator::formatMessage(string msg){
	cout << "Formatting : ";
	switch (formatType){//check format type
	case NO_FORMAT://no format type
		cout << "No format" << endl;
		return msg;
		break;
	case HTML_FORMAT:{
		cout << "HTML" << endl;//html format type
		return "<HTML><body><b>" + msg + "<b></body></HTML>";
	}
					 break;
	case ENC_FORMAT:{
		//encrypt format type
		cout << "Encrypt" << endl;
		return encryptDecrypt(msg);
	}
					break;
	default:
		cout << " Unknown Format " << endl;
		return msg;
		break;
	}
}