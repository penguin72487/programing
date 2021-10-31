#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<limits>
using namespace std;
class node{
public:
    long long i_Sum=0;
    
    //int i_Max = -2147483648;
    //node *pa_Node;
    //node *l_Node;
    //node *r_Node;
};
class Segment_Tree{
public:
    //node* top=nullptr;
    node *t_Node;
    long long int ans = 0;
    int size;
    Segment_Tree(vector<pair<int,int>> &a)
    {
        size = a.size();
        t_Node = new node[size << 1];
        for (auto it = ++a.begin(); it != a.end();++it)
        {
            t_Node[size - 1 + it->first].i_Sum = 1;
            t_Node[size - 1 + it->second].i_Sum = 1;
            ans += rang_Sum(it->first, it->second);
            update(it->first, it->second);
        }
    }
    ~Segment_Tree()
    {
        delete [] t_Node;
    }
    long long int rang_Sum(int op,int ed)//(op,ed)
    {
        //long long int ans=0;
        while(op<ed)
        {
            
            if(op&1)
            {
                ++op;
            }
            if(ed&1)
            {
                
            }
            else
            {
                --ed;
            }
            op >>= 1;
            ed >>= 1;
        }
        
        return t_Node[op].i_Sum;
    }
    void update(int op,int ed)
    {
        while(op>1)
        {
            op >>=1;
            ++t_Node[op].i_Sum;
            
        }
        while(ed>1)
        {
            ed >>= 1;
            ++t_Node[ed].i_Sum;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    int N = (n << 1)+1;
    vector<pair<int, int>> a(n+1);
    int tmp;
    for (int i = 1; i < N;++i)
    {
        
        cin >> tmp;
        if(a[tmp].first)
        {
            a[tmp].second = i;
        }    
        else
        {
            a[tmp].first = i;
        }
    }
    Segment_Tree low_Dis(a);
    cout << low_Dis.ans << "\n";
}