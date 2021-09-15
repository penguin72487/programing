#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<limits>
using namespace std;
class node{
public:
    long long i_Sum=0;
    //node* min_Node = this;
    //int i_Max = -2147483648;
    //node *pa_Node;
    node *l_Node;
    node *r_Node;
};
class DC_Tree
{
public:
    node *top=nullptr;
    DC_Tree(int* tmp,int n)
    {
        for (int i = 0; i < n;++i)
        {
            if(top)
            {
                
            }
            else
            {
                node *op = new node;
                op->i_Sum = tmp[i];
                top = op;
            }
        }
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