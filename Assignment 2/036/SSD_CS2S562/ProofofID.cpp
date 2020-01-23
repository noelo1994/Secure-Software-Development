#include "ProofofID.h"

std::string ProofofID::getProofID(){
	return proofID;
};

void ProofofID::setProofID(std::string aproofID){
	proofID = aproofID;
};

ProofofID::ProofofID(std::string aproofID) : proofID(aproofID){};

