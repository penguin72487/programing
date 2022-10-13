#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        long long ans = 0;
        int a[n];
        int i = 0;
        int k, o;
        cin >> k;
        int *p = a;
        for (; p < a + n;++p){
            if(k>=*p)
            {
                ans+=*p;
            }
            else {
                break;
            }
        }
        for (i=1; i < n;i+=2)
        {
            cin >> k >> o;
        }
    }
    return 0;
}