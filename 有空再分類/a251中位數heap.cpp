#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		vector<int> max_Heap;
		vector<int> min_Heap;
		for(int j=0;j<5;++j)
		{
			int tmp;
			cin>>tmp;
			if(max_Heap.empty())
			{
				max_Heap.push_back(tmp);
			}
			else if(max_Heap.empty())
			{
				min_Heap.push_back(tmp);
			}
			else if(tmp<=max_Heap[0])
			{
				max_Heap.push_back(tmp);
				push_heap(max_Heap.begin(),max_Heap.end());
			}
			else
			{
				min_Heap.push_back(tmp);
				push_heap(min_Heap.begin(),min_Heap.end(),greater<int>());
			}
			if(max_Heap.size()>min_Heap.size()+1)
			{
				pop_heap(max_Heap.begin(),max_Heap.end());
				min_Heap.push_back(*(--max_Heap.end()));
				push_heap(min_Heap.begin(),min_Heap.end(),greater<int>());
				max_Heap.pop_back();
			}
			else if(max_Heap.size()<min_Heap.size())
			{
				pop_heap(min_Heap.begin(),min_Heap.end(),greater<int>());
				max_Heap.push_back(*(--min_Heap.end()));
				push_heap(max_Heap.begin(),max_Heap.end());
				min_Heap.pop_back();
			}
		}
		cout<<max_Heap[0]<<"\n";
	}
		
}

