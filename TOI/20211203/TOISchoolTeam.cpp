#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class node{
public:
    node (int x,int y)
    {
        boy = x;
        girl = y;
        differ = x - y;
    }
    node ()
    {

    }
    int boy;
    int girl;
    int differ;
    bool operator ()(node val,node val2)
    {
        return val.differ < val2.differ;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    int N = n + m;
    int a, b;
    node list[N];
    for (int i = 0; i < N;++i)
    {
        cin >> a >> b;
        list[i].boy = a;
        list[i].girl = b;
    }
    for (int i = 0; i < N;++i)
    {
        list[i].differ = list[i].boy - list[i].girl;
    }
    sort(list,list+N,node());
    int ans = 0;
    
    for (int i = 0; i < n;++i)
    {
        ans += list[i].boy;
    }
    for (int i = 0; i < m;++i)
    {
        ans += list[N - 1 - i].girl;
    }
    cout << ans << "\n";
}