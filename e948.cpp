#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n;
	for(cin>>n;n>0;n--)
	{
		int g,a,h,w;
	cin>>g>>a>>h>>w;
	float BMI=(g==1)*(13.7*w+5*h-6.8*a+66)+(g==0)*(9.6*w+1.8*h-4.7*a+665);
	cout<<fixed;
	cout<<setprecision(2)<<BMI<<endl;
}
}
