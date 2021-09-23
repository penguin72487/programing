#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<limits>
using namespace std;
class node{
public:
    long long i_Sum=0;
    node* min_Node = this;
    
    //int i_Max = -2147483648;
    //node *pa_Node;
    //node *l_Node;
    //node *r_Node;
};
class Segment_Tree{
public:
    node* top=nullptr;
    node *t_Node;
    int size;
    Segment_Tree(int* tmp,int n)
    {
        
        
    }
    ~Segment_Tree()
    {
        
    }
    //node *build(node *op, node *ed);
    long long prior_Sum(node* op,node* ed)
    {
        long long t_Sum=0;
        
        return t_Sum;
    }
    node* rn_Min(node* op,node* ed)
    {
        return nullptr;
    }
    int i_Licky()
    {
        return 0;
    }
    int i_Licky(node *op, node *ed)
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
    Segment_Tree Licky(list,n);
    cout << Licky.i_Licky();
}