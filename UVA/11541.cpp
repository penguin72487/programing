#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout.tie()->sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	int k=0;
	while(t--){
		++k;
		char c;
		int n=0;
		string s,ans;
		cin>>s;
        int num = 0;
        for(auto& it:s){
            if(it>='A')
            {
                ++num;
            }
        }
        stringstream ss(s);
		for(int i=0;i<num;++i)
		{
            //cout<<ss.str()<<"\n";
			ss>>c;
			ss>>n;
			for(int i=0;i<n;++i)
			{
				ans.push_back(c);
			}	
		}
		cout<<"Case "<<k<<": "<<ans<<"\n";

		
		
	}
	



}
