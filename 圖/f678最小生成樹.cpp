#include<iostream>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<deque>
#include<set>
using namespace std;
class node{
public:
	int data;
	map<node*,int> ni_Vec;

};
class node_Vec{
public:
	int u;
	int v;
	int w;
	node_Vec()
	{
		
	}
	node_Vec(int t_u,int t_v,int t_w)
	{
		u=t_u;
		v=t_v;
		w=t_w;
	}
	bool operator()(node_Vec val,node_Vec val2)
	{
		if(val.w!=val2.w)
		{
			return val.w<val2.w;
		}
		else
		{
			if(val.u!=val2.u)
			{
				return val.u<val2.u;
			}
			else
			{
				return val.v<val2.v;
			}
		}
	}
};
class min_Tree{
	public:
	node* op=nullptr;
	map<int,node*> in_List;
	map<pair<int,int>,bool> iib_TrNode;
	
	min_Tree()
	{
	}
	~min_Tree()
	{
		for(auto it=in_List.begin();it!=in_List.end();++it)
		{
			delete it->second;	
		}	
	}	
	void insert(int u,int v,int w)
	{
		if(op)
		{
			iib_TrNode.clear();
			
		}
		else
		{
			node* u_Node=new node;
			op=u_Node;
			op->data=u;
			node* v_Node=new node;
			v_Node->data=v; 
			op->ni_Vec[v_Node]=w;
			v_Node->ni_Vec[op]=w;
			
			
						
		}	
	}
	
	bool b_circle(node* op)
	{
		bool tmp=0;
		for(auto it=op->ni_Vec.begin();it!=op->ni_Vec.end();++it)
		{
			if(iib_TrNode.find(pair<int ,int>(op->data,it->first->data))==iib_TrNode.end())
			{
				iib_TrNode[pair<int ,int>(op->data,it->first->data)]=1;
				it->first->ni_Vec.erase(op);
				tmp=max(tmp,b_circle(it->first));
			}
			else
			{
			 return 0;	
			}
			 
		}
		return tmp;
	}
};
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m;
	cin>>n>>m;
	min_Tree tree;
	node_Vec vec[m];
	for(int i=0;i<m;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		vec[i].u=a;
		vec[i].v=b;
		vec[i].w=c;
	}
	sort(vec,vec+m,node_Vec());
	
	
	
	
} 

