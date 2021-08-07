#include <algorithm>
#include <iostream>
#include <deque>
#include <vector>
#include <map>
using namespace std;
struct node{
public: 
	char c_Name;
	vector<node*> list_Ptr;
};
struct Adj_List{
public:
	vector<node*> node_Ptr;
	map<char,node*> cb_Map;
	map<char,bool> cb_Trlist;
	Adj_List()
	{
		
	}
	void insert(char c_Name,char ct_Name)
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
		it->list_Ptr.push_back(jt);
		jt->list_Ptr.push_back(it);
	}
	int size()
	{
		return cb_Map.size();
	}
	void DFS(char op_Name)
	{
		
		cb_Trlist[op_Name]=1;
		for(auto it=cb_Map[op_Name]->list_Ptr.begin();it!=cb_Map[op_Name]->list_Ptr.end();++it)
		{
			//cout<<"cb_Trlist[(*it)->c_Name]"; 
			if(!cb_Trlist[(*it)->c_Name])
			{
				DFS((*it)->c_Name);
				cb_Trlist[(*it)->c_Name]=1;
			}
		}
		cout<<cb_Map[op_Name]->c_Name<<"\n";
//		if(cb_Trlist.size()+1==cb_Map.size())
//		{
//			cb_Trlist.clear();
//			return ;
//		}
	}
	void BFS(char op_Name)
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
				if(!cb_Trlist[(*it)->c_Name])
				{
					list.push_back(**it);
					cb_Trlist[(*it)->c_Name]=1;
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
	test.insert('A','A');
	test.insert('A','B');
	test.insert('A','C');
	test.insert('A','D');
	test.insert('B','E');
	test.insert('C','E');
	test.insert('B','C');
	test.insert('D','C');
	cout<<test.cb_Map.size()<<endl;
	cout<<"DFS\n";
	test.DFS('A');
	cout<<"BFS\n";
	test.BFS('A');

}

