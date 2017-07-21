#include "reaction.hpp"
#include "components.hpp"
int main(){


double dt,k1,k2,t;


std::string s;
std::stringstream ss;
int n_rxn;

s="test.tex";
k1=1;
k2=1e-3;
dt=1e-3;

get_reactions(s,n_rxn);
double dN [3]={0};
reaction rxn1("test.tex.eq1");
rxn1.reactants[0].n=50;
rxn1.reactants[1].n=25;
rxn1.reactants[2].n=0;

for(int j=0;j<n_rxn;j++){
ss.str("");
ss << "test.tex.eq" << j+1;

getcoeff(ss.str(),rxn1.nu);

}

ofstream out;
out.open ("output.txt");
out <<"##\tt\tA\tB\tC\tD\n"<<"##=============================================="<<endl;
for (int i=0;i<100;i++){
	t=dt*i;
	out<<"\t"<<t<<"\t"<<rxn1.reactants[0].n<<"\t"<<rxn1.reactants[1].n<<"\t"<<rxn1.reactants[2].n<<endl;
	for(int j=0;j<n_rxn;j++) get_dN(rxn1,dN);
	react(rxn1,dN,dt);
}
out.close();
return 0;
}
