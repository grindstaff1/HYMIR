#include "rxn.hpp"

int main(){

double dt,k1,t;
dt=1e-3;

reaction rxn1("test.eq1");
rxn1.reactants[0].n=50;
rxn1.reactants[1].n=25;
rxn1.reactants[2].n=0;

return 0;
}
