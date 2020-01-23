#include "Authenticator.h"

Authenticator::Authenticator(){};

ProofofID * Authenticator::authenticateUser(Subject &s){
	AuthenticatorInfo ainfo;//create object
	ProofofID *proofofID = nullptr;//null pointer value
	std::string username = s.getUsername();//get inputted username
	std::string pass = s.getPassword();//get inputted password
	std::string token = "";//initialise variable
	//if the credentials match
	if (ainfo.validateUser(username, pass)){
		if (username == "user"){//if user has signed in
			cout << "\nWelcome user..\n";
		}
		else if (username == "admin"){//if admin has signed in
			cout << "\nWelcome admin..\n";
		}
		//encrypt/decrypt username and password
		token = encryptDecrypt(username + pass);
		proofofID = new ProofofID(token);//new proof of id
		s.setproofofID(token);//set proof of id
	}
	else

		cout << "User credentials do not match, please try again. ";
	return proofofID;

};

std::string Authenticator::encryptDecrypt(std::string toEncrypt){
	char key = 'A';
	std::string output = toEncrypt;
	for (size_t i = 0; i < toEncrypt.size(); i++){
		output[i] = toEncrypt[i] ^ key;
	}
	return output;
}