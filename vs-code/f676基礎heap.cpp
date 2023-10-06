#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int> list;
	char c_Tmp;
	int i_Tmp;
	while(cin>>c_Tmp&&c_Tmp!=EOF)
	{
		if(c_Tmp=='I')
		{
			cin>>i_Tmp;
			list.push(i_Tmp);
		}
		else
		{
			cout<<list.top()<<"\n";
			list.pop();
		}
	}

}

