#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <unordered_map>
using namespace std;
class node {
    public:
    int min_Odd=2147483647;
    int min_Even=2147483646;
    node()
    {

    }
    node(int t)
    {
        if(t&1)
        {
            min_Odd = t;
        }
        else
        {
            min_Even = t;
        }
    }
    node(int t_A,int t_B)
    {
        min_Odd =min(min_Odd,t_A);
        min_Even =min(min_Even,t_B);
    }
};
class Segment_Tree{
    public:
    vector<node> root;
    int n;
    Segment_Tree(vector<int>& t){
        n = t.size();
        root.resize(n);
        for(auto it=t.begin(); it!=t.end(); ++it)
        {
            root.push_back(node(*it));
        }
        for(int i=n-1; i>0; --i)
        {
            root[i].min_Even = min(root[i << 1].min_Even, root[(i << 1)|1].min_Even);
            root[i].min_Odd = min(root[i << 1].min_Odd, root[(i << 1) | 1].min_Odd);
        }
    }
    node query(int l,int r)
    {
        node ans;
        for (int i_Op = l + n, i_Ed = r + n;i_Op < i_Ed;i_Op>>=1,i_Ed>>=1)
        {
            if(i_Op&1)
            {
                ans.min_Odd=min(ans.min_Odd, root[i_Op].min_Odd);
                ans.min_Even = min(ans.min_Even, root[i_Op].min_Even);
                ++i_Op;
            }
            if(i_Ed&1)
            {
                --i_Ed;
                ans.min_Even = min(ans.min_Even, root[i_Ed].min_Even);
                ans.min_Odd = min(ans.min_Odd, root[i_Ed].min_Odd);
                
            }
        }
        return ans;
    }
};
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        vector<int> sorted_Arr = arr;
        sort(sorted_Arr.begin(), sorted_Arr.end());
        if(sorted_Arr==arr)
        {
            cout<<"YES\n";
            continue;
        }
        unordered_map<int, int> iindex_Map;
        for(int i=0;i<n;i++){
           iindex_Map[sorted_Arr[i]]=i;
        
        }
        Segment_Tree root(arr);
        bool flag = 1;
        for(int i=0;i<n;++i)
        {
            if(arr[i]&1)
            {
                if(arr[i]>root.query(i,iindex_Map[arr[i]]+1).min_Odd)
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                if(arr[i]>root.query(i,iindex_Map[arr[i]]+1).min_Even)
                {
                    flag = 0;
                    break;
                }
            }
        }

        if(flag)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }

    }
    return 0;
}
void swap(int &a,int &b)
{
    a^=b^=a^=b;
}