#include<iostream>
#include<unordered_map>
using namespace std;
class node{
public:
	int data;
	unordered_map<int,node*> in_List;//adj list
};
class graph{
public:
	node* op=nullptr;
	unordered_map<int,node*> in_Map;//int to node* map
    unordered_map<int, bool> ib_TrNode;
    graph()
	{
		
	}
	~graph()
	{
		for(auto it=in_Map.begin();it!=in_Map.end();++it)
		{
			delete it->second;
		}
		in_Map.clear();
	}
	void insert(int u,int v)
	{
		if(op)
		{
			node* u_Node;
			if(in_Map.find(u)==in_Map.end())
			{
				u_Node=new node;
				u_Node->data=u; 
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
			}
			else
			{
				v_Node=in_Map[v];
			}
            v_Node->in_List[u] = u_Node;
            u_Node->in_List[v] = v_Node;
        }
		else
		{
			op=new node;
			node* v_Node=new node;
			op->data=u;
			op->in_List[v]=v_Node;
			
			v_Node->data=v;
			v_Node->in_List[u]=op;
			
			in_Map[u]=op;
			in_Map[v]=v_Node;
		}
	}
	bool b_Circle()
	{
        ib_TrNode.clear();
        ib_TrNode[op->data] = 1;
        bool bt_Circle=0;
        for (auto it = op->in_List.begin(); it != op->in_List.end();++it)
        {
            bt_Circle=max(bt_Circle, b_Circle(op,it->second));
        }

        return bt_Circle;
    }
	bool b_Circle(node* op,node* ed)
	{
        bool bt_Circle=0;
        //cout<<ed->data<<"\n";
        if(ib_TrNode.find(ed->data)!=ib_TrNode.end())
        {
            return 1;
        }
        else 
        {
        	ib_TrNode[ed->data]=1;
            ed->in_List.erase(op->data);
            for (auto it = ed->in_List.begin(); it != ed->in_List.end();++it)
            {
                bt_Circle=max(bt_Circle, b_Circle(ed,it->second));
            }

        }
        return bt_Circle;
    }
	 
};
int main()
{
	graph tmp;
	tmp.insert(1,2);
	tmp.insert(2,3);
	tmp.insert(3,4);
	tmp.insert(3,1);
    cout<<tmp.b_Circle()<<"\n";
    return 0;
}

