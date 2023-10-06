#include<iostream>
using namespace std;
int int_Stacktop, int_Stack[105];
int main()
{
	string str_Cmd;
	int i=0;
	int_Stacktop=0; 
	while (cin>>str_Cmd)
	{
	
		if(str_Cmd=="push")
		{
			cin>>i/
			int_Stack[int_Stacktop]=i;
			int_Stacktop++;
		}
		if(str_Cmd=="pop")
		{
			if(int_Stack==0)
			printf(" pop: nothing in stack\n");
			else
			printf("pop: %d\n",int_Stack[int_Stacktop-1]);
			int_Stacktop--;
		}
	}
	
	
	
 } 
