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
	map<node*, int> ni_Vec;
    map<node *, int> ni_Backup;
};
class node_Vec{
public:
	int u;
	int v;
	int w;
	node_Vec()
	{
		
	}
	node_Vec(int t_u,int t_v,int t_w)
	{
		u=t_u;
		v=t_v;
		w=t_w;
	}
	bool operator()(node_Vec val,node_Vec val2)
	{
		if(val.w!=val2.w)
		{
			return val.w<val2.w;
		}
		else
		{
			if(val.u!=val2.u)
			{
				return val.u<val2.u;
			}
			else
			{
				return val.v<val2.v;
			}
		}
	}
};
class min_Tree{
	public:
	node* op=nullptr;
	map<int,node*> in_Map;
	map<int,bool> ib_TrNode;
	
	min_Tree()
	{
	}
	~min_Tree()
	{
		for(auto it=in_Map.begin();it!=in_Map.end();++it)
		{
			delete it->second;	
		}	
	}	
	bool insert(int u,int v,int w)
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

            if(b_Circle()==0)
            {
                return 1;
            }
            else
            {
                u_Node->ni_Vec.erase(v_Node);
                u_Node->ni_Backup.erase(v_Node);
                v_Node->ni_Vec.erase(u_Node);
                v_Node->ni_Backup.erase(u_Node);

                return 0;
            }
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
            return 1;
        }	
	}
	bool b_Circle()
	{
        ib_TrNode.clear();
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            it->second->ni_Backup = it->second->ni_Vec;
        }
       // cout << op->data << " ";
        ib_TrNode[op->data] = 1;
        bool bt_Circle=0;
        for (auto it = op->ni_Vec.begin(); it != op->ni_Vec.end();++it)
        {
                bt_Circle=max(bt_Circle, b_Circle(op,it->first));
        }
        //cout << "\n";
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            it->second->ni_Vec = it->second->ni_Backup;
        }
        return bt_Circle;
    }
	bool b_Circle(node* op,node* ed)
	{
        bool bt_Circle=0;
        //cout<<ed->data<<" ";
        if(ib_TrNode.find(ed->data)!=ib_TrNode.end())
        {
            ib_TrNode[ed->data]=1;   
            return 1;
        }
        else 
        {
        	ib_TrNode[ed->data]=1;
            ed->ni_Vec.erase(op);
            for (auto it = ed->ni_Vec.begin(); it != ed->ni_Vec.end();++it)
            {
                bt_Circle=max(bt_Circle, b_Circle(ed,it->first));
            }

        }
        return bt_Circle;
    }
    void bfs_TrNode()
    {
        ib_TrNode.clear();
        deque<node*> list;
        list.push_back(op);
        while(!list.empty())
        {
            node *now = list.front();
            list.pop_front();
            //cout << now->data << "\n";
            
            ib_TrNode[now->data] = 1;
            for (auto it = now->ni_Vec.begin(); it != now->ni_Vec.end();++it)
            {
                if(ib_TrNode[it->second]==0)
                {  
                    list.push_back(it->first);
                }
            }
            
        }
    }
};
int main()
{
	int n,m;
	cin>>n>>m;
	min_Tree tree;
    vector<node_Vec> vec;
	for(int i=0;i<m;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
        vec.push_back(node_Vec(a, b, c));
	}
	sort(vec.begin(),vec.end(),node_Vec());

    for (auto it = vec.begin(); it != vec.end();++it)
    {
        
        bool b_Tmp = tree.insert(it->u, it->v, it->w);
        //cout << it->u << "->" << it->v <<" "<< it->w <<" ok?"<<b_Tmp<< "\n";
        //tree.bfs_TrNode();
        if(!b_Tmp)
        {
            it->w = 0;
        }
        
    }
    
    //cout <<"size="<< tree.in_Map.size() << "\n";
    
    int totle = 0;
    for (auto it = vec.begin(); it != vec.end();++it)
    {
        //cout << it->u << "->" << it->v <<" "<< it->w << "\n";
        totle += it->w;
    }
    cout << totle << "\n";
} 
