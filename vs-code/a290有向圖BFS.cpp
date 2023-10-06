#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
class node{
public:
    int data;
    vector<node *> n_Vec;
    node()
    {

    }
    node (int tmp)
    {
        data = tmp;
    }
};
class road{
public :
    node *op = nullptr;
    unordered_map<int, node *> in_Map;
    unordered_map<int, bool> ib_TrNode;

    road ()
    {

    }
    ~road ()
    {
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            delete it->second;
        }
        in_Map.clear();

    }
    void insert(int u,int v)
    {
        if(op)
        {
            node *u_Node;
            node *v_Node;
            if(in_Map.find(u)==in_Map.end())
            {
                u_Node = new node(u);
            }
            else
            {
                u_Node = in_Map[u];
            }
            if(in_Map.find(v)==in_Map.end())
            {
                v_Node = new node(v);
            }
            else
            {
                v_Node = in_Map[v];
            }
            u_Node->n_Vec.push_back(v_Node);

        }
        else
        {
            node *u_Node=new node;
            node *v_Node = new node;
            u_Node->data = u;
            v_Node->data = v;
            u_Node->n_Vec.push_back(v_Node);
            in_Map[u] = u_Node;
            in_Map[v] = v_Node;
        }
    }
    bool b_Arrive(int op,int ed)
    {
        deque<node *> list;
        list.push_back(in_Map[op]);
        ib_TrNode[op] = 1;
        while(!list.empty())
        {
            node *now = list.front();
            
            if(now->data==ed)
            {
                return 1;
            }
            ib_TrNode[now->data] = 1;
            for (auto it = now->n_Vec.begin(); it != now->n_Vec.end();++it)
            {
                if(ib_TrNode.find((*it)->data)==ib_TrNode.end())
                {
                    list.push_back(*it);
                }
                
            }
            list.pop_front();
        }
        return 0;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    int n, m;
    while(cin>>n>>m)
    {
        road tmp;
        for (int i = 0; i < m;++i)
        {
            int a, b;
            cin >> a >> b;
            tmp.insert(a, b);
        }
        int a, b;
        cin >> a >> b;
        if(tmp.b_Arrive(a,b))
        {
            cout << "Yes!!!\n";
        }
        else
        {
            cout << "No!!!\n";
        }
    }
    
    return 0;
}