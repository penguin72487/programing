#include<iostream>
#include<queue>
using namespace std;
int main()
{
	
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		int ans=0;
		int sum=0;
		for(auto it=s.begin();it!=s.end();it++)
		{
			switch(*it)
			{
				case '.':
				break;
				case 'p':
				sum++; 
				break;
				case 'q':
					if(sum)
					{
						sum--;
						ans++;		
					}
				break; 
			}
		}
		cout<<ans<<"\n";
	}
	
}

