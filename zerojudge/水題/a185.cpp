#include<iostream>
#include<sstream>
using namespace std;
int o_al(int a,int b)
{
	if (b==0)
	return a;
	else
	return o_al(b,a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	cin.clear();
	cin.sync();
	cin.ignore();
	for(int i=0;i<n;i++)
	{
		int int_max=0;
		string s;
		getline(cin,s);
		stringstream ss(s);
		int val[100];
		for(int j=0;ss>>val[j];j++)
		{
			for(int k=0;k<j;k++)
			{
				int num=o_al(val[j],val[k]);
				if (int_max<num)
				{
					int_max=num;
				}
			}
			
		}
		cout<<int_max<<endl;
		
	}
}
