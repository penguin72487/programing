#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a[10] = {10, 9, 1, 2, 5, 6, 7, 3, 4, 8};
    cout << *min_element(a, a + 10) << " " << *max_element(a, a + 10) << " " << accumulate(a, a + 10,0) / 10.0 << "\n";
    return 0;
}
