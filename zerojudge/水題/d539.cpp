#include<stdio.h>
#include<algorithm>

int main()
{
	int n;
	scanf("%d",&n);
	int l[n];
	int i,j;
	for(i=0;i<n;i++)
	scanf("%d",&l[i]);
	int num;
	scanf("%d",&num);
	int a,b;

	for(i=0;i<num;i++)
	{
			int int_max=0;
		scanf("%d%d",&a,&b);
		if(a==b)
		printf("%d\n",l[a-1]);
		else
		{
		for(j=std::min(a,b)-1;j<std::max(a,b);j++)
		int_max=std::max(int_max,l[j]);
		printf("%d\n",int_max);
	}
	}
	

	
}
