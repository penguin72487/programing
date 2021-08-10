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
	unordered_map<char,int> list_Ptr;
};
struct Adj_List{
public:
	vector<node*> node_Ptr;
	unordered_map<char,node*> cb_Map;
	unordered_map<char,bool> cb_Trlist;
	Adj_List()
	{
		
	}
	void insert(char c_Name,int i_weight,char ct_Name)
	{
		node* it;
		node* jt;
		if(!cb_Map[c_Name])
		{
			it=new node;
			it->c_Name=c_Name;
			cb_Map[c_Name]=it;
		}
		else
		{
			it=cb_Map[c_Name];
		}
		if(!cb_Map[ct_Name])
		{
			jt=new node;
			jt->c_Name=ct_Name;
			cb_Map[ct_Name]=jt;
		}
		else
		{
			jt=cb_Map[ct_Name];
		}
		it->list_Ptr[c_Name]=i_weight; 
		jt->list_Ptr[ct_Name]=i_weight;
	}
	int size()
	{
		return cb_Map.size();
	}
	void DFS(char op_Name='A')
	{
		
		cb_Trlist[op_Name]=1;
		for(auto it=cb_Map[op_Name]->list_Ptr.begin();it!=cb_Map[op_Name]->list_Ptr.end();++it)
		{
			cout<<"cb_Trlist[(*it)->c_Name]"; 
			if(cb_Trlist.find(it->first)!=cb_Trlist.end())
			{
				cb_Trlist[it->first]=1;
				DFS(it->first);
				
			}
		}
		cout<<cb_Map[op_Name]->c_Name<<"\n";
		cb_Trlist.clear();
//		if(cb_Trlist.size()+1==cb_Map.size())
//		{
//			cb_Trlist.clear();
//			return ;
//		}
	}
	void BFS(char op_Name='A')
	{
		cb_Trlist.clear();
		deque<node> list;
		list.push_back(*cb_Map[op_Name]);
		while(!list.empty())
		{
			cb_Trlist[list.front().c_Name]=1;
			cout<<list.front().c_Name<<"\n";
			for(auto it=list.front().list_Ptr.begin();it!=list.front().list_Ptr.end();++it)
			{
				if(!cb_Trlist[it->first])
				{
					list.push_back(*cb_Map[it->first]);
					cb_Trlist[it->first]=1;
				}
			}
			list.pop_front();
		}
		cb_Trlist.clear();
	}
	~Adj_List()
	{
		for(auto it =cb_Map.begin();it!=cb_Map.end();++it)
		{
			delete it->second;
		}
		cb_Map.clear();
	}
	
};
int main()
{
	Adj_List test;
	test.insert('A',2,'A');
	test.insert('A',3,'B');
	test.insert('A',7,'C');
	test.insert('A',3,'D');
	test.insert('B',8,'E');
	test.insert('C',6,'E');
	test.insert('B',11,'C');
	test.insert('D',8,'C');
	cout<<test.cb_Map.size()<<"\n";
	cout<<"DFS\n";
	test.DFS();
	cout<<"BFS\n";
	test.BFS('E');

}

