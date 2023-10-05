#include <iostream>
#include <queue>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        priority_queue<int> list;
        int a[n];
        int b[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        for(int i=0; i<n; i++)
        {
            list.push(a[i]);
            cout<<b[i]-list.top()<<" ";
            list.pop();
            list.push(b[i]);
            

        }
        cout << "\n";
    }

}