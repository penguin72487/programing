#include<iostream>
#include<unordered_map>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
class node {
public:
    node(int tmp)
    {
        data=tmp;
    }
    int data;
    vector<node*> list;

};
class graph{
public:
    node* op=nullptr;
    int n,m;
    unordered_map<int,node*> in_Map;
    unordered_map<int,bool> ib_Map;
    graph(int tmp,int ttmp){
        n=tmp;
        m=ttmp;
    }
    ~graph()
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
            node* v_Node;
            if(in_Map.find(u)==in_Map.end())
            {
                u_Node=new node (u);
            }
            else
            {
                u_Node=in_Map[u];
            }
            if(in_Map.find(v)==in_Map.end())
            {
                v_Node=new node (v);
            }
            else
            {
                v_Node=in_Map[v];
            }
            u_Node->list.push_back(v_Node);
            
        }
        else
        {
            op = new node(u);
            node* v_Node=new node(v);
            in_Map[u]=op;
            in_Map[v]=v_Node;
            op->list.push_back(v_Node);
        }
    }
    bool b_Alltr()
    {
        dfs_Tr(in_Map[1],ib_Map);
        
        if(ib_Map.size()==n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void dfs_Tr(node* now,unordered_map<int,bool> &ib_Map)
    {
        //unordered_map<int,bool> ib_Map;
        ib_Map[now->data]=1;
        cout<<now->data<<"\n";
        for(auto it=now->list.begin();it!=now->list.end();++it)
        {
            if(ib_Map.find((*it)->data)==ib_Map.end())
            {
                dfs_Tr(*it,ib_Map);
            }
            
        }
            

    }

};
int main()
{
    
    int n,m;
    cin>>n>>m;
    graph tr_Line(n,m);
    int u,v;
    for(int i=0;i<m;++i)
    {
        cin>>u>>v;
        tr_Line.insert(u,v);
    }
    if(tr_Line.b_Alltr())
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }

}