#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
	int n;
	int a;
	vector<int> l;
	int i,h=0;
	int m;
	int o(int m)
	{
		
	}

bool f(int k)
{
	int m =o(a);
	//printf("k m  %d %d\n",k,m);
	return (k<m); 
}

int main()
{
	scanf("%d",&n);
			for(i=0;i<2*n;i++)
	{
		scanf("%d",&a);
		l.push_back(a);
		if(count(l.begin(),l.end(),a)==2)
		{
			//printf("%d\n",a);
			o(a);
		h+=count_if(find(l.begin(),l.end(),a),l.end(),f );
	}
	}
			
	 
	printf("%d\n",h);
}

