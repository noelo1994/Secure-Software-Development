#include "AuthInfo.h"
#include "User.h"
#include "ProofofID.h"

//Auth Class

class Auth
{
public:
	Auth(); //constructor
	ProofofID * authUser(User &u); //attempts
private:
	string encryptDecrypt(string toEncrypt);
};
