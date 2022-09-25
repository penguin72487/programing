#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        long long list[n];
        long long adj_List[n];
        for(int i = 0,tmp=0; i < n; ++i)
        {
            cin>>list[i];
            adj_List[i] =list[i]-tmp;
            tmp = list[i];
        }
        bool flag = 0;
        int pos = 0;
        int neg = 0;
        for(int i = 1; i < n; ++i)
        {
            if(adj_List[i]>0)
            {
                pos = i;
                break;
            }
        }
        for(int i = pos+1; i < n; ++i)
        {
            if(adj_List[i]<0)
            {
                neg = i;
                flag = 1;
                break;
            }
        }
    
        if(flag)
        {

            cout<<"YES\n" << pos << " " <<pos + 1 << " "<<neg + 1 << "\n";
        }
        else
        {
            cout << "NO\n";
        }


    }
    return 0;
}