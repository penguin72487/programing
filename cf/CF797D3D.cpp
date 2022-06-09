#include <iostream>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int sum = 0;
        int n,k;
        cin >> n>>k;
        char c_Tmp;
        int pre_Sum[n+1];
        *pre_Sum = 0;
        for (int i = 1; i <=n; i++)
        {
            cin>>c_Tmp;
            if(c_Tmp=='B')
            {
                ++sum;
            }
            pre_Sum[i] = sum;
        }
        int i_Min = 2147483647;
        bool flag = true;
        for(int i =k; i<=n; i++)
        {
            i_Min = min(i_Min,k-pre_Sum[i]+pre_Sum[i-k]);
            if(i_Min<1)
            {
                cout << "0\n";
                flag = false;
                break;
            }
        }
        if(flag)
        {
            cout<<i_Min<<"\n";
        }
    }
}