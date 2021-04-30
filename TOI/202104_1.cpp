#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long spend(long long op,long long ed,int* so);
long long  cost(int* so,int lv);
long long c;
int n;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin>>n>>c;
	int so[n];
	for(int i=0;i<n;i++)
	{
		cin>>so[i];
	}
	sort(so,so+n);
	if(n==1)
	{
		cout<< (so[0])+ int (sqrt(c))<<endl;
	}
	else
	{
		cout<<spend(so[0],so[n-1],so)<<endl;
	}
	
	
	
}
long long  spend(long long op,long long ed,int* so)
{
    //int low = op, high = ed - 1;
    long long lv;

    while (op <ed-1)
    {
       	lv = (op + ed) / 2;
		//cout<<op<<" "<<ed<<endl;
        long long totle=cost(so,lv);
        if(totle==c)
        {
        	return lv;
		}
        else if ( totle > c)
        {
            ed = lv-1;
        }
        else if (totle < c)
        {
            op = lv +1;
        }
    }

    return op;
}
long long cost(int* so,int lv)
{
	long long totle=0;
	for(int* it=so;it!=so+n&&*it<lv;it++)
	{
		totle+=(lv-*it)*(lv-*it);
	}
	return totle;
}


