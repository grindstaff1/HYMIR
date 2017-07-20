#ifndef RXN
#define RXN

#include <cmath>
#include <vector>
#include "components.hpp"

class reaction {
	
	public:
	component reactants[];		//List of Reactants
	component products[];		//List of Products
	double k; 					//reaction rate
	int nu[];					//Reaction coefficients
	std::string EQFILE;			//File of reaction
	
	
};



void get_dN(component&,component&,component&,component&,component&,component&,component&,component&,component&,component&,component&,double,double, int[],double[]);
void react(component&,component&,component&,component&,component&,component&,component&,component&,component&,component&,component&,double[]);

#endif
