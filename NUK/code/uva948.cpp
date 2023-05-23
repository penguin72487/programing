#include<bits/stdc++.h>
using namespace std;
vector<int> vec={1,1};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    for (int i = 2; i < 40;++i)
    {
        vec.push_back(vec[i-1]+vec[i-2]);
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << n << " = ";

        for (int i = 39; i >= 0;--i)
        {
            if(n>=vec[i])
            {

                n -= vec[i];
                cout << "1";
                for (int j = i-1; j >= 1;--j)
                {
                    if(n>=vec[j])
                    {
                        n -= vec[j];
                        cout << "1";
                    }
                    else {
                        cout << "0";
                    }
                }
                break;
            }
        }
        cout << " (fib)\n";
    }

    return 0;
}