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
    node *min_Node;
    node()
    {
        min_Node = this;
    }
    //int i_Max = -2147483648;
    node *pa_Node;
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
        t_Node = new node [n];
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
        pa->l_Node->pa_Node = pa;
        pa->r_Node->pa_Node = pa;
        if(pa->l_Node->i_Min<pa->r_Node->i_Min)
        {
            pa->i_Min = pa->l_Node->i_Min;
            pa->min_Node = pa->l_Node->min_Node;
        }
        else
        {
            pa->i_Min = pa->r_Node->i_Min;
            pa->min_Node = pa->r_Node->min_Node;
        }
        pa->i_Sum = pa->l_Node->i_Sum + pa->r_Node->i_Sum;
        return pa;
    }
    long long prior_Sum(node* op,node* ed)
    {
        long long t_Sum=0;
        while(op<ed)
        {
            if(op==op->pa_Node->r_Node)
            {
                t_Sum += op->i_Sum;
            }
            if(ed==ed->pa_Node->l_Node)
            {
                t_Sum += ed->i_Sum;
            }
            op = op->pa_Node;
            ed = ed->pa_Node;
        }
        
        return t_Sum;
    }
    node* r_Min(node* op,node* ed)
    {
        return top;
    }
    int i_Licky()
    {
        return i_Licky(t_Node, t_Node + (sizeof(t_Node) / 4)-1);
    }
    int i_Licky(node* op,node* ed)
    {
        if(op+1==ed)
        {
            return op->i_Sum;
        }
        node *min_Node = r_Min(op, ed);
        if(prior_Sum(op,min_Node)>prior_Sum(min_Node+1,ed))
        {
            return i_Licky(op, min_Node);
        }
        else
        {
            return i_Licky(min_Node+1, ed);
        }
        


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
    cout << Licky.i_Licky();
}