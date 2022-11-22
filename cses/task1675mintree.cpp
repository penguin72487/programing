#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
auto c = [](auto const&a,auto const& b)
{
    int ga[3];
    int gb[3];
    tie(ga[0], ga[1], ga[2]) = a;
    tie(gb[0], gb[1], gb[2]) = b;
    if (ga[2] == gb[2])
    {
        return (ga[0] + ga[1] < gb[0] + gb[1]);
    }
    else
    {
        return (ga[0] < gb[0]);
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    //priority_queue<tuple<int, int, long long>, vector<tuple<int, int, long long>>, greater<tuple<int, int, long long>>> pq;
    priority_queue<tuple<int, int, long long>, vector<tuple<int, int, long long>>, c> pq;
    return 0;
}