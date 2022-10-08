#include<iostream>
#include<vector>
#include<set>
#include<deque>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, t;
        string s;
        cin >> n >> t >> s;
        vector<deque<int>> letter(25);
        for (auto it = s.begin(); it != s.end();++it){
            letter[(*it - 'a')].push_back(it - s.begin());
        }
        int m = n / t;
        for (int j = 0;j<t;++j)
        {
            //int last = 0;
            int count_Letter = 0;
            auto jt =letter.rbegin();
            for (int i = 0; i < 26;++i)
            {
                if(count_Letter==m)
                {
                    cout << char('a' + i);
                    break;
                }
                if(letter[i].empty()){
                    while(count_Letter!=m)
                    {
                        while((!jt->empty())&&count_Letter!=m)
                        {
                            //cout <<"in"<< *jt->rbegin();
                            jt->pop_back();
                            ++count_Letter;
                        }
                        if(jt->empty())
                        {
                           ++jt;
                        }

                    }
                    cout << char('a' + i);
                    break;
                }
                else{

                    letter[i].pop_front();
                    ++count_Letter;
                
                }

            }
            
        }
        cout << "\n";
    }
    return 0;
}