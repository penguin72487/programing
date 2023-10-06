#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> max_Heap;
	vector<int> min_Heap;
	for(int i=0;i<n;++i)
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
	if(n&1)
	{
		cout<<max_Heap[0]<<"\n";
	}
	else
	{
		cout<<(max_Heap[0]+min_Heap[0])/2.0<<"\n";
	}
//	make_heap(list.begin(),list.end(),greater<int>());
//	for(auto it=list.begin();it!=list.end();it++)
//	{
//		cout<<*it<<" ";
//	}
//	cout<<"\n";
	
}

