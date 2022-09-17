#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int x, y,n;
        cin >> x >> y >> n;
        int dot_X[n];
        int dot_Y[n];
        for(int i=0;i<n;++i)
        {
            cin>>dot_X[i];
            cin>>dot_Y[i];
        }
        sort(dot_X, dot_X+n);
        sort(dot_Y, dot_Y+n);
        cout << "(Street: "<<dot_X[(n-1)/2]<<", Avenue: "<<dot_Y[(n-1)/2]<<")\n";
    }
    return 0;
}
