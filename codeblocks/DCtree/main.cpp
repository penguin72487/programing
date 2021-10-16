#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<limits>
using namespace std;
class node{
public:
    long long i_Sum = 0;
    int data;

    node ()
    {

    }

    node(int tmp)
    {
        data = tmp;
        i_Sum = data;

    }
    //node* min_Node = this;
    //int i_Max = -2147483648;
    node *l_Node = nullptr;
    node *r_Node = nullptr;
    bool operator <(node* val2)
    {
        return (data < val2->data);
    }

    bool operator()(node* val,node* val2)
    {
        return (val->data < val2->data);
    }
    bool operator()(node &val,node &val2)
    {
        return (val.data < val2.data);
    }

};
class DC_Tree
{
public:
    node *top;
    vector<node *> r_List;

    DC_Tree()
    {
        top = new node(0);
        r_List.push_back(top);
    }
    ~DC_Tree()
    {
        dis_Node();
    }
    void dis_Node()
    {
        dis_Node(top);
    }
    void dis_Node(node* now)
    {
        if(!now)
        {
            return;


        }
        dis_Node(now->l_Node);
        dis_Node(now->r_Node);
        delete now;
    }
    void insert(int tmp)
    {
        if(r_List.size()!=1)
        {
            if(tmp>r_List.back()->data)
            {
                r_List.back()->r_Node = new node(tmp);
                r_List.push_back(r_List.back()->r_Node);
            }
            else
            {
                node *in_Node = new node(tmp);
                auto it = lower_bound(r_List.begin(), r_List.end(), in_Node,node());
                (*it)->l_Node = (*it)->r_Node;
                (*it)->r_Node = in_Node;
                r_List.erase(it+1, r_List.end());
                r_List.push_back((*it)->r_Node);
            }
        }
        else
        {
            top->r_Node = new node(tmp);
            r_List.push_back(top->r_Node);
        }
    }
    void mid_Trace()
    {
        mid_Trace(top);
    }
    void mid_Trace(node *now)
    {
        if(!now)
        {
            return;
        }
        mid_Trace(now->l_Node);
        cout << now->data << "\n";
        mid_Trace(now->r_Node);
    }
    int i_Licky();

};
int main()
{
    int n;
    cin >> n;
    DC_Tree Licky;
    for (int i = 0; i < n;++i)
    {
        int tmp;
        cin >> tmp;
        Licky.insert(tmp);
    }
    Licky.mid_Trace();
}
