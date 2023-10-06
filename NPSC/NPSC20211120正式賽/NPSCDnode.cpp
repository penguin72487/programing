#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
class node{
public:
    int data;
    int index;
    node(int a,int b)
    {
        data = a;
        index = b;
    }
    bool operator()(node &val,node &val2)
    {
        if(val.data==val2.data)
        {
            return val.index < val2.index;
        }
        else
        {
            return val.index < val2.index;
        }
    }
};
bool cmp(node &val,node &val2)
{
    if(val.data==val2.data)
    {
        return val.index < val2.index;
    }
    else
    {
        return val.index < val2.index;
    }

}
int main()
{
    int ca;
    cin>>ca;
    while(ca--)
    {
        long long int n,k;
        cin>>n>>k;
        vector<int> sa(n);
        vector<int> ch(k);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> n_Tmp;
        int i_tmp;
        for(int i=0;i<n;++i)
        {
            cin >> sa[i];
            n_Tmp.push(make_pair(i_tmp, i));
        }
        for(int i=0;i<k;++i)
        {
            cin >> ch[i];
        }
        sort(ch.begin(),ch.end());
        for(int i=0;i<k;++i)
        {
            int min = n_Tmp.top().first;
            int pos =  n_Tmp.top().second;
            n_Tmp.pop();
            if(ch[i] > min)
            {
                sa[pos] = ch[i];
            }
        }
        int st = 0 , ed = sa.size();
        int ans = INT_MIN;
        while(st<sa.size())
        {
            int sum = 0;
            for(int i=st;i<ed;++i)
            {
                sum+=sa[i];
            }
            ans = max(ans,sum);
            ed--;
            if(st == ed)
            {
                st++;
                ed = sa.size();
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
