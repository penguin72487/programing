#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> x(m,0);
        vector<int> y(n,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int tmp;
                cin >> tmp;
                x[j] = max(x[j], tmp);
                y[i] = max(y[i], tmp);
            }
        }
        int count_X = 0;
        for (int i = 0; i < m;i++)
        {
            count_X += x[i];
        }
        int count_Y = 0;
        for (int i = 0; i < n; i++)
        {
            count_Y += y[i];
        }
        int ans = min(m - count_X, n - count_Y);
        if(ans&1)
        {
            cout << "Ashish\n";
        }
        else{
            cout <<"Vivek\n";
        }
    }
    return 0;
}