#include<iostream>
#include<algorithm>
using namespace std;
class node{
public :
	int data;
	node* l_Node=nullptr;
	node* r_Node=nullptr;
};

class BinaryTree{
public:
	node* op=nullptr;
	BinaryTree()
	{

	}
	~BinaryTree()
	{
		 dis_Node(op);
	}
	void dis_Node(node* op)
	{
		if(op)
		{
			dis_Node(op->l_Node);
			dis_Node(op->r_Node);
			delete op;
			
		}
	}
	void insert(int tmp)
	{
		if(op)
		{
			find_NodePtr(tmp,op);
		}
		else
		{
			op=new node;
			op->data=tmp;
		}
	}
	void find_NodePtr(int tmp,node* now)
	{
		if(tmp<now->data)
		{
			if(now->l_Node)
			{
				find_NodePtr(tmp,now->l_Node);
				return ;
			}
			else
			{
				node* lt_Node=new node;
				lt_Node->data=tmp;
				now->l_Node=lt_Node;
				return ;
			}
		}
		else
		{
			if(now->r_Node)
			{
				find_NodePtr(tmp,now->r_Node);
				return ;
			}
			else
			{
				node* rt_Node=new node;
				rt_Node->data=tmp;
				now->r_Node=rt_Node;
				return ;
			}
			
		}
	}
	bool ib_find(int tmp,node* now)
	{
		bool bt_L,bt_R;
		if(now)
		{
			if(now->data!=tmp)
			{
				if(now->data>tmp)
				{
					return ib_find(tmp,now->l_Node);
				}
				else
				{
					return ib_find(tmp,now->r_Node);
				}
			}
			else
			{
				return 1;
			}
			
		}
		return 0;
	
	}
	
};
int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	int list[n];
	BinaryTree tree;
	for(int i=0;i<n;++i)
	{
		cin>>list[i];
		tree.insert(list[i]);
	}
	sort(list,list+n);
	int tmp;
	for(int i=0;i<n;++i)
	{
		cout<<list[i]<<"\n";
	}
	cin>>tmp;
	if(tree.ib_find(tmp,tree.op))
	{
		cout<<"Yes\n";
	}
	else
	{
		cout<<"No\n";
	}

	

}

