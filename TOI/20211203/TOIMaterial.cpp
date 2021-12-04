#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class node{
public:
    unordered_map<int,bool> differ;
    
    //int i_Max = -2147483648;
    //node *pa_Node;
    //node *l_Node;
    //node *r_Node;
};
class Segment_Tree{
public:
    node *t_Node;
    int size;
    Segment_Tree(vector<int> &a)
    {
        
        size = a.size();
        int n = size;
        t_Node = new node[size<<1];

        for (int i = 0; i < n;++i)
        {
            t_Node[n + i].differ[a[i]]=1;
        }
        for (int i = 2 * n - 1; i > 0;--i)
        {
            for (auto it = t_Node[i].differ.begin(); it != t_Node[i].differ.end();++it)
            {
                t_Node[i >>1].differ[it->first] = 1;
            }
                
        }
        /*
        for (auto it = t_Node + size; it != t_Node + size * 2;++it)
        {
            cout << it->i_Sum << " ";

        }
        
        cout << "\n";
        */
        
    }
    ~Segment_Tree()
    {
        delete [] t_Node;
    }
    //node *build(node *op, node *ed);
    long long differ_Sum(int &op,int &ed)
    {
        
        /*
        cout << "list";
        for (auto it = op ; it !=ed ;++it)
        {
            cout << it->i_Sum << " ";
        }
        cout << "\n";
        */
        unordered_map<int,bool> t_Sum;
        int i_op = op+size-1;
        int i_ed = ed+size;
        while(i_op<i_ed)
        {
            //cout << "index " << i_op << " " << i_ed << "\n";
            if(i_op&1)
            {
                for (auto it=t_Node[i_op].differ.begin();it!=t_Node[i_op].differ.end();++it)
                {
                    t_Sum[it->first]=1;
                }
                ++i_op;
            }
            if(i_ed&1)
            {
                --i_ed;
                for (auto it=t_Node[i_ed].differ.begin();it!=t_Node[i_ed].differ.end();++it)
                {
                    t_Sum[it->first]=1;
                }
            }
            i_op >>= 1;
            i_ed >>= 1;
            if(i_op==i_ed)
            {
                if(t_Sum.empty())
                {
                    return t_Node[i_op].differ.size();
                }
                else
                {
                    int ans = 0;
                    if(t_Node[i_op].differ.size()>t_Sum.size())
                    {
                        for (auto it = t_Sum.begin(); it != t_Sum.end();++it)
                        {
                            if(t_Node[i_op].differ.find(it->first)==t_Node[i_op].differ.end())
                            {
                                ++ans;
                            }
                        }
                        return t_Node[i_op].differ.size() + ans;
                    }
                    else
                    {
                        for (auto it = t_Node[i_op].differ.begin(); it != t_Node[i_op].differ.end();++it)
                        {
                            if(t_Sum.find(it->first)==t_Sum.end())
                            {
                                ++ans;
                            }
                        }
                        return t_Sum.size() + ans;
                    }
                    
                }
                
            }

        }
        //cout << "Sum" << t_Sum << "\n";
        return t_Sum.size();
    }
    
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;++i)
    {
        cin >> a[i];
    }
    Segment_Tree Material(a);
    int m;
    cin >> m;
    int v, u;
    for (int i = 0; i < m;++i)
    {
        cin >> v >> u;
        cout<<Material.differ_Sum(v,u)<<"\n";
    }
}