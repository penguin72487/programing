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
    int i_opVec=2147483647;
    unordered_map<node*, int> ni_Vec;
    unordered_map<node *, int> ni_Backup;
};
class Graph{
	public:
	node* op=nullptr;
	map<int,node*> in_Map;
	unordered_map<int,bool> ib_TrNode;

    Graph()
	{
	}
	~Graph()
	{
		for(auto it=in_Map.begin();it!=in_Map.end();++it)
		{
			delete it->second;	
		}
        
    }
    void insert(int u,int v,int w)
    {
        if(op)
        {
            node* u_Node;
			if(in_Map.find(u)==in_Map.end())
			{
				u_Node=new node;
                u_Node->data = u;
                in_Map[u] = u_Node;
            }
			else
			{
				u_Node=in_Map[u];
			}
			node* v_Node;
			if(in_Map.find(v)==in_Map.end())
			{
				v_Node=new node;
				v_Node->data=v;
                in_Map[v] = v_Node;
            }
			else
			{
				v_Node=in_Map[v];
			}
            v_Node->ni_Vec[u_Node] = w;
            u_Node->ni_Vec[v_Node] = w;
            
        }
        else
        {
            node* u_Node=new node;
			op=u_Node;
			u_Node->data=u;
			node* v_Node=new node;
			v_Node->data=v; 
			op->ni_Vec[v_Node]=w;
			v_Node->ni_Vec[op]=w;
            in_Map[v_Node->data] = v_Node;
            in_Map[u_Node->data] = u_Node;
        }
    }
    int short_Distance()
    {
        deque<node *> list;
        in_Map.begin()->second->i_opVec = 0;
        ib_TrNode[in_Map.begin()->second->data] = 1;
        list.push_back(in_Map.begin()->second);
        while(!list.empty())
        {
            node *now = list.front();
            cout << now->data << " ";
            list.pop_front();
            ib_TrNode[now->data] = 1;
            for (auto it = now->ni_Vec.begin(); it != now->ni_Vec.end();++it)
            {
                if(ib_TrNode.find(it->first->data)==ib_TrNode.end())
                {
                    list.push_back(it->first);
                    it->first->i_opVec = min(it->first->i_opVec,now->i_opVec+it->second);
                }
            }
        }
        cout << "\n";
        return (--in_Map.end())->second->i_opVec;
    }
};
int main()
{
    Graph tmp;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tmp.insert(a, b, c);
    }
    cout<<tmp.short_Distance()<<"\n";

    return 0;
}