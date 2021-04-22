#include<iostream>
#include<algorithm>
using namespace std;

struct fans{
	int n;
	int val=0;
	
bool operator() (fans val,fans val2)
{
	if(val.val>val2.val)
	{
		return 1;
	}
	else if(val.val==val2.val)
	{
		if(val.n<val2.n)
		{
			return 1;
		} 
		else 
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}
};
int main()
{
	//cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>m>>n;
	fans f[m];
	for(int i=0;i<m;i++)
	{
		f[i].n=i;
	}
	int num;
	int x;
	for(int i=0;i<n;i++)
	{
		
		cin>>num>>x;
		f[num].val+=x;
	}
	sort(f,f+m,fans());
	for(int i=0;i<m;i++)
	{
		cout<<f[i].n<<" "<<f[i].val<<"\n";
	}
}
