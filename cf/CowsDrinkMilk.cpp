#include <iostream>
#include<algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int milk[n];
    for(int i = 0; i < n; i++)
    {
        cin>>milk[i];
    }
    int min_M=*(min_element(milk,milk+n));
    *min_element(milk,milk+n) = *max_element(milk,milk+n);
    cout << min((min_M + *max_element(milk, milk + n))/2, *min_element(milk, milk + n))<<"\n";
    return 0;
}