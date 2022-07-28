#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int node_Apple[n];
    for(int i = 0; i < n; i++)
    {
        cin>>node_Apple[i];
    }
    unordered_map<int ,unordered_map<int,int>> node_Link(n);
    int q = n - 1;
    int u, v, l;
    for(int i = 0; i<q;++i)
    {
        cin >> u >> v >> l;
        node_Link[u][v] = l;

    }
    //long long ans = 0;
}