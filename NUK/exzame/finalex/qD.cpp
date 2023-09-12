#include <bits/stdc++.h>

using namespace std;

struct compareB {
    bool operator()(pair<int,int> i, pair<int,int> j) {
        return i.first < j.first;
    }
};

struct compareS {
    bool operator()(pair<int,int> i, pair<int,int> j) {
        return i.first > j.first;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,s;
    cin>>n>>s;

    priority_queue<pair<int,int>, vector<pair<int,int>>, compareB> order_B;
    order_B.push({1000000000,1000000000});
    priority_queue<pair<int,int>, vector<pair<int,int>>, compareS> order_S;
    for(int i=0;i<n;++i)
    {
        char o;
        int a,b;
        cin>>o>>a>>b;
        if(o=='B')
        {
            order_B.push({a,b});
        }
        else
        {
            order_S.push({a,b});
        }
        //pair
    }
    while(!order_B.empty() && !order_S.empty() && order_B.top().first >= order_S.top().first)
    {
        int amount = min(order_B.top().second,order_S.top().second);
        auto it=order_B.top();
        order_B.pop();
        auto jt=order_S.top();
        order_S.pop();
        //cout<<price<<" "<<amount<<"\n";
        it.second-=amount;
        jt.second-=amount;
        if(it.second>0)
        {
            order_B.push(it);
        }
        if(jt.second>0)
        {
            order_S.push(jt);
        }

    }
    if(order_B.size()<s || order_S.size()<s)
    {
        vector<tuple<char,int,int>> ans;
        if(order_S.size()<s)
        {
            while(!order_S.empty())
            {
                if(!ans.empty()&&get<0>(ans.back())=='S'&&get<1>(ans.back())==order_S.top().first)
                {
                    get<2>(ans.back())+=order_S.top().second;
                }
                else
                {
                    ans.push_back(make_tuple('S',order_S.top().first,order_S.top().second));
                }
                order_S.pop();
            }
            reverse(ans.begin(),ans.end());
            while(!order_B.empty()&&ans.size()<s*2)
            {
                if(!ans.empty()&&get<0>(ans.back())=='B'&&get<1>(ans.back())==order_B.top().first)
                {
                    get<2>(ans.back())+=order_B.top().second;
                }
                else
                {
                    ans.push_back(make_tuple('B',order_B.top().first,order_B.top().second));
                }
                order_B.pop();
            }
        }
        else{
            int n=s-order_B.size();
            for(int i=0;i<n&&!order_S.empty();++i)
            {
                if(!ans.empty()&&get<0>(ans.back())=='S'&&get<1>(ans.back())==order_S.top().first)
                {
                    get<2>(ans.back())+=order_S.top().second;
                    --i;
                }
                else
                {
                    ans.push_back(make_tuple('S',order_S.top().first,order_S.top().second));
                }
                order_S.pop();
            }
            reverse(ans.begin(),ans.end());
            while(!order_B.empty())
            {
                if(!ans.empty()&&get<0>(ans.back())=='B'&&get<1>(ans.back())==order_B.top().first)
                {
                    get<2>(ans.back())+=order_B.top().second;
                }
                else
                {
                    ans.push_back(make_tuple('B',order_B.top().first,order_B.top().second));
                }
                order_B.pop();
            }
        }
    }
    else
    {
        vector<tuple<char,int,int>> ans;
        for(int i=0;i<s;++i)
        {
            if(!ans.empty()&&get<0>(ans.back())=='S'&&get<1>(ans.back())==order_S.top().first)
            {
                get<2>(ans.back())+=order_S.top().second;
                --i;
            }
            else
            {
                ans.push_back(make_tuple('S',order_S.top().first,order_S.top().second));
            }
            order_S.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<s;++i)
        {
            if(!ans.empty()&&get<0>(ans.back())=='B'&&get<1>(ans.back())==order_B.top().first)
            {
                get<2>(ans.back())+=order_B.top().second;
                --i;
            }
            else
            {
                ans.push_back(make_tuple('B',order_B.top().first,order_B.top().second));
            }
            order_B.pop();
        }
        for(auto [a,b,c]:ans)
        {
            cout<<a<<" "<<b<<" "<<c<<"\n";
        }
    }


}
