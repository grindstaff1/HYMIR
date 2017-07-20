#ifndef RXN
#define RXN

#include <cmath>
#include <vector>
#include "components.hpp"

class reaction {
	
	public:
	component reactants[];		//List of Reactants
	double k; 					//reaction rate
	int nu[];					//Reaction coefficients
	std::string EQFILE;			//File of reaction
	
	reaction(std:: string);
};


void getcoeff(std:: string, int[]);
int get_N_reactants(std::string);
void get_dN(reaction, double[]);
void react(reaction);

#endif
