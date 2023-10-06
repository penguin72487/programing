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
	map<int,node*> in_Map;
    deque<int> grup_Trable;
    //map<int,bool> ib_TrNode;
    map<int, vector<node *>*> ivn_Map;

    Graph()
	{
	}
	~Graph()
	{
		for(auto it=in_Map.begin();it!=in_Map.end();++it)
		{
			delete it->second;	
		}
        for (auto it = ivn_Map.begin();it!=ivn_Map.end();++it)
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
    void solution(){
        bg_init_();
        while(!grup_Trable.empty())
        {
            b_BG(ivn_Map[*grup_Trable.begin()],*grup_Trable.begin(),ivn_Map.size()+1);

        }
    }
    void bg_init_()
    {
        ivn_Map[1] = new vector<node *>;
        for (auto it = in_Map.begin(); it != in_Map.end();++it)
        {
            ivn_Map[1]->push_back(it->second);
        }
        grup_Trable.push_back(1);
    }
    void b_BG(vector<node*> *tmp,int grup,int grup2)
    {
        grup_Trable.pop_front();
        int binary[3]={-1};
        binary[1] = grup;
        binary[2] = grup2;
        ivn_Map[grup2] = new vector<node *>;
        map<int, bool> ib_TrNode;
        for (auto it = tmp->begin(); it != tmp->end();++it)
        {
            (*it)->colour = -1;
        }
        deque<node *> stl;
        stl.push_back(*tmp->begin());
        int index = 1;
        stl.back()->colour = binary[index];
        ib_TrNode[(*tmp->begin())->data] = grup;
        while(!stl.empty())
        {
            node *now = stl.front();
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
                    (*it)->colour = binary[index^3];
                }
                else if((*it)->colour==now->colour)
                {
                    grup_Trable.push_back(now->colour);
                }
            }
        }
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
    
    tmp.insert(0, 3);
    tmp.insert(2, 3);
    tmp.insert(0, 1);
    tmp.insert(1, 2);
    //tmp.insert(4, 2);//2
    //tmp.insert(4, 3);//2
    //tmp.insert(5, 4);//3
    //tmp.insert(5, 3);//3
    //.insert(5, 4);
    //tmp.insert(5, 6);
    //tmp.insert(6, 3);
    //cout << tmp.in_Map.size() << "\n";
    tmp.solution();
    for (auto it = tmp.in_Map.begin(); it != tmp.in_Map.end();++it)
    {
        cout << it->second->colour << " ";
    }
    cout << "\n";

    return 0;
}