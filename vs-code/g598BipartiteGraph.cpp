#include<iostream>
#include<vector>
#include<map>
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
    set<int> i_Node;
    map<int,node*> in_Map;
    map<int, node *> in_Backup;
    map<int,bool> ib_TrNode;

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
    void insert(int &u,int &v,bool flag)
    {
        if(flag)
        {
            i_Node.insert(u);
            i_Node.insert(v);
        }
        
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
    void backup_Init_()
    {
        for (auto it = i_Node.begin(); it != i_Node.end();++it)
        {
            in_Backup[*it] = new node(*it);
        }
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            for (auto jt = it->second->n_Vec.begin(); jt != it->second->n_Vec.end();++jt)
            {
                in_Backup[it->first]->n_Vec.push_back(in_Backup[(*jt)->data]);
            }
               
        }
    }
    void backup()
    {
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            delete it->second;
        }
        in_Map.clear();
        for (auto it = in_Backup.begin(); it != in_Backup.end();++it)
        {
            in_Map[it->first] = it->second;
        }
        in_Backup.clear();
    }
    
    bool b_BG()
    {
        ib_TrNode.clear();
        deque<node*> stl;
        stl.push_back(in_Map.begin()->second);
        stl.back()->colour = 1;
        ib_TrNode[in_Map.begin()->first] = 1;
        while (!stl.empty())
        {
            node* now=stl.front();
            //cout <<"dd "<< now->data << "\n";
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
                    (*it)->colour = !now->colour;
                }
                else if((*it)->colour==now->colour)
                {
                    return 0;
                }
            }
        }
        


        return 1;

    }
    
    void print_AdjList()
    {
        for (auto it = in_Map.begin(); it != in_Map.end(); ++it)
        {
            cout << it->first << ": ";
            for(auto jt=it->second->n_Vec.begin();jt!=it->second->n_Vec.end();++jt)
            {
                cout << (*jt)->data<<" ";
            }
            cout << "\n";
        }
    }
    
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Graph tmp;
    
    //tmp.insert(1, 0);
    //tmp.insert(0, 2);
    //tmp.insert(1, 3);
    //tmp.insert(2, 3);
    //tmp.insert(4, 5);

    //tmp.insert(0, 6);
    //tmp.insert(0, 3);
    //tmp.insert(3, 5);
    
    //cout << tmp.b_BG() << "\n";
    
    int n, m,p,k;
    cin >> n>>m;
    for (int i = 0; i < m;++i)
    {
        int a, b;
        cin >> a >> b;
        tmp.insert(a,b,1);
    }
    //tmp.print_AdjList();
    cin >> p >> k;
    for (int i = 0; i < p;++i)
    {
        tmp.backup_Init_();
        int a, b;
        for (int j = 0; j < k;++j)
        {
            cin >> a >> b;
            tmp.insert(a, b,0);
        }
        if(!tmp.b_BG())
        {
            cout << i+1 << "\n";
        }
        tmp.backup();
    }

        return 0;
}