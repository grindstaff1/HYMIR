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

component::component(){
	name = "";   
	T = 298;			
	P = 101.325;			
	rho = 1;			
	mw  = 100;			
	phase = "";				
	M = 10;			
	n = M/mw;
	V = M/rho; 			
	cp = 1;			
}
void getcoeff(std:: string, int[]);


void getcoeff(std:: string eq, int coeff[]){
	std::ifstream in;
	std::string c;
	in.open(eq.c_str());
	int g=0;
	int sgn=-1;
	if(in.fail())
	std::cout<< "ERROR!    Could not open file: "<<c<<"\n";
	
	while(getline(in,c))
	{
		std::size_t found = c.find('>');
		if (found!=std::string::npos){
		sgn=1;
		}
		if(c[0]!='<'&&c[0]!='-'&&c[0]!='['){
			if(isdigit(c[0])){
				coeff[g]=std::stoi(c);
				coeff[g]*=sgn;
				g++;
			}else{
				coeff[g]=sgn;
				g++;
			}
		}
	}
	in.close();
	
return;
}
#endif
