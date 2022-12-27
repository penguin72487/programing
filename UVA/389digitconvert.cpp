#include<bits/stdc++.h>
using namespace std;
long long digit_Conver_To_Ten(string &s,int &a)
{
    long long ans = 0;
    int base = 1;
    for(auto it=s.rbegin();it!=s.rend();++it){
        if(*it>=65)
        {
            ans += base * (*it - 'A' + 10);
        }
        else {
            ans += base * (*it - '0');
        }

        base *= a;
    }
    return ans;

}
string tobdigit(long long n,int b){//ten to b digit
    string ans;
    while(n){
        int t = n % b;
        if(t<10)
        {
            ans.push_back(t + '0');
        }
        else {
            ans.push_back(t - 10 + 'A');
        }

        n /= b;
    }
    //cout << ans << endl;
    for (int i = ans.size(); i < 7;++i)
    {
        ans.push_back('0');
    }
    for (int i = ans.size(); i > 7;--i)
    {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    int a, b;
    while(cin>>s>>a>>b)
    {
        cout << tobdigit(digit_Conver_To_Ten(s, a), b) << "\n";
    }
    return 0;
}