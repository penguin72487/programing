#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	 
	  long double  i,t,t2;
	 for(i=0.1;i<=10;i+=0.1)
	 {
	 	t=log10(2);
		t2 =log10(1+0.01*i);
	 	 long double r=72/i;
	 	cout<<fixed<<setprecision(10)<<i<<"% "<<t/t2<<" "<<r<<" "<<abs(r-t/t2)<<endl;
	 }
}
