#include<iostream>
#include<queue> 
#include<vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
//	cout.tie(0);
	int n=0;
	int tmp;
	priority_queue<int> max_Heap;
	priority_queue<int,vector<int>,greater<int>> min_Heap;
	while(cin>>tmp&&tmp!=-1)
	{
			++n;
		if(max_Heap.empty())
		{
			max_Heap.push(tmp);
		}
		else if(min_Heap.empty())
		{
			min_Heap.push(tmp);
		}
		else if(tmp<=max_Heap.top())
		{
			max_Heap.push(tmp);	
		}
		else
		{
			min_Heap.push(tmp);
		}
		
		if(max_Heap.size()>min_Heap.size()+1)
		{
			min_Heap.push(max_Heap.top());
			max_Heap.pop();
		}
		else if(max_Heap.size()<min_Heap.size())
		{
			max_Heap.push(min_Heap.top());
			min_Heap.pop();
		}
		if(n&1)
		{
			cout<<max_Heap.top()<<"\n";
		}
		else
		{
			cout<<(max_Heap.top()+min_Heap.top())/2<<"\n";
		}
	}

}
