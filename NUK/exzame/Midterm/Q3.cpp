#include<bits/stdc++.h>
using namespace std;
void intohex(long long n)
{
    if(n<=0)
    {
        return;
    }
    intohex(n / 16);
    int t = n % 16;
    if(t<10)
    {
        cout << t;
    }
    else {
        t -= 10;
        cout << (char)('A' + t);
    }

}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    srand(time(0));
    long long n = rand()%9901+100;
    //long long n = 900%9901+100;
    cout<<n<<" ";
    intohex(n);
    cout << "\n";
    //printf("%x", n);

    return 0;
}