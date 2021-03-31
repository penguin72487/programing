#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
vector<int> a;
a.push_back(1);
int b,i;
for (b=1;b<=1000;b++)
{
	for (i=0;i<a.size();i++)
	{
		a[i]*=b;
	}
	for (i=0;i<a.size();i++)
	{
		if (a[i]>9)
		{
			if (a.size()==i+1)
				a.push_back(a[i]/10);
			else
				a[i+1]+=a[i]/10;
			a[i]=a[i]%10;
		}
	}
}
reverse(a.begin(),a.end());
for (i=0;i<a.size();i++)
{
cout << a[i];
}
return 0;
}
