#include<iostream>
using namespace std;
int main()
{
int a;
ios::sync_with_stdio(false);
cin>>a;
printf("%d",a%4+4*(a%4==4));
}


