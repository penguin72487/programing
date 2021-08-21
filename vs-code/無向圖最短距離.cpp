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
class Graph{
	public:
	node* op=nullptr;
	unordered_map<int,node*> in_Map;
	unordered_map<int,bool> ib_TrNode;
    int **dis_List=nullptr;

    Graph()
	{
	}
	~Graph()
	{
		for(auto it=in_Map.begin();it!=in_Map.end();++it)
		{
			delete it->second;	
		}
        if(dis_List)
        {
            for (int i = 0; i < in_Map.size();++i)
            {
                delete dis_List[i];
            }
            delete[] dis_List;
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
        
        dis_List = new int*[in_Map.size()];
        for (int i = 0; i < in_Map.size();++i)
        {
            dis_List[i] = new int[in_Map.size()];
            fill(dis_List[i], dis_List[i] + in_Map.size(),2147483647);
        }
        
        for (auto it = in_Map.begin();it!=in_Map.end();++it)
        {
            
            for (auto jt = it->second->ni_Vec.begin();jt!=it->second->ni_Vec.end();++it)
            {
                cout << "hi\n";
                dis_List[it->first][jt->first->data] = jt->second;
            }
        }
        
        for (int i = 0; i < in_Map.size();++i)
        {
            dis_List[i][i] = 0;
        }
        for (int i = 0; i < in_Map.size();++i)
        {
            for (int j = 0; j < in_Map.size();++j)
            {
                cout<<dis_List[i][j]<<" ";
            }
            cout << "\n";
        }
            return 0;
    }
};
int main()
{
    Graph tmp;
    tmp.insert(0, 1, 2);
    tmp.insert(0, 2, 5);
    tmp.insert(1, 3, 6);
    tmp.insert(1, 4, 10);
    tmp.insert(2, 4, 8);
    tmp.insert(2, 3, 9);
    tmp.insert(4, 5, 3);
    tmp.insert(3, 5, 4);
    tmp.short_Distance();

    return 0;
}