#include<iostream>
#include<string>
using namespace std;
string round(string a,int p)
{
	int n=a.find('.');
	if(a[n+p+1]>='5')
	{
		a[n+p]++;
		erase(0,1);
		return a;
	 } 
	 else
	 {
	 	erase(a.begin()+n+p,a.end());
		return a;
	 }
	 
}
int main()
{
	string l;
	int p;
	cin>>l>>p;
	cout<<round(l,p)<<endl;
		
}
