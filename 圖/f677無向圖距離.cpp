#include<iostream>
#include<unordered_map>
using namespace std;
class node{
public:
	int data;
	unordered_map<int,node*> in_Map;
};
class infect{
	node* op=nullptr;
	unordered_map<int,node*> in_List;
	void insert(int a,int b)
	{
		if(op)
		{
			node* l_Node;
			node* r_Node;
			if(in_List.find(a)==in_List.end())
			{
				
			}
			
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
	for(int i=0;i<m;++i)
	{
		
	}

}

