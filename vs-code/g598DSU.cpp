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
        while(now->pa!=now)
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
            u_Node->pa = u_Node;
            v_Node->oppo = u_Node;
            v_Node->pa = v_Node;
        }
        else if(!u_init&&!v_init)
        {
            u_Node = in_Map[u];
            v_Node = in_Map[v];
            v_Node->Gpa()->pa = u_Node->oppo->Gpa();
            v_Node->oppo->Gpa()->pa = u_Node->Gpa();

        }
        else
        {
            if(!u_init)
            {
                u_Node = in_Map[u];
                v_Node = new node(v);
                in_Map[v] = v_Node;
                v_Node->pa = u_Node->oppo->Gpa();
                v_Node->oppo = u_Node->Gpa();
            }
            else
            {
                v_Node = in_Map[v];
                u_Node = new node(u);
                in_Map[u] = u_Node;
                u_Node->pa = v_Node->oppo->Gpa();
                u_Node->oppo = v_Node->Gpa();

            }
        }

    }
    bool re_Ward(int u,int v)
    {
        
        return 0;
    }
    void backup_Init_()
    {
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            in_Back[it->first] = new node(it->first);
        }
        for (auto it = in_Back.begin(); it != in_Back.end();++it)
        {
            it->second->oppo = in_Map[it->first]->oppo;
            it->second->pa = in_Map[it->first]->pa;

        }
    }
    void backup()
    {
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            if(in_Back.find(it->first)==in_Back.end())
            {
                delete it->second;
                it=prev(it);
                in_Map.erase(next(it));
            }
            else
            {
                it->second->pa = in_Map[it->first]->pa;
                it->second->oppo = in_Map[it->first]->oppo;
            }
        }
    }
};
int main()
{
    DSU tmp;
    int n,m,p,k;
    cin >> n >> m;
    int a, b;

    for (int i = 0; i < m;++i)
    {
        cin >> a >> b;
        tmp.insert(a,b);
    }
    tmp.backup_Init_();
    cin >> p >> k;
    for (int i = 0; i < p;++i)
    {
        
        int a, b;
        for (int j = 0; j < k;++j)
        {
            cin >> a >> b;
            tmp.insert(a, b);
        }
        tmp.backup();
    }
    return 0;
}