#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long int qury(int n, int *f, int init);
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int f[n];
    for (int i = 0; i < n;++i)
    {
        cin >> f[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < n;++i)
    {
        int k;
        cin >> k;
        int op = 1,ed=k;
        int mid;
        while(op<ed)
        {
            mid = (op + ed) / 2;
            //cout << mid << " ";
            if(qury(n,f,mid)<=k)
            {
                op = mid+1;
            }
            else
            {
                ed = mid-1;
            }
        }
        cout << (op+ed)/2 <<"\n";
    }
}

long long int qury(int n, int *f, int init)
{
    long long ans = init;
    long long  tmp = init;
    for (int i = 0; i < n;++i)
    {
        tmp = tmp * (float)( min(log2(f[i] + 1), 30.0) / 30);
        ans += tmp;
    }

        return ans;
}