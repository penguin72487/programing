#include<iostream>
#include<algorithm>
#include  <iterator> 
#include <cstdio>
#include<map>
#include<set>
using namespace std;
int main()
{
	int n,q;
	cin>>n>>q; 
	int i_h[n];//紀錄士兵的身高
	map <int,int> h_i;//身高對應編號 
	set <int> sort_h;
	for(int i=0;i<n;i++)
	{
		cin>>i_h[n];
		sort_h.insert(i_h[i]);
		h_i[i_h[i]]=i;
	}
	sort_h.insert(i_h,i_h+n);
	for( set<int>::iterator iter = sort_h.begin() ; iter != sort_h.end() ; ++iter)
    {
		cout<<*iter<<" ";
    }
	cout<<endl;
	for(int i=0;i<q;i++)
	{
		int temp;
		cin>>temp;
		
		auto it=sort_h.find(i_h[temp]);
		cout<<(*next(it))<<" "<< (*prev(it))<<endl;
		sort_h.erase(i_h[temp]);
	
		
			
	} 
} 
	

