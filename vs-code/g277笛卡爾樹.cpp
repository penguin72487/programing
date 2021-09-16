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
    node *pa_Node = nullptr;
    node *l_Node = nullptr;
    node *r_Node = nullptr;
};
class DC_Tree
{
public:
    node *top=nullptr;
    DC_Tree(int* tmp,int n)
    {
        node *insert_Ptr=nullptr;
        for (int i = 0; i < n;++i)
        {
            //cout <<"index val "<<i<<" "<<tmp[i]<< "insert " << insert_Ptr->data<<"\n";
            if(top)
            {
                node *t_Node = new node(tmp[i]);

                if(t_Node->data>insert_Ptr->data)
                {
                    //cout <<"insert_Node "<<insert_Ptr->data<<" t_Node "<<t_Node->data<<" hi\n";

                    t_Node->pa_Node=insert_Ptr;
                    insert_Ptr->r_Node = t_Node;
                    insert_Ptr = t_Node;
                    //dfs_Mid(top);
                    
                }
                else
                {
                    node *insert_Pa = insert_Ptr;

                    while(t_Node->data<insert_Pa->data&&insert_Pa!=top)
                    {
                        insert_Pa = insert_Pa->pa_Node;
                        cout << "while " << insert_Pa->data << " ";
                    }
                    
                    if(insert_Pa==top)
                    {
                            cout <<"insert_Node "<<insert_Ptr->data<<" t_Node "<<t_Node->data<<" hi top\n";

                            insert_Pa->pa_Node = t_Node;
                            t_Node->l_Node = insert_Pa;
                            insert_Ptr = t_Node;
                            //insert_Ptr->l_Node = top;
                            top = t_Node;
                            t_Node->pa_Node = t_Node;
                            insert_Ptr = t_Node;
                            //dfs_Mid(top);
                            continue;
                    }

                    //cout <<"insert_Node "<<insert_Pa->data<<" t_Node "<<t_Node->data<<" hi re\n";
                    
                    insert_Ptr->pa_Node = t_Node;
                    insert_Pa->r_Node = t_Node;
                    t_Node->pa_Node = insert_Pa;
                    t_Node->l_Node = insert_Ptr;
                    insert_Ptr = t_Node;
                    //top = t_Node;
                   // dfs_Mid(top);
                    
                    
                }
            }
            else
            {
                node *op = new node(tmp[i]);
                top = op;
                insert_Ptr=top;
                insert_Ptr->pa_Node = top;
                //dfs_Mid(top);
            }
        }
        dfs_Mid();
    }
    ~DC_Tree()
    {
        dis_Node(top);
    }    
    void dfs_Mid()
    {
        dfs_Mid(top);
        cout << "\n";
    }
    void dis_Node(node* now)
    {
        if(now)
        {
            dis_Node(now->l_Node);
            dis_Node(now->r_Node);
            delete now;
        }
    }
    void dfs_Mid(node* now)
    {
        if(now)
        {
            dfs_Mid(now->l_Node);
            cout << now->data << " ";
            dfs_Mid(now->r_Node);
            
        }
        
    }
    void dfs_Sum()
    {
        dfs_Sum(top);
    }
    void dfs_Sum(node* now)
    {
        if(now)
        {
            dfs_Sum(now->l_Node);
            //cout << now->i_Sum << " ";
            dfs_Sum(now->r_Node);
            now->pa_Node->i_Sum += now->i_Sum;
        }
        

    }
    int i_Licky()
    {
        dfs_Sum();
        node *now = top;
        while(now->l_Node!=nullptr||now->r_Node!=nullptr)
        {
            cout <<"op "<< now->data << " ";

            if(!now->r_Node&&now->l_Node->i_Sum>now->r_Node->i_Sum)
            {
                now = now->l_Node;
            }
            else
            {
                now = now->r_Node;
            }
        }
        cout << "hi\n";
        return now->data;
    }
};
int main()
{
    //cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n;++i)
    {
        cin >> list[i];
    }
    DC_Tree Licky(list,n);
    
    cout <<"ans = "<< Licky.i_Licky();
}