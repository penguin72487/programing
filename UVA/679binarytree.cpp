#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout.tie()->sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	//int k=0;
	while(t--){
		int d,t;
		cin>>d>>t;
		int n=1<<d;
        int nn = n >> 1;
        vector<int> tree(n,0);
		int now;
		for(int i=0;i<t;++i)
		{
			for(now=1;now<nn;)
			{
				if(tree[now])
				{
					tree[now]^=1;
					now<<=1;
                    now|=1;
				}
				else {
					tree[now]^=1;
					now<<=1;
					
				}
			}
		}
		cout<<now<<"\n";		
		
	}
    cin >> t;
}
