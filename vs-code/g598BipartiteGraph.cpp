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
    int colour=-1;
    vector<node*> n_Vec;
    node (int tmp)
    {
        data = tmp;
    }
};
class Graph{
	public:
	node* op=nullptr;
	unordered_map<int,node*> in_Map;
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
    void insert(int u,int v)
    {
        if(op)
        {
            node* u_Node;
			if(in_Map.find(u)==in_Map.end())
			{
                u_Node = new node(u);
                in_Map[u] = u_Node;
            }
			else
			{
				u_Node=in_Map[u];
			}
			node* v_Node;
			if(in_Map.find(v)==in_Map.end())
			{
				v_Node=new node(v);
                in_Map[v] = v_Node;
            }
			else
			{
				v_Node=in_Map[v];
			}
            v_Node->n_Vec.push_back(u_Node);
            u_Node->n_Vec.push_back(v_Node);
            
        }
        else
        {
            node* u_Node=new node(u);
			op=u_Node;
			node* v_Node=new node(v);
			op->n_Vec.push_back(v_Node);
			v_Node->n_Vec.push_back(op);
            in_Map[v_Node->data] = v_Node;
            in_Map[u_Node->data] = u_Node;
        }
    }
    bool b_BG()
    {
        deque<node*> stl;
        stl.push_back(in_Map[1]);
        stl.back()->colour = 1;
        ib_TrNode[1] = 1;
        while (!stl.empty())
        {
            node* now=stl.front();
            //cout << now->data << "\n";
            stl.pop_front();
            for(auto it=now->n_Vec.begin();it!=now->n_Vec.end();++it)
            {
                if(ib_TrNode.find((*it)->data)==ib_TrNode.end())
                {
                    stl.push_back(in_Map[(*it)->data]);
                    ib_TrNode[(*it)->data] = 1;

                }
                if((*it)->colour==-1)
                {
                    (*it)->colour = bool(0==now->colour);
                }
                else if((*it)->colour==now->colour)
                {
                    return 0;
                }
            }
        }
        


        return 1;

    }
    void operator=(Graph &tmp)
    {
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            tmp.in_Map[it->first] = new node(it->second->data);
            tmp.in_Map[it->first]->n_Vec = it->second->n_Vec;
        }
    }
};
int main()
{
    Graph tmp;
    
    //tmp.insert(1, 2);
    //tmp.insert(1, 4);
    //tmp.insert(3, 2);
    //tmp.insert(3, 4);
    //tmp.insert(4, 2);//2
    //tmp.insert(4, 3);//2
    //tmp.insert(5, 4);//3
    //tmp.insert(5, 3);//3
    //.insert(5, 4);
    //tmp.insert(5, 6);
    //tmp.insert(6, 3);
    //cout << tmp.in_Map.size() << "\n";
    int n, m,p,k;
    cin >> n>>m;
    for (int i = 0; i < m;++i)
    {
        int a, b;
        cin >> a >> b;
        tmp.insert(a,b);
    }
    cin >> p >> k;
    for (int i = 0; i < p;++i)
    {
        Graph grup = tmp;
        for (int j = 0; j < m;++j)
        {
            int a, b;
            cin >> a >> b;
            grup.insert(a, b);
        }
        if(!grup.b_BG())
        {
            cout << i + 1 << "\n";
        }

    }

        return 0;
}