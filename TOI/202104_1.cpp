#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long spend(long long op,long long ed,int* so);
long long  cost(int* so,long long lv);
long long c;
long long m=100000000;
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

	cout<<"\n";
	sort(so,so+n);

	if(n==1)
	{
		cout<< (so[0])+ int (sqrt(c))<<"\n";
	}
	else
	{
		cout<<spend(so[0],m,so)<<"\n";
	}
	
	
	
}
long long  spend(long long op,long long ed,int* so)
{
    //int low = op, high = ed - 1;
    long long lv;

<<<<<<< .mine
    while (op<ed-1)
=======
    while (op <ed)
>>>>>>> .theirs
    {
       	lv = (op + ed) / 2;
		//cout<<op<<" "<<ed<<endl;
		//cout<<"lv="<<lv<<endl;
        long long totle=cost(so,lv);
        //cout<<"ªá¶O¬O"<<totle<<endl; 
        if(totle==c)
        {
        	return lv;
		}
		else if(cost(so,lv+1)>c&&totle<c)
		{
			return lv;
		}
        else if ( totle > c)
        {
<<<<<<< .mine
            ed = lv;

=======
        //	cout<<"1"<<endl;
            ed = lv-1;
>>>>>>> .theirs
        }
        else if (totle < c)
        {
<<<<<<< .mine
            op = lv ;

=======
        //	cout<<"2"<<endl; 
            op = lv +1;
>>>>>>> .theirs
        }
    }

    return (op + ed) / 2;;
}
long long cost(int* so,long long lv)
{
	long long totle=0;
	for(int* it=so;it!=so+n&&*it<lv&&totle<c;it++)
	{
		totle+=(lv-*it)*(lv-*it);
	}
	return totle;
}
