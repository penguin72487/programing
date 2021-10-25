#include<iostream>
#include<vector>
using namespace std;
class node{
public:
    int data;
    node *n_next=nullptr;
    vector<node *> level;
    node(int tmp)
    {
        data = tmp;
    }
};
class skip_List{
public:
    node *op=nullptr;
    int i_size=0;
    skip_List()
    {

    }
    ~skip_List()
    {

    }
    void dis_Node(node* now)
    {
        if(!now)
        {
            return;
        }
        dis_Node(now->n_next);
        delete now;
    }
    void insert(int tmp)
    {
        if(op)
        {
            
            node *n_Pa = op;
            while(n_Pa&&tmp>n_Pa->data)
            {
                n_Pa = n_Pa->n_next;
            }
            if(n_Pa->n_next==nullptr)
            {

            }
            else
            {
                node *in_Node = new node(tmp);
                in_Node->n_next = n_Pa->n_next;
            }
            
            n_Pa->n_next = in_Node;
            n_Pa->level.push_back(n_Pa->n_next);
            ++i_size;
        }
        else
        {
            op = new node(tmp);
            op->level.push_back(op);
            ++i_size;
        }
    }
};
int main()
{
    int n;
    cin >> n;
    skip_List ksp;
    for (int i = 0; i < n;++i)
    {
        int tmp;
        cin >> tmp;
        ksp.insert(tmp);
    }
    for (auto it = ksp.op; it != nullptr;it=it->n_next)
    {
        cout << it->data << "\n";
    }
}
