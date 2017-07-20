#include "reaction.hpp"
#include "components.hpp"
int main(){


double dt,k1,k2,t;
double dN [11]={0};
component a,b,c,d,e,f,g,h,l,m,o;
std::string s;
std::stringstream ss;
int n_rxn;

s="test.tex";
k1=1;
k2=1e-3;
dt=1e-3;

a.n=50;
b.n=25;
c.n=1;

get_reactions(s,n_rxn);
int nu[n_rxn][11] = {0};

for(int j=0;j<n_rxn;j++){
ss.str("");
ss << "test.tex.eq" << j+1;

getcoeff(ss.str(),nu[j]);

}
reaction rxn1("test.tex.eq1");

ofstream out;
out.open ("output.txt");
out <<"##\tt\tA\tB\tC\tD\n"<<"##=============================================="<<endl;
for (int i=0;i<100;i++){
	t=dt*i;
	out<<"\t"<<t<<"\t"<<a.n<<"\t"<<b.n<<"\t"<<c.n<<"\t"<<d.n<<endl;
	for(int j=0;j<n_rxn;j++) get_dN(rxn1,dN);
	react(rxn1);
}
out.close();
return 0;
}
