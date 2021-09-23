#include<iostream>
using namespace std;
int main()
{
	string l;
	int i=1;
	while(cin>>l&&l[0]!='#')
	{
		if(l=="HELLO")
			printf("Case %d: ENGLISH\n",i);
		else if(l=="HOLA")
			printf("Case %d: SPANISH\n",i);
		else if(l=="HALLO")
			printf("Case %d: GERMAN\n",i);
		else if(l=="BONJOUR")
			printf("Case %d: FRENCH\n",i);
		else if(l=="CIAO")
			printf("Case %d: ITALIAN\n",i);
		else if(l=="ZDRAVSTVUJTE")
			printf("Case %d: RUSSIAN\n",i);
		else 
			printf("Case %d: UNKNOWN\n",i);
		
		
		
		i++;
	}
}
