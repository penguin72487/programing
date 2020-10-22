#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
bool f(int k)
{
	int j;
	printf("fountion %d",k);
	 return j<k; 
}

int main()
{
	int n;
	int a ;
	vector<int> l;
	scanf("%d",&n);
	int i,h=0;
	for(i=0;i<2*n;i++)
	{
		scanf("%d",&a);
		l.push_back(a);
		if(count(l.begin(),l.end(),a)==2)
		{
			printf("yes %d",a);
		h+=count_if(l.begin(),l.end(),f(a))  ;
	}
			
	} 
	printf("%d\n",h);
}

