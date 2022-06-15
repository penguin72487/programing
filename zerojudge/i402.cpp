#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
long long make_Dot(vector<int> &a, vector<int> &b);
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n>>m;
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    long long ans = -9223372036854775807;
    ans= max(ans,make_Dot(a,b));
    ans= max(ans,make_Dot(b,a));
    vector<int> rea;
    vector<int> reb;
    rea.assign(a.rbegin(),a.rend());
    reb.assign(b.rbegin(),b.rend());
    ans = max(ans, make_Dot(rea, b));
    ans = max(ans, make_Dot(b, rea));
    ans = max(ans, make_Dot(reb, a));
    ans = max(ans, make_Dot(a, reb));
    ans = max(ans, make_Dot(reb, rea));
    ans = max(ans, make_Dot(rea, reb));

    cout << ans << "\n";
}
long long make_Dot(vector<int> &a,vector<int> &b)
{
    int n=a.size();
    int m=b.size();
    long long matrix[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrix[i][j] = a[i]*b[j];
        }
    }

    vector<vector<long long>> vec_dot(m+n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vec_dot[i + j].push_back(matrix[i][j]);
        }
    }
    long long ans = -9223372036854775807;
    for(auto it=vec_dot.begin(); it!=vec_dot.end();++it)
    {
        long long  t_Ans = -9223372036854775807;
        long long  sum=*(it->begin());
        auto jt = it->begin();
        t_Ans=max(t_Ans,sum);
        for (++jt;jt!=it->end();++jt)
        {
            sum = max(sum, sum + *jt);
            t_Ans=max(t_Ans,sum);
        }
        ans = max(t_Ans, ans);
    }

    return ans;
}