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
		int n=5;
		int x[5]={};
		int y[5]={};
        x[2] = 1;
        y[2] = 1;
        int rd=1,ld=1;
		map<int,pair<int,int>> ixy_Map;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
			{
                if(i==j&&i==2)
                {
                    continue;
                }
				int t;
				cin>>t;
				ixy_Map[t]={i,j};
			}
		}
		vector<int> a(75);
		for(auto& it:a)
		{
			cin>>it;
		}
		for(int i=0;i<75;++i)
		{
			int t=a[i];
			if(ixy_Map.find(t)!=ixy_Map.end())
			{
				auto it=ixy_Map[t];
				++x[it.first];
				++y[it.second];
				if(it.first==it.second)
				{
					++rd;
				}
				if(it.first+it.second==4)
				{
					++ld;
				}
				if(*max_element(x,x+5)>=5||*max_element(y,y+5)>=5||rd>=5||ld>=5)
				{
					cout<<"BINGO after "<<i+1<<" numbers announced\n";
					break;
				}
			}
			
		}
		
		

		
		
	}
	



}
