#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>
using namespace std;
class EloRating{
	public:
		double getE(int A, int B){
		return 1/(1+pow(10,(((double)B-(double)A)/400)));
				}
				
		int getRank(int a,int k,double s,double E){
		return a+k*(s-E)+0.5;
		}
			
	

	private:
		int RA;
		int RB;
		int K ;
};
	

