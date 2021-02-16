#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
vector<vector<int> > val(10000, vector<int> (1,0));

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
	cin.tie(0);
	ios_base::sync_with_stdio(1);
	val[0][0]=1;
	int n;
	while(cin>>n&&n!=0)
	{
		for(int i=1;i<=n;i++)
		{
			//cout<<"yes"<<endl;
			if(val[i][0]!=0)
			continue;
			val[i].clear();
			val[i].assign(val[i-1].rbegin(),val[i-1].rend());
			for(auto it=val[i].begin();it!=val[i].end();it++)
			{
				(*it) *= 2;
			}
			for(int j=0;j<val[i].size();j++) 	//統一進位 
			{
				
				if(val[i][j]>9)
				{
				 	if(val[i].size()==j+1)
				 		val[i].push_back(val[i][j]/10);
		 			else
    					val[i][j+1]+=val[i][j]/10;
    			val[i][j]=val[i][j]%10;
   				}
			}
			reverse(val[i].begin(),val[i].end());
		}
			for(auto it=val[n].begin();it!=val[n].end();it++)
			{
				cout<<*it;
			}
			cout<<"\n";
		
	}
	
} 
