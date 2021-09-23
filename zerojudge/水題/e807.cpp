#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n=7,m=4;
	double rain[n][m];
	double week[7]={0},w[7];
	double time[4]={0},t[4];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>rain[i][j];
			week[i]+=rain[i][j];
			w[i]=week[i];
			time[j]+=rain[i][j];
			t[j]=time[j];
		}
	}
	sort(w,w+7);
	sort(t,t+4);
	cout<<find(week,week+7,w[6])-week+1<<endl;
	int a=find(time,time+4,t[3])-time+1;
	switch(a)
	{
		case 1:
		cout<<"morning"<<endl;
		break;
		case 2: 
		cout<<"afternoon"<<endl;
		break;
		case 3: 
		cout<<"night"<<endl;
		break;
		case 4: 
		cout<<"early morning"<<endl;
		break;
		
	}
	
	
}
