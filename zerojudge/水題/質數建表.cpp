#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main()
{
	/*
	int* it= new int [100000000];
	delete [] it;
	*/
	vector <int> pr;
	int n=100;
	for(int i=3;i<=n;i+=2)
	{
		//cout<<i<<" ";
		pr.push_back(i);
	}
	/*
	for(auto it=pr.begin();it!=pr.end();it++)
	{
		cout<<*it<<" ";
	}*/
	for(auto it=pr.begin();it!=pr.end();it++)
	{
		for(auto jt=it;jt!=pr.end();jt++)
		{
			jt++;
			cout<<*jt<<" % "<<*it<<" ";
			if((*jt)%(*it)==0)
			{
				cout<<"hi";
				pr.erase(jt);
				jt--;
				jt--;
			}
		}
	}
	for(auto it=pr.begin();it!=pr.end();it++)
	{
		cout<<*it<<" ";
	}
}

