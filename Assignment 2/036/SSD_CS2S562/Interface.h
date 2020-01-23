#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>

class Interface{//prints the interface after login
private:
	char option;//stores user option

public:
	Interface();//constructor - initialises variables
	void print();//prints interface to screen
	char getOption();//gets user option
	void optionSelect(char a);//processes option selected
};
#endif