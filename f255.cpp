#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<vector<int> > val(10000, vector<int>(1,0));
vector<int> f(vector<int> val,int n)
{
	if(val[n]!=0)
	{
		return val[n];
	}
	else
	{
		return f(val,n-1);
	}
}
void out(vector<int> val)
{
	int i=0;
	while(val[i]==0)  //去數字頭的0 
	i++;
			
	for(;i<val.size();i++)
	printf("%d",val[i]);
	printf("\n");
	val.clear();
}
int main ()
{
	
	val[0].push_back(1);
	int n;
	while(cin>>n&&n!=0)
	{
		
		f(val[n],n);
		out(val[n]);
	}
	
} 
