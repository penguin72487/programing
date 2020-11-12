#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int i;
	string l;
	int k=0,d=0,a=0;
	int std_k=0;
	for(i<0;i<n;i++)
	{
		cin>>l;
		if(l=="Get_Kill")
		{
			k++;
			if(k-std_k<3)
			printf("You have slain an enemie.\n");
			else if(k-std_k==3)
			printf("KILLING SPREE!\n");
			else if(k-std_k==4)
			printf("RAMPAGE~\n");
			else if(k-std_k==5)
			printf("UNSTOPPABLE!\n");
			else if(k-std_k==6)
			printf("DOMINATING!\n");
			else if(k-std_k==7)
			printf("GUALIKE!\n");
			else 
			printf("LEGENDARY!\n");
		}
		
		else if(l=="Get_Assist")
		{
			a++;
		}
		
		else
		{
			if(k-std_k<3)
			printf("You have been slained.\n");
			else 
			printf("SHUTDOWN.\n");
			std_k=k;
			d++;
			
		}
		
	}
	printf("%d/%d/%d",k,d,a);
}
