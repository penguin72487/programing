#include <iostream>
using namespace std;
int range_Query(int l,int r,int *&ans)
{
    return ans[r] - ans[l - 1];
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int dor_T[n+1];
        *dor_T = 0;
        int *dor = &dor_T[1];
        int adj_Dor[n];
        int ans_T[n+1];
        *ans_T= 0;
        int*ans = &ans_T[1];
        int l=0, r=0;
        bool flag = 1;
        for(int i=0,sum=0; i<n; ++i){
            cin >> dor[i];
            adj_Dor[i] =dor[i]-dor[i-1];
            sum+=dor[i];
            ans[i] = sum;
            if(adj_Dor[i]<0)
            {

                r = i - 1;
                if(range_Query(l,r,ans)<range_Query(0,l,ans))
                {
                    flag = 0;
                    break;

                }

                l = i;
            }
        }
        r = n - 1;
        if(range_Query(l,r,ans)<range_Query(0,l,ans))
        {
            flag = 0;

        }
        if(flag){
            for(int i=0; i<n;++i)
            {
                cout<<ans[i]<< " ";
            }
            cout<<"\n";
        }
        else 
        {
            cout << "-1\n";
        }


    }
    return 0;
}