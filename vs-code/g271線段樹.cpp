#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<limits>
using namespace std;
class node{
public:
    long long i_Sum=0;
    int i_Min = 2147483647;
    //int i_Max = -2147483648;
    node *l_Node;
    node *r_Node;
};
class Segment_Tree{
public:
    node* top=nullptr;
    node *t_Node;
    Segment_Tree(int* tmp)
    {
        int n = sizeof(tmp)/4;
        t_Node = new node [n+1];
        for (int i = 0; i < n;++i)
        {
            t_Node[i].i_Sum = tmp[i];
        }
        top=build(t_Node, t_Node + n);
    }
    ~Segment_Tree()
    {
        dis_Tree(top);
    }
    void dis_Tree(node* now)
    {
        if(!now)
        {
            return;
        }
        dis_Tree(now->l_Node);
        dis_Tree(now->r_Node);
        delete now;
    }
    node* build(node *op,node* ed)
    {
        if(op+1==ed)
        {
            op->i_Min = op->i_Sum;
            return op;
        }
        node *pa = new node;
        int n = ed - op;
        pa->l_Node = build(op,op+(n>>1));
        pa->r_Node = build(op+(n>>1)+1,ed);
        pa->i_Min = min(pa->l_Node->i_Min, pa->r_Node->i_Min);
        pa->i_Sum = pa->l_Node->i_Sum + pa->r_Node->i_Sum;
        return pa;
    }
    long long prior_Sum(int op,int ed)
    {
        long long ans=0;
        
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n;++i)
    {
        cin >> list[i];
    }
    Segment_Tree Licky(list);
}