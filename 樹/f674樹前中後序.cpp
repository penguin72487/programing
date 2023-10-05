#include<iostream>
#include<deque>
using namespace std;
class node{
public :
	int data;
	node* l_Node=nullptr;
	node* r_Node=nullptr;
};
class tree{
public :
	node* op=nullptr;
	int size=0; 
	tree()
	{
		
	
	}
	~tree()
	{
		//dfs_disNode(op);
	
	}
	void insert(int i_Pa,int i_L,int i_R)
	{
		if(size==0)
		{
			op=new node;
			op->data=i_Pa;
			node* lt_Node;
			if(i_L!=-1)
			{
				lt_Node=new node;
				lt_Node->data=i_L;
				++size;
			}
			else
			{
				lt_Node=nullptr;
			} 
			node* rt_Node;
			if(i_R!=-1)
			{
				rt_Node=new node;
				rt_Node->data=i_R;
				++size;

			}
			else
			{
				rt_Node=nullptr;
			}
			op->l_Node=lt_Node;
			op->r_Node=rt_Node;

		}
		else
		{
			node* n_Pa=bfs_NodePtr(i_Pa);
			node* lt_Node;
			if(i_L!=-1)
			{
				lt_Node=new node;
				lt_Node->data=i_L;
				++size;

			}
			else
			{
				lt_Node=nullptr;
			} 
			node* rt_Node;
			if(i_R!=-1)
			{
				rt_Node=new node;
				rt_Node->data=i_R;
				++size;

			}
			else
			{
				rt_Node=nullptr;
			}
			n_Pa->l_Node=lt_Node;
			n_Pa->r_Node=rt_Node;			
		}
	}

	node* bfs_NodePtr(int goal)
	{
		deque<node*> list;
		list.push_back(op);
		while(!list.empty())
		{
			
			node* now=list.front();
			//cout<<now->data<<"\n";
			list.pop_front();
			if(now->data==goal)
			{
				return now;
			}
			if(now->l_Node)
			list.push_back(now->l_Node);
			if(now->r_Node)
			list.push_back(now->r_Node);
			
		}
		return nullptr;
		
	}
	void dfs_Trfrom(node* now)
	{
		if(!now)
		return ;
		cout<<now->data<<" ";
		dfs_Trfrom(now->l_Node);
		dfs_Trfrom(now->r_Node);
		
	}
	void dfs_Trmid(node* now)
	{
		if(!now)
		return ;
		dfs_Trmid(now->l_Node);
		cout<<now->data<<" ";
		dfs_Trmid(now->r_Node);
		
	}
	void dfs_Trend(node* now)
	{
		if(!now)
		return ;
		dfs_Trend(now->l_Node);
		dfs_Trend(now->r_Node);
		cout<<now->data<<" ";
		

	}
	void dfs_disNode(node* now)
	{
		if(!now) 
		return
		
		dfs_disNode(now->l_Node);
		dfs_disNode(now->r_Node);
		delete now;

	}
		
};
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	tree tr_Tmp;
	for(int i=0;i<n;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		tr_Tmp.insert(a,b,c);
	}
	//cout<<tr_Tmp.tree_High()<<"\n";
	tr_Tmp.dfs_Trfrom(tr_Tmp.op);
	cout<<"\n";
	tr_Tmp.dfs_Trmid(tr_Tmp.op);
	cout<<"\n";
	tr_Tmp.dfs_Trend(tr_Tmp.op);
	cout<<"\n";
	
	return 0;
	
}

