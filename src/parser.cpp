#include "parser.hpp"


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
