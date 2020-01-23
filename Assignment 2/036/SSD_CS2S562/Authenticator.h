#ifndef AUTHENTICATOR_H
#define AUTHENTICAOTR_H

#include "AuthenticatorInfo.h"
#include "Subject.h"
#include "ProofofID.h"
using namespace std;

class Authenticator{//authenticates user
private:
	std::string encryptDecrypt(std::string toEncrypt);//encrypts/decrypts proof of id

public: 
	Authenticator();//constructor initialises data members
	ProofofID * authenticateUser(Subject &s);//attempts to authorise user
};
#endif