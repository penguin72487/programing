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
	unordered_map<node*, int> ni_Vec;
    unordered_map<node *, int> ni_Backup;
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
        ib_TrNode.clear();
        int op = 1;
        int ed = 6;
        //in_Map[ed]->ni_Backup = in_Map[ed]->ni_Vec;
        //in_Map[ed]->ni_Vec.clear();
        int ans = 2147483647;
        ib_TrNode[op] = 1;
        if(in_Map[op]->ni_Vec.find(in_Map[ed])!=in_Map[op]->ni_Vec.end())
        {
            ans = in_Map[op]->ni_Vec[in_Map[ed]];   
        }
        for (auto it = in_Map[op]->ni_Vec.begin();it!=in_Map[op]->ni_Vec.end();++it)
        {
            //if(ib_TrNode.find(it->second)==ib_TrNode.end())
            {
                cout <<op<<"->"<< it->first->data << "dis" << it->second << " ";
               ans = min(ans, short_Distance(it->first->data, ed, it->second));
               cout << "\n";
            }
        }
        //in_Map[ed]->ni_Vec = in_Map[ed]->ni_Backup;
        return ans;
    }
    int short_Distance(int op,int ed,int totle)
    {
        //cout << op <<"->"<<ed<< " ";
        cout << "totle=" << totle << " ";
        if(op==ed)
        {
            //cout << "pop ";
            return totle;
        }
        ib_TrNode[op] = 1;
        //cout << op << "push ";
        if(in_Map[op]->ni_Vec.find(in_Map[ed])!=in_Map[op]->ni_Vec.end())
        {
            totle += in_Map[op]->ni_Vec[in_Map[ed]];
        }
        for (auto it = in_Map[op]->ni_Vec.begin();it!=in_Map[op]->ni_Vec.end();++it)
        {
            if(ib_TrNode.find(it->first->data)==ib_TrNode.end())
            {
                //cout <<"size="<<ib_TrNode.size()<< "";
                cout <<op<<"->"<< it->first->data << "dis" << it->second << " ";
                totle = min(totle, short_Distance(it->first->data, ed,totle+it->second));
            }            
        }
        return totle;
    }
};
int main()
{
    Graph tmp;
    
    tmp.insert(1, 2, 2);
    tmp.insert(1, 3, 5);
    tmp.insert(2, 4, 6);
    tmp.insert(2, 5, 10);
    tmp.insert(3, 5, 8);
    tmp.insert(3, 4, 9);
    tmp.insert(5, 6, 3);
    tmp.insert(4, 6, 4);
    cout << tmp.in_Map.size() << "\n";
    cout<<tmp.short_Distance()<<"\n";

    return 0;
}