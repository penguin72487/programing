#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<functional>
using namespace std;
class heap{
public:
	vector<int> list;
	bool maxheap =1;
	bool cmp(const long& a,const long& b) 
	const{ 
    
		return a>b; 
	} 
	heap(vector<int> tmp)
	{
		list=tmp;
		make_heap(list.begin(),list.end());
	}
	heap(initializer_list<int> tmp)
	{
		list=tmp;
		make_heap(list.begin(),list.end());
	}
	heap(bool tmp)
	{
		maxheap=tmp;
		if(maxheap)
		make_heap(list.begin(),list.end());
		else
		make_heap(list.begin(),list.end());
	}
	void operator=(vector<int> tmp)
	{
		list=tmp;
		make_heap(list.begin(),list.end());
	}
	void operator=(initializer_list<int> tmp)
	{
		list=tmp;
		make_heap(list.begin(),list.end(),cmp);
	}
	void insert(int tmp)
	{
		list.push_back(tmp);
		push_heap(list.begin(),list.end());
	}
	void erase(int index)
	{
		if(index==0)
		{
			pop_heap(list.begin(),list.end());
			list.pop_back();
		}
		else if(index<pow(2,(log10(list.size())/log10(2))+1))
		{
			
		}
		else
		{
			list.erase(list.end()-(1+list.size()-index));
		}
	}
	void maxheapify(int index)
	{
		int i_P = index;
        int i_L = 2*index + 1;
        int i_R = 2*index + 2;

        if (i_L < list.size() && list[i_L] > list[i_P])
            i_P = i_L;

        if (i_R < list.size() && list[i_R] > list[i_P])
            i_P = i_R;

        if (i_P!=index)
		{
            swap(list[index],list[i_P]);
            maxheapify(i_P);
        }
	}
	void minheapify()
	{
		
	}
	int size()
	{
		return list.size();
	}
	vector<int>::iterator begin()
	{
		return list.begin();
	}
	vector<int>::iterator end()
	{
		return list.end();
	}
	
};
int main()
{
	vector<int> tmp={12,11,13,5,6,7};
	heap list={12,11,13,5,6,7};
	for(auto it=list.begin();it!=list.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<"\n";
	

}

