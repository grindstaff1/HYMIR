#ifndef COMP
#define COMP

#include <string>
#include <cctype>
#include <algorithm>
#include "parser.hpp"

using namespace std;

class component {
	public:
	std::string name;   //Component identifier
	
	double T;			//Temperature
	double P;			//Pressure
	double rho;			//Density
	double mw;			//Molecular Weight
	std::string phase;	//Phase of Matter
	double V;			//Volume
	double M;			//Mass
	double n;			//Moles
	double cp;			//specific heat per mole
	
	void EOS();
	
	component();
};

class constants {
	public:
	double R  ;//= 1;			//Gas constant
	double k  ;//= 1;			//Boltzmann constant
	double NA ;//= 6.0223e23;	//Avogadro's number

};

void getcoeff(std:: string, int[]);

#endif
