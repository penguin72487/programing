#include<stdio.h>
#include<algorithm>
#include<vector>
int main()
{
	int a;
	std::vector <int> l;
	while(scanf("%d",&a)!=EOF)
	{
		l.push_back(a);
		std::sort(l.begin(),l.end());
		int n=l.size()/2;
		if(l.size()%2==1)
		printf("%d\n",l[n]);
		else
		printf("%d\n",(l[n-1]+l[n])/2);
	}
}
