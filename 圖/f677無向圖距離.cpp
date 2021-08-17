#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;
class node{
public:
	int data;
	unordered_map<int,node*> in_Map;
};
class infect{
	public:
	node* op=nullptr;
	unordered_map<int,node*> in_List;
	infect()
	{
	}
	~infect()
	{
		for(auto it=in_List.begin();it!=in_List.end();++it)
		{
			delete it->second;	
		}	
	}
	void insert(int a,int b)
	{
		if(op)
		{
			node* l_Node;
			node* r_Node;
			if(in_List.find(a)==in_List.end())
			{
				l_Node=new node;
				l_Node->data=a;
				in_List[a]=l_Node;
			}
			else
			{
				l_Node=in_List[a];
			}
			if(in_List.find(b)==in_List.end())
			{
				r_Node=new node;
				r_Node->data=b;
				in_List[b]=r_Node;
			}
			else
			{
				r_Node=in_List[b];
			}
			l_Node->in_Map[b]=r_Node;
			r_Node->in_Map[a]=l_Node;
			
			
			
		}
		else
		{
			op =new node;
			op->data=a;
			node* tmp=new node;
			tmp->data=b;
			op->in_Map[b]=tmp;
			tmp->in_Map[a]=op;
			in_List[a]=op;
			in_List[b]=tmp;
		}
	}
	
};
int main()
{
	int n,m;
	cin>>n>>m;
	infect patien;
	for(int i=0;i<m;++i)
	{
		int a,b;
		cin>>a>>b;
		patien.insert(a,b);
	}
	set<int> list;
	list.insert(0);
	for(auto it=patien.in_List[0]->in_Map.begin();it!=patien.in_List[0]->in_Map.end();++it)
	{
		for(auto jt=it->second->in_Map.begin();jt!=it->second->in_Map.end();++jt)
		{
			list.insert(jt->first);
		}
		list.insert(it->first);
		
	}
	cout<<list.size()<<"\n";
}

