#include<iostream>
using namespace std;
int fn_GetHCF(int val,int val2);
int main ()
{
	int val,val2;
	cin>>val>>val2;
	if(val<val2)
	val^=val2^=val^=val2;
	cout<<fn_GetHCF(val,val2)<<endl;
	return 0;
}
int fn_GetHCF(int val,int val2)
{
	if(val%val2==0)
		return val2;
	else
	{
		int temp;
		temp=val2;
		val2=val-(val/val2)*val2;
		val=temp;
	}
	return fn_GetHCF(val,val2);
}

