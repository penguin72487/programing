#include <iostream>
using namespace std;
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m;
        int r, c;
        cin>>n>>m>>r>>c;
        --r;
        --c;
        int matrix[n][m];
        bool flag=0;
        bool flag_R=0;
        bool flag_C=0;
        for(int i=0;i<n;i++)
        {
            string s;
            cin >> s;
            for(auto it=s.begin();it!=s.end();++it)
            {
                if(*it=='B')
                {
                    matrix[i][it-s.begin()] =1;
                    flag = 1;
                    if(i==r)
                    {
                        flag_R = 1;
                    }
                    if(it-s.begin()==c)
                    {
                        flag_C = 1;
                    }
                }
                else
                {
                    matrix[i][it - s.begin()] = 0;
                }

            }

        }
        if(!flag)
        {
            cout << "-1\n";
        }
        else if(matrix[r][c])
        {
            cout << "0\n";
        }
        else if(flag_R||flag_C)
        {
            cout << "1\n";
        }
        else
        {
            cout << "2\n";
        }
    }

return 0;
}