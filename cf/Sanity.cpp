#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n, s, k;
    cin >> n >> s >> k;
    long long day[n];
    long long tmp = 0;
    for(int i=0; i<n; ++i)
    {
        cin>>day[i];
        if(day[i]==0)
        {
            ++tmp;
        }
        else
        {
            s+=tmp/k;
            s-=day[i];
        }
    }
    
    cout << s+tmp/k << "\n";

    return 0;
}