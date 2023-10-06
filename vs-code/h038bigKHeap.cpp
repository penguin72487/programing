#include<iostream>
#include<queue>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    priority_queue<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n;++i)
    {
        int tmp;
        cin >> tmp;
        a.push(tmp);
    }
    cin >> n;
    for (int i = 1; i < n;++i)
    {
        a.pop();
    }
    cout << a.top() << "\n";
}