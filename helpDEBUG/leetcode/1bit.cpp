#include<iostream>
#include <bitset>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32> a(n);
        return a.count();
    }
}s;
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    cout<<s.hammingWeight(00000000000000000000000000001011);
}