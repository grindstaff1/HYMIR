#include "reaction.hpp"
void react(component &a,component &b,component &c,component &d,component &e,component &f,component &g,component &h,component &l,component &m,component &o,double dN[]){
	
	a.n+= dN[0];
	b.n+= dN[1];
	c.n+= dN[2];
	d.n+= dN[3];
	e.n+= dN[4];
	f.n+= dN[5];
	g.n+= dN[6];
	h.n+= dN[7];
	l.n+= dN[8];
	m.n+= dN[9];
	o.n+= dN[10];
	return;
}

void get_dN(component &a,component &b,component &c,component &d,component &e,component &f,component &g,component &h,component &l,component &m,component &o,double k,double dt, int fu[],double dN[]){
	
	double dd;
	
	dd=dt*k*pow(a.n,max(0,-fu[0]))*pow(b.n,max(0,-fu[1]))*pow(c.n,max(0,-fu[2]))*pow(d.n,max(0,-fu[3]))*pow(e.n,max(0,-fu[4]))*pow(f.n,max(0,-fu[5]))*pow(g.n,max(0,-fu[6]))*pow(h.n,max(0,-fu[7]))*pow(l.n,max(0,-fu[8]))*pow(m.n,max(0,-fu[9]))*pow(o.n,max(0,-fu[10]));
	for(int i = 0; i < 10; i++) dN[i] = dN[i]+fu[i]*dd;
	
	return;
}
