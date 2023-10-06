#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    string s;
    while(t--){
        int res = 0;
        
        cin >> s;
        for (int init = 0; init < 1000001;++init)
        {
            int cur = init;
            
            bool ok = 1;
            
            for(auto it=s.begin(); it!=s.end();++it)
            {
                ++res;
                if(*it=='+')
                {
                    ++cur;
                }
                else
                {
                    --cur;
                }
                if(cur<0)
                {
                    ok = 0;
                    break;
                }
            }
            if(ok)
            {
                break;
            }
        }
        cout << res << "\n";
    }
    return 0;
}