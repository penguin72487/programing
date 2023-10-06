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
        int n;
        cin >> n;
        
        n -= 3;
        int mid = n / 3;
        if(n%3==0)
        {
            
            cout << mid+1  << " " << mid+2 <<" "<< mid  << "\n";
        }
        else if(n%3==1)
        {
            
            cout << mid+1  << " " << mid+3 << " " << mid << "\n";
        }
        else 
        {
            cout << mid +2 << " " << mid+3 << " " << mid << "\n";
        }
    }
}