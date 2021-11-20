#include <bits/stdc++.h>
using namespace std;
int vi_Kadane(vector<int> &v_Arr)
{
    int pre_Sum = 0;
    int ans = -2147483648;
    for(auto it=v_Arr.begin();it!=v_Arr.end();++it)
    {
        pre_Sum = max(*it, *it + pre_Sum);
        if(pre_Sum>ans)
        {
            ans = pre_Sum;
        }
    }
    return ans;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int ca;
    cin>>ca;
    while(ca--)
    {
        long long int n,k;
        cin>>n>>k;
        vector<int> sa(n);
        vector<int> ch(k);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> n_Tmp;
        //int i_tmp;
        for(int i=0;i<n;++i)
        {
            cin >> sa[i];
            n_Tmp.push(make_pair(sa[i], i));
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
            
            if(ch[i] > min)
            {
                n_Tmp.pop();
                sa[pos] = ch[i];
                n_Tmp.push(make_pair(ch[i], pos));
            }
        }      

        cout<<vi_Kadane(sa)<<"\n";
    }
    return 0;
}