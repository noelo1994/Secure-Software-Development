#include "ProofofID.h"

using namespace std;



string ProofofID::getproofID()
{
	return proofID;
};
void ProofofID::setproofID(string aproofID)
{
	proofID = aproofID;
};

ProofofID::ProofofID(string aproofID)
:proofID(aproofID){};