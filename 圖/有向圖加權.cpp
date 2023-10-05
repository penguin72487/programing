#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <unordered_map> 
using namespace std;
struct node{
public: 
	char c_Name;
	unordered_map<int,int> list_Ptr;
};
struct Adj_List{
public:
	unordered_map<int,node*> in_Ptr;
	unordered_map<int,bool> cb_Trlist;
	Adj_List()
	{
		
	}
	void insert(int c_Name,int ct_Name,int i_Vector)
	{
		node* it;
		node* jt;
		if(in_Ptr.find(c_Name)==in_Ptr.end())
		{
			it=new node;
			it->c_Name=c_Name;
			in_Ptr[c_Name]=it;
		}
		else
		{
			it=in_Ptr[c_Name];
		}
		if(in_Ptr.find(ct_Name)==in_Ptr.end())
		{
			jt=new node;
			jt->c_Name=ct_Name;
			in_Ptr[ct_Name]=jt;
		}
		else
		{
			jt=in_Ptr[ct_Name];
		}
		it->list_Ptr[c_Name]=i_Vector; 
		jt->list_Ptr[ct_Name]=i_Vector;
	}
	int size()
	{
		return in_Ptr.size();
	}
	int distance(int op,int ed)
	{
		if(op==ed)
		{
			return 0;
		}
		int n=in_Ptr.size()+1;
		int i_estPath[n];
		fill(i_estPath,i_estPath+n,2147483647);
		i_estPath[op]=0;
		for(auto it=in_Ptr[op]->list_Ptr.begin();it!=in_Ptr[op]->list_Ptr.end();++it)
		{
			i_estPath[it->first]=it->second;
		}
//		for(auto it=in_Ptr[op]->list_Ptr.begin();it!=in_Ptr[op]->list_Ptr.end();++it)
//		{
//			i_estPath[ed]=min(i_estPath[ed],i_estPath[it->first]+distance(it->first,ed));
//
//		}
//		return i_estPath[ed];
		 
	}
	~Adj_List()
	{
		for(auto it =in_Ptr.begin();it!=in_Ptr.end();++it)
		{
			delete it->second;
		}
		in_Ptr.clear();
	}
	
};
int main()
{
	Adj_List test;
	test.insert(1,2,2);
	test.insert(1,3,5);
	test.insert(2,4,6);
	test.insert(2,5,10);
	test.insert(3,5,8);
	test.insert(3,4,9);
	test.insert(4,6,4);
	test.insert(5,6,3);
	cout<<test.in_Ptr.size()<<"\n";
	cout<<"³Ìµu¶ZÂ÷\n"<<test.distance(1,6)<<"\n";
	

}

