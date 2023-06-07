#include <bits/stdc++.h>

using namespace std;

struct compareB {
    bool operator()(pair<int,int> i, pair<int,int> j) {
        return i.first > j.first;
    }
};

struct compareS {
    bool operator()(pair<int,int> i, pair<int,int> j) {
        return i.first < j.first;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,s;
    cin>>n>>s;

    priority_queue<pair<int,int>, vector<pair<int,int>>, compareB> order_B;
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
        while(!order_B.empty() && !order_S.empty() && order_B.top().first >= order_S.top().first)
        {
            int price = order_S.top().first;
            int amount = min(order_B.top().second,order_S.top().second);
            auto it=order_B.top();
            order_B.pop();
            auto jt=order_S.top();
            order_S.pop();
            cout<<price<<" "<<amount<<"\n";
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
    }
}
