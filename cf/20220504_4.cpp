#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    int arr_So[n];
    vector<int> priorty_So(n);
    int priorty_Situ[n];
    int t_Sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr_So[i];
        t_Sum += arr_So[i];
        priorty_So[i] = t_Sum;
        priorty_Situ[i] = t_Sum;
    }
    t_Sum=0;
    for(int i=0;i<n;i++)
    {
        int damage;

        cin >> damage;

        int ans_R =upper_bound(priorty_So.begin(),priorty_So.end(),damage+t_Sum)-priorty_So.begin();
        if(ans_R==n)
        {
            cout << n << "\n";
            t_Sum =0;
        }
        else
        {
            cout<<n-ans_R << "\n";
            t_Sum += damage;
        }

    }
}
