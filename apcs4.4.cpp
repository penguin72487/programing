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
	//printf("a %d\n",a);
	int m =o(a);
	//printf("k m  %d %d\n",k,m);
	return k<m; 
}

int main()
{

	scanf("%d",&n);
		int loc[n]={0};
			for(i=0;i<2*n;i++)
	{	
		scanf("%d",&a);
			if(i=0)
		loc[0]=a;
		l.push_back(a);
		if(loc[a]) 
		loc[a]=i;
		if(count(l.begin(),l.end(),a)==2)
		{
		//	printf("a %d\n",a);
			o(a);
		h+=count_if(find(l.begin()+loc[a],l.end(),a),l.end(),f );
		//	printf("h loc %d\n",h,loc[a]);
	}
	}
			
	 
	printf("%d\n",h);
}

