#include "rxn.hpp"

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
for(int uu=0;uu<11;uu++){
std::cout<<nu[j][uu]<<"\t";
}
std::cout<<endl;
}

ofstream out;
out.open ("output.txt");
out <<"t\tA\tB\tAB\tC\n"<<"=================================="<<endl;
for (int i=0;i<10;i++){
	t=dt*i;
	out<<t<<"\t"<<a.n<<"\t"<<b.n<<"\t"<<c.n<<"\t"<<d.n<<endl;
	for(int j=0;j<n_rxn;j++) get_dN(a,b,c,d,e,f,g,h,l,m,o,k2,dt,nu[j],dN);
	react(a,b,c,d,e,f,g,h,l,m,o,dN);
}
out.close();
return 0;
}
