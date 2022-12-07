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
		char c;int n;
		cin>>c>>c>>n;
		long long M[n][n];
		bool flag = 1;
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j){
				cin>>M[i][j];
				if(M[i][j]<0)
				{
					flag =0;
				}
			}
		}
        
		if(n&1)
		{
			int cc=n>>1;
			for(int i=0;i<n;++i)
			{
				for(int j=0;j<n;++j){
					if(M[i][j]!=M[i+2*(cc-i)][j+2*(cc-j)])
					{
						flag=0;
						break;
					}
					
				}
				if(!flag)
				{
					break;
				}
			}
			
		}
		else {
			//bool flag = 1;
			float cc=n/2.0-0.5;
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j){
                    int x = i + 2.0* (cc - float(i))+0.5;
                    int y = j + 2.0 * (cc - float(j))+0.5;
                    if(M[i][j]!=M[x][y])
                    {
                        flag=0;
                        break;
                    }
                    
                }
                if(!flag)
                {
                    break;
                }
            }
		}

		
		
		if(flag)
		{
			cout<<"Test #"<<k<<": Symmetric.\n";
		}
		else {
			cout<<"Test #"<<k<<": Non-symmetric.\n";
		}
		
	}
	



}
