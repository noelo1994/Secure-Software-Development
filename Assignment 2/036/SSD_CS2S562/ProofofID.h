#ifndef PROOFOFID_H
#define PROOFOFID_h

#include <string>
using namespace std;

class ProofofID{//creates and gets proof of id
private:
	std::string proofID;//stores proof of id

public:
	ProofofID(){};//constructor
	ProofofID(std::string);
	std::string getProofID();//gets proof of id
	void setProofID(std::string);//sets proof of id
};
#endif