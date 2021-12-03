#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
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
    vector<node> t_Node;
    long long int ans = 0;
    int size;
    int max_size;
    int index_Op;
    Segment_Tree(vector<pair<int,int>> &a)
    {
        size = (a.size()-1)*2;
        index_Op = size;
        t_Node.resize(2*size);
        for (auto it = ++a.begin(); it != a.end();++it)
        {
            rang_Sum(index_Op + it->first,index_Op + it->second);
            update(index_Op + it->first,index_Op + it->second);
            
        }
    }
    ~Segment_Tree()
    {
        //delete [] t_Node;
    }
    void rang_Sum(int op,int ed)//(op,ed)
    {
        //long long int ans=0;
        int i_op = op+1;
        int i_ed = ed;
        while(i_op<i_ed)
        {
            
            if(i_op&1)
            {
                ans += t_Node[i_op].i_Sum;
                ++i_op;
                
            }
            if(i_ed&1)
            {
                
                 --i_ed;
                 ans += t_Node[i_ed].i_Sum;
                

            }

            i_op >>= 1;
            i_ed >>= 1;
        }
        //return 0;
        return;
    }
    void update(int op,int ed)
    {
        while(op>0)
        {
            ++t_Node[op].i_Sum;
            op >>=1;
           
            
        }
        while(ed>0)
        {
            ++t_Node[ed].i_Sum;
            ed >>= 1;
            
        }
    }

};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    //fstream file;
    //file.open("f315p409_in.txt");
    cin>>n;
    int N = (n << 1)+1;
    vector<pair<int, int>> a(n+1);
    for (auto it = a.begin(); it != a.end();++it)
    {
        it->first = -1;
        it->second = -1;
    }
    int tmp;
    for (int i = 1; i <N;++i)
    {
        
        cin >> tmp;
        if(a[tmp].first!=-1)
        {
            a[tmp].second = i-1;
        }    
        else
        {
            a[tmp].first = i-1;
        }
    }
    /*
    for (auto it = a.begin(); it != a.end();++it)
    {
        cout << it->first << " " << it->second << "\n";
    }
    */
        Segment_Tree low_Dis(a);
    cout << low_Dis.ans << "\n";
}