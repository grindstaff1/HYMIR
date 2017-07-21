#include "reaction.hpp"

reaction::reaction(std:: string e){
 EQFILE=e;
 int N = get_N_reactants(EQFILE);
 reactants.resize(N);
}


int get_N_reactants(std::string &eq){
	int N=0;
	std::ifstream in;
	std::string c;
	in.open(eq.c_str());

	if(in.fail())
	std::cout<< "ERROR!    Could not open file: "<<c<<"\n";
	
	while(getline(in,c))
	{
		if(c[0]!='<'&&c[0]!='-'&&c[0]!='[') N++;
	}

	in.close();

	return N;
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

void react(reaction &rxn, double dN[],double dt){
	
	int N = get_N_reactants(rxn.EQFILE);
	
	for(int i=0;i<N;i++) rxn.reactants[i].n+=dN[i]*dt;

	return;
}


void get_dN(reaction &rxn, double dN[]){
	
	
	double dd;
	int N = get_N_reactants(rxn.EQFILE);

	dd=rxn.k;
	
	for(int i=0;i<N;i++) {
	dd *=pow(rxn.reactants[i].n,max(0,-rxn.nu[i]));
	dN[i]=0;
	}

	for(int i = 0; i < N; i++) dN[i] = dN[i]+rxn.nu[i]*dd;
	
	return;
}
