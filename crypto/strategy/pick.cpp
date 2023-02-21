#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w",stdout);

    deque<int> sample;
    int now_Price;
    for (int i = 0; i < 22;++i)
    {
        cin >> now_Price;
        sample.push_back(now_Price);
    }
    deque<tuple<int, int, int>> order; // tickets
    queue<tuple<int, int, int>> Short;
    queue<tuple<int, int, int>> Long;
    int time = 0;
    while(cin>>now_Price&&now_Price)
    {
        ++time;
        order.push_back({*max_element(sample.begin(), sample.end()), *min_element(sample.begin(), sample.end()), time});
        sample.pop_front();
        sample.push_back(now_Price);

        if(time-get<2>(order.front())>60)
        {
            order.pop_front();
        }
        if(time-get<2>(Short.front())>60)
        {
            order.pop_front();
        }
        if(time-get<2>(Long.front())>60)
        {
            order.pop_front();
        }
        
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}