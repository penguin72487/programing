#include<iostream>
#include<string>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s,ans;
        cin >> s;
        bool one = 0;
        bool zero = 0;
        int last_Zero=-1;
        auto it = s.begin();
        for (;it != s.end(); ++it)
        {
            if(*it=='0')
            {
                ans.push_back('0');
            }
            else{
                one = 1;
                last_Zero = (it-s.begin());
                break;
            }
        }
        for (;it!=s.end();it++)
        {
            if(*it=='0')
            {
                zero = 1;
                last_Zero = (it-s.begin());
            }
        }
        if(one^1) // ==0
        {
            cout << s << "\n";
        }
        else if(zero^1) //==0
        {
            cout<<s << "\n";
        }
        else
        {
            cout << ans;
            for (int i = last_Zero; i <n;++i)
            {
                cout << s[i];
            }
            cout << "\n";
        }
    }
    return 0;
}