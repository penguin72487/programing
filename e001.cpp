#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
	int n,q;
	int num_so[n];//紀錄士兵的身高 
	map <int,int> w_num;//體重對應編號 
	for(int i=0;i<n;i++)
	{
		cin>>num_so[i];
		w_num[i]=num_so[i];
	}
	sort(num_so,num_so+n);
	
	
} 
