
#include<iostream>
using namespace std;
class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro = 1;
        int sum = 0;
        while(n){
            sum += n % 10;
            pro *= n % 10;
            n /= 10;
        }
        return pro-sum;
    }
}s;
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    cout<<s.subtractProductAndSum(234);
}