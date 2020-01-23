#include "Subject.h"
using namespace std;

Subject::Subject(std::string ausername, std::string apass) : username(ausername), password(apass){
	proofID = "";
}

Subject::Subject(){
	cout << "\n username : ";
	//the following 2 lines prevent 'username' from buffer overflow 
	std::cin.width(5);//only store 5 characters
	std::cin >> username;//store username
	cout << " password : ";
	cin >> password;//store password
	proofID = "";//set proofID
}

std::string Subject::getUsername(){
	return username;
};

std::string Subject::getPassword(){
	return password;
};

void Subject::setproofofID(std::string proof){
	proofID = proof;
};

std::string Subject::getproofofID(){
	return proofID;
};