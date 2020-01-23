#ifndef LOGGERFACTORY_H
#define LOGGERFACTORY_H

#include <string>
#include <iostream>
#include "Logger.h"

class LoggerFactoryM{
public:
	Logger *getLogger();//get logger type
};
#endif