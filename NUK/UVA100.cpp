#include<iostream>
using namespace std;
int shat(int n)
{
    int ans = 0;
    while(n>1)
    {
        //cout << n << " ";
        ++ans;
        if(n&1)
        {
            n = n * 3 + 1;
        }
        else
        {
            n /= 2;
        }
    }
    return ans;
}
void swap(int &a,int &b)
{
    a^=b^=a^=b;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a, b;
    while(cin>>a>>b)
    {
        int ans = -1;
        bool flag = false;
        if(a>b)
        {
            flag = 1;
            swap(a,b);
        }
        for (int i = a, tmp = b + 1; i < tmp;++i)
        {
            ans = max(ans, shat(i));
        }
        if(flag)
        {
            swap(a, b);
        }
        cout << a << " " << b << " " << ans+1<<"\n";
    }
    return 0;
}