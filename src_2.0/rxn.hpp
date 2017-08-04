#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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

class reaction {
	
	public:
	component reactants[];	//List of Reactants
	double k; 				//reaction rate
	int nu[];				//Reaction coefficients
	std::string EQFILE;		//File of reaction
	
	reaction(std::string e);
};

void getcoeff(std:: string, int[]);
int get_N_reactants(std::string&);
void get_dN(reaction&, double[]);
void react(reaction&, double[],double);
void get_reactions(std::string, int& );
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
	std::cout<< "ERROR!    Could not open equation file "<<c<<"\n";
	
	while(getline(in,c))
	{
		if(c!="k"){
		
		
		coeff[g]=std::stoi(c);
		
		
		}
	}
	in.close();
	
return;
}

void react(reaction &rxn, double dt){
	int N = get_N_reactants(rxn.EQFILE);
	double dN[N]={0.0};
	get_dN(rxn,dN);
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

void get_reactions(std::string Input, int &n_rxn){
	std::ifstream in;
	std::ofstream out;
	std::string equation,Output;
	int e=0;
	std::stringstream ss;
	
	in.open(Input.c_str());
	if(in.fail())
	std::cout<< "ERROR!    Could not open file: "<<Input<<"\n";
	
	while(getline(in,equation))
	{
		if(equation.substr(0,3) =="\\ce")
		{
			e++;			
			ss.str("");
			ss << Input<<".eq" << e;
			out.open(ss.str().c_str());
			if(out.fail())
			std::cout<<"Error! Could not create output file.";
			
			for(int i=4;i<equation.length();i++)
			{
				if((equation.at(i)=='['|| equation.at(i)=='<'||equation.at(i)=='+'||(equation.at(i)=='-'&&equation.at(i+1)=='>'))&& (equation.at(i-1)!=']'))
				out<<"\n";
				
				if(equation.at(i)!='+'&&equation.at(i)!=' '&&equation.at(i)!='{'&&equation.at(i)!='}'&&equation.at(i)!='&'&&equation.at(i)!='\\')
				out <<equation.at(i);
			
				if(equation.at(i)==']')
				out<<"\n";
			}
		out.close();
		}
	}
	n_rxn=e;
	in.close();
	out.close();
	return;
}
