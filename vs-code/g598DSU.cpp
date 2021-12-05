#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<algorithm>
#include<deque>
#include<set>
using namespace std;
class node{
public:
	int data;
    node *pa=nullptr;
    node *oppo=nullptr;
    node (int tmp)
    {
        data = tmp;
    }
    node* Gpa()
    {
        node *now = pa;
        while(now)
        {
            now = now->pa;
        }
        return now;
    }
};
class DSU{
	public:
	node* op=nullptr;
	unordered_map<int,node*> in_Map;
	unordered_map<int,bool> ib_TrNode;

    DSU()
	{
	}
	~DSU()
	{
		for(auto it=in_Map.begin();it!=in_Map.end();++it)
		{
			delete it->second;	
		}
        
    }
    void insert(int u,int v)
    {
        bool u_init=(in_Map.find(u)==in_Map.end());
        bool v_init=(in_Map.find(v)==in_Map.end());
        node *u_Node;
        node *v_Node;
        if(u_init&&v_init)
        {
            u_Node = new node(u);
            in_Map[u] = u_Node;
            v_Node = new node(v);
            in_Map[v] = v_Node;
            u_Node->oppo = v_Node;
            v_Node->oppo = u_Node;
        }
        else if(!u_init&&!v_init)
        {
            u_Node = in_Map[u];
            v_Node = in_Map[v];
            
        }
        else
        {
            if(u_init)
            {

            }
            else
            {

            }
        }

    }
    
};
int main()
{
    DSU tmp;
    

    return 0;
}