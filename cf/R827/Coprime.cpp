#include<iostream>
#include<map>
using namespace std;
long long gcd(long long a, long long b)
{
    if( b==0 )
        return a;
    return gcd( b, a%b );
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> ii_Map;
        int a[n];
        for(int i=0; i<n; ++i){
            cin >> a[i];
            ii_Map[a[i]] = i + 1;
        }

        int ans=-1;
        for(int i=1;i<1001;++i)
        {
            for(int j=1;j<1001;++j)
            {
                if(gcd(i,j)==1&&ii_Map[i]&&ii_Map[j])
                {
                    ans=max(ans,ii_Map[i]+ii_Map[j]);
                
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}