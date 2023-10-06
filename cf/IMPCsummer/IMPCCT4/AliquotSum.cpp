#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        long long t;
        cin >> t;
        long long sum = 1;
        for(int j=2; (j*j)<=t; ++j)
        {
            if(t%j ==0)
            {
                sum += j;
                sum += t / j;
            }
        }
        if(sum ==t)
        {
            cout << "perfect\n";
        }
        else if(sum <t)
        {
            cout << "deficient\n";
        }
        else 
        {
            cout << "abundant\n";
        }
    }
}