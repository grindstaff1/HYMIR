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

