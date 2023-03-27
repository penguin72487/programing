#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int s, d;
        cin >> s >> d;
        int a = (s + d) / 2;
        int b = s - a;
         if(a<0||b<0)
            cout << "impossible" << "\n";
        else if((s+d)&1)
        {
            cout<<"impossible"<<"\n";
        }
        else
            cout << max(a, b) << " " << min(a, b) << "\n";
    }
    return 0;
}