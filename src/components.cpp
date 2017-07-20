#include "components.hpp"

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
