#ifndef WATERTYPES_H
#define WATERTYPES_H

#include <iostream>
#include <string>
#include <inttypes.h>

enum WaterType {LAKE = 1, SEA, RIVER};

//Type Class
class Type
{
public:
	virtual void ty(std::string msg) = 0;
};
#endif