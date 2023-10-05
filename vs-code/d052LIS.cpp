#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i_LIS(int* p,int n);
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        //if(t==1)
        int n;
        cin >> n;
        int q[n];
        for (int i = 0; i < n;++i)
        {
            cin >> q[i];
        }
        cout << i_LIS(q,n) << "\n";
    }
}
int i_LIS(int* p,int n)
{
    
    vector<int> v;
    v.push_back(*p);
    for (int i = 1; i < n;++i)
    {
        if(p[i]>v.back())
        {
            v.push_back(p[i]);
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), p[i]);
            *it = p[i];
        }
    }
    return v.size();
}