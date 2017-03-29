#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <math.h>
#include "elo.h"
using namespace std;

EloRating er;

int main()
{

	double s[6],Ea[7],Eb[7];
	int K,RA[7],RB[7];
	
	ofstream outfile("file.out",ios::out);
	ifstream infile("file.in",ios::in);
	if(!infile){
		cerr<<"Failed opening"<<endl;
		exit(1);
	}
	infile>>K>>RA[0]>>RB[0]>>s[0]>>s[1]>>s[2]>>s[3]>>s[4]>>s[5];
			
	for(int i=0;i<7;++i){
	
	Ea[i] = er.getE(RA[i],RB[i]);	
	Eb[i] = er.getE(RB[i],RA[i]);
	cout<<Ea[i]<<' '<<Eb[i]<<endl;
	RA[i+1] = er.getRank(RA[i],K,s[i],Ea[i]);
	RB[i+1] = er.getRank(RB[i],K,1-s[i],Eb[i]);
	
	cout<<RA[i]<<' '<<RB[i]<<endl;
	outfile<<RA[i]<<' '<<RB[i]<<endl;
	}
	
		
	return 0;
}
