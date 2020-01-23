#include "Auth.h"
using namespace std;

Auth::Auth(){ };

ProofofID * Auth::authUser(User &u)
{
	AuthInfo info;
	ProofofID *proofofID = nullptr;
	string ID = u.getId();
	string password = u.getPassword();
	string token = "";

	if (info.validation(ID, password))
	{
		cout << "\nWelcome " << ID <<"!";
		cout << "\nAuthenticated!\n";
		token = encryptDecrypt(ID + password);
		proofofID = new ProofofID(token);
		u.setproofofID(token);
	}
	else
	{
		cout << "Invalid!!!";

	}
	return proofofID;
}

string Auth::encryptDecrypt(string toEncrypt)
{
	char key = 'A';
	string output = toEncrypt;
	for (int i = 0; i < toEncrypt.size(); i++)
	{
		output[i] = toEncrypt[i] ^ key;
	}
	return output;
}