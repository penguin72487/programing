#include<iostream>
using namespace std;
void insertion_sort(int list[],int n);
int main()
{
	int n;
	cin>>n;
	int list[n];
	for(int i=0;i<n;i++)
	{
		cin>>list[i];
	} 
	insertion_sort(list,n);
	for(int i=0;i<n;i++)
	{
		cout<<list[i]<<" "; 
	}
	cout<<endl;
}
void insertion_sort(int list[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(list[i]>list[j])
			{
				list[i]^=list[j]^=list[i]^=list[j];
			}
		}
	}
	
}
