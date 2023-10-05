#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
int C,R,k,m;
cin>>R>>C>>k>>m;
//while(cin>>R>>C>>k>>m){
R+=2;C+=2;
int city[R][C];
for(int i=0;i<R;i++)
{
for(int j=0;j<C;j++)
{
		if (i==0||i==R-1||j==0||j==C-1)
			city[i][j]=-1;
			else
			cin>>city[i][j];

}
}
for(int day = 0;day < m;day++)
{
int city_II[R][C]={0};

for(int i=1;i<R-1;i++){
for(int j=1;j<C-1;j++)
{
if(city[i][j]>=k)
{
if(city[i+1][j]>=0)
{
city_II[i+1][j]+=city[i][j]/k;
city_II[i][j]-=city[i][j]/k;
}
if(city[i-1][j]>=0)
{
city_II[i-1][j]+=city[i][j]/k;
city_II[i][j]-=city[i][j]/k;
}
if(city[i][j+1]>=0)
{
city_II[i][j+1]+=city[i][j]/k;
city_II[i][j]-=city[i][j]/k;
}
if(city[i][j-1]>=0)
{
city_II[i][j-1]+=city[i][j]/k;
city_II[i][j]-=city[i][j]/k;
}
}
}
}
for(int i=1;i<R-1;i++){
for(int j=1;j<C-1;j++)
{
city[i][j]+=city_II[i][j];
}
}
}
int int_max = 0;
int int_min = 2147483647;
for(int i=1;i<R-1;i++)
{
for(int j=1;j<C-1;j++)
{
	if(city[i][j]>=0)
			{
			int_max=max(int_max,city[i][j]);
			int_min=min(int_min,city[i][j]);
			} 
}
}

cout << int_min << endl;
cout << int_max << endl;
}
