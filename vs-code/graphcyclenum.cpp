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
    vector<node*> n_Vec;
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
            v_Node->n_Vec.push_back(u_Node);
            u_Node->n_Vec.push_back(v_Node);
            
        }
        else
        {
            node* u_Node=new node;
			op=u_Node;
			u_Node->data=u;
			node* v_Node=new node;
			v_Node->data=v; 
			op->n_Vec.push_back(v_Node);
			v_Node->n_Vec.push_back(op);
            in_Map[v_Node->data] = v_Node;
            in_Map[u_Node->data] = u_Node;
        }
    }
    int traced_Num()
    {
        int ans=0;
        deque<node*> stl;
        stl.push_back(in_Map[1]);
        ib_TrNode[1] = 1;
        while (!stl.empty())
        {
            node* now=stl.front();
            cout << now->data << "\n";
            stl.pop_front();
            for(auto it=now->n_Vec.begin();it!=now->n_Vec.end();++it)
            {
                if(ib_TrNode.find((*it)->data)==ib_TrNode.end())
                {
                    stl.push_back(in_Map[(*it)->data]);
                    ib_TrNode[(*it)->data] = 1;
                }
                else
                {
                    ++ans;
                }
            }
        }
        


        return ans;

    }
};
int main()
{
    Graph tmp;
    
    tmp.insert(1, 2);
    tmp.insert(1, 3);
    tmp.insert(2, 3);
    tmp.insert(4, 2);//2
    tmp.insert(4, 3);//2
    //tmp.insert(5, 4);//3
    //tmp.insert(5, 3);//3
    tmp.insert(5, 4);//
    tmp.insert(5, 6);
    tmp.insert(6, 3);
    //cout << tmp.in_Map.size() << "\n";
    cout<<tmp.traced_Num()<<"\n";

    return 0;
}