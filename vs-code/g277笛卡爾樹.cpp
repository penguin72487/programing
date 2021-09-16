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
    node *pa_Node;
    node *l_Node;
    node *r_Node;
};
class DC_Tree
{
public:
    node *top=nullptr;
    DC_Tree(int* tmp,int n)
    {
        node *insert_Ptr;
        for (int i = 0; i < n;++i)
        {
            cout <<"index val "<<i<<" "<<tmp[i]<< "insert " << insert_Ptr->i_Sum<<" ";
            if(top)
            {
                node *t_Node = new node(tmp[i]);
                if(t_Node->i_Sum>insert_Ptr->i_Sum)
                {
                    //insert_Ptr->pa_Node = t_Node;
                    insert_Ptr->r_Node = t_Node;
                    insert_Ptr = t_Node;
                }
                else
                {
                    
                    while(t_Node->i_Sum<insert_Ptr->i_Sum&&insert_Ptr!=top)
                    {
                        insert_Ptr = insert_Ptr->pa_Node;
                    }
                    if(insert_Ptr==top)
                    {
                            insert_Ptr->pa_Node = t_Node;
                            t_Node->l_Node = insert_Ptr;
                            insert_Ptr = t_Node;
                            //insert_Ptr->l_Node = top;
                            top = t_Node;
                            continue;
                    }
                    insert_Ptr->pa_Node = t_Node;
                    t_Node->l_Node = insert_Ptr;
                    insert_Ptr = t_Node;
                    top = t_Node;

                    
                }
            }
            else
            {
                node *op = new node;
                op->i_Sum = tmp[i];
                top = op;
                insert_Ptr=top;
                insert_Ptr->pa_Node = top;
            }
        }
        dfs_Mid(top);
    }
    void dfs_Mid(node* now)
    {
        dfs_Mid(now->l_Node);
        cout << now->i_Sum<<" ";
        dfs_Mid(now->r_Node);
    }
    int i_Licky()
    {
        return 0;
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
    DC_Tree Licky(list,n);
    cout << Licky.i_Licky();
}