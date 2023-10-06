#include <iostream>
//#include<algorithm>
using namespace std;
int ft[]={0,2,5,9,10,15,16,19,26};
int f[100]={0,2,5};
int trans(int a);
int main()
{
    int a;
    cin>>a;
    trans(a);
    cout<<f[a]<<endl;

    return 0;
}
int trans(int a)
{

    for(int i=1;i<=a/2;i++)
    {
       f[a]=max(trans(a-i)+trans(i),f[a]);
    }



}

