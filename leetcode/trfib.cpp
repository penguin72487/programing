#include<iostream>
using namespace std;
class Solution {
public:
        int tribonacci(int n) {
        long long f[3]={0,1,1};
        if(n<3)
        {
            return f[n];
        }
        n -= 2;
        for(int i=0;i<n;++i)
        {
            swap(f[0],f[2]);
            swap(f[0],f[1]);
            f[2]+=f[0]+f[1];
            
        }

        return f[2];
        
    }
    void swap(long long &a,long long &b)
    {
        a^=b^=a^=b;
    }
}s;
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    cout<<s.tribonacci(4);
}