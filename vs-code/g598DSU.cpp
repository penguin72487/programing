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
        if(!now)
        {
            return this;
        }
        while(now->pa)
        {
            now = now->pa;
        }
        return now;
    }
    /*
    node* oppo_Gpa()
    {
        node *now = oppo;
        if(!now)
        {
            return this;
        }
        while(now->oppo)
        {
            now = now->oppo;
        }
        return now;
    }
    */
};
class DSU{
	public:
	node* op=nullptr;
	unordered_map<int,node*> in_Map;
    unordered_map<int, node *> in_Back;
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
            if(v_Node->Gpa()->pa != u_Node->oppo->Gpa())
            {
                v_Node->Gpa()->pa = u_Node->oppo->Gpa();
            }
            if(v_Node->oppo->Gpa()->pa != u_Node->Gpa())
            {
                v_Node->oppo->Gpa()->pa = u_Node->Gpa();
            }
            

        }
        else
        {
            if(!u_init)
            {
                u_Node = in_Map[u];
                v_Node = new node(v);
                in_Map[v] = v_Node;
                if(v_Node->pa != u_Node->oppo->Gpa())
                {
                    v_Node->pa = u_Node->oppo->Gpa();
                }
                if(v_Node->oppo != u_Node->Gpa())
                {
                    v_Node->oppo = u_Node->Gpa();
                }
            }
            else
            {
                v_Node = in_Map[v];
                u_Node = new node(u);
                in_Map[u] = u_Node;
                if(u_Node->pa != v_Node->oppo->Gpa())
                {
                    u_Node->pa = v_Node->oppo->Gpa();
                }
                if(u_Node->oppo != v_Node->Gpa())
                {
                    u_Node->oppo = v_Node->Gpa();
                }

            }
        }

    }
    
};
int main()
{
    DSU tmp;
    int n,m;
    cin >> n >> m;
    int a, b;

    for (int i = 0; i < m;++i)
    {
        cin >> a >> b;
        tmp.insert(a,b);
    }

        return 0;
}