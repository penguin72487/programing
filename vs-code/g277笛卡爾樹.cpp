#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<limits>
using namespace std;
class node{
public:
    long long i_Sum=0;
    node ()
    {

    }
    node(int tmp)
    {
        i_Sum = tmp;
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
            //cout <<"index val "<<i<<" "<<tmp[i]<< "insert " << insert_Ptr->i_Sum<<"\n";
            if(top)
            {
                node *t_Node = new node(tmp[i]);

                if(t_Node->i_Sum>insert_Ptr->i_Sum)
                {
                    cout <<"insert_Node "<<insert_Ptr->i_Sum<<" t_Node "<<t_Node->i_Sum<<" hi\n";

                    t_Node->pa_Node=insert_Ptr;
                    insert_Ptr->r_Node = t_Node;
                    insert_Ptr = t_Node;
                    dfs_Mid(top);
                    
                }
                else
                {
                    node *insert_Pa = insert_Ptr;

                    while(t_Node->i_Sum<insert_Pa->i_Sum&&insert_Pa!=top)
                    {
                        insert_Pa = insert_Pa->pa_Node;
                    }
                    
                    if(insert_Pa==top)
                    {
                            cout <<"insert_Node "<<insert_Ptr->i_Sum<<" t_Node "<<t_Node->i_Sum<<" hi top\n";

                            insert_Pa->pa_Node = t_Node;
                            t_Node->l_Node = insert_Pa;
                            insert_Ptr = t_Node;
                            //insert_Ptr->l_Node = top;
                            top = t_Node;
                            t_Node->pa_Node = t_Node;
                            insert_Ptr = t_Node;
                            dfs_Mid(top);
                            continue;
                    }

                    cout <<"insert_Node "<<insert_Pa->i_Sum<<" t_Node "<<t_Node->i_Sum<<" hi re\n";
                    
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
        dfs_Mid(top);
    }
    ~DC_Tree()
    {
        dis_Node(top);
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
            cout << now->i_Sum << " ";
            dfs_Mid(now->r_Node);
            
        }
        
    }
    int i_Licky()
    {
        return 0;
    }
};
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int list[n];
    for (int i = 0; i < n;++i)
    {
        cin >> list[i];
    }
    DC_Tree Licky(list,n);
    cout << Licky.i_Licky();
}