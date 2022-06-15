#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n>>m;
    int a[n];
    int b[n];
    int matrix[n][m];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrix[i][j] = a[i]*b[j];
        }
    }

    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    vector<vector<int>> vec_dot(m+n-1);
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
    vec_dot.clear();
    vec_dot.resize(m+n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vec_dot[i-j+m-1].push_back(matrix[i][j]);
        }
    }
    for(auto it=vec_dot.begin(); it!=vec_dot.end();++it)
    {
        long long  t_Ans = -9223372036854775807;
        long long  sum=*(it->begin());
        auto jt = it->begin();
        t_Ans=max(t_Ans,sum);
        for (++jt;jt!=it->end();++jt)
        {
            sum =max(sum,sum+*jt);
            t_Ans=max(t_Ans,sum);
        }
        ans = max(t_Ans, ans);
    }







    reverse(b,b+m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            matrix[i][j] = a[i]*b[j];
        }
    }

    vec_dot.clear();
    vec_dot.resize(m+n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vec_dot[i + j].push_back(matrix[i][j]);
        }
    }
    
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
    
    vec_dot.clear();
    vec_dot.resize(m+n-1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vec_dot[i-j+m-1].push_back(matrix[i][j]);
        }
    }
    for(auto it=vec_dot.begin(); it!=vec_dot.end();++it)
    {
        long long  t_Ans = -9223372036854775807;
        long long  sum=*(it->begin());
        auto jt = it->begin();
        t_Ans=max(t_Ans,sum);
        for (++jt;jt!=it->end();++jt)
        {
            sum =max(sum,sum+*jt);
            t_Ans=max(t_Ans,sum);
        }
        ans = max(t_Ans, ans);
    }


    cout << ans << "\n";
}