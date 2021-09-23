#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class step{
public:
    int i_X;
    int i_Y;
    step ()
    {

    }
    step(int t_X,int t_Y)
    {
        i_X = t_X;
        i_Y = t_Y;
    }
    bool operator()(step val,step val2)
    {
        if(val.i_X==val2.i_X)
        {
            return (val.i_Y<val2.i_Y);
        }
        else
        {
            return (val.i_X < val2.i_X);
        }
    }
    
};
int Lis_step(step* dr_Fly,int n)
{
    int ans = 1;
    vector<int> v;
    v.push_back(dr_Fly[0].i_Y);
    //int dp[n + 1];
    //dp[0] = 1;

    for (int i = 1; i < n;++i)
    {
        if(dr_Fly[i].i_Y>=v.back())
        {
            v.push_back(dr_Fly[i].i_Y);
            ++ans;
            //dp[i] = ans;
        }
        
        else
        {
            auto it = upper_bound(v.begin(), v.end(), dr_Fly[i].i_Y);
            *it = dr_Fly[i].i_Y;
            //dp[i] = it - v.begin()+1;
        }
        
    }
        return ans;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    step dg_Fly[n];
    for (int i = 0; i < n;++i)
    {
        cin >> dg_Fly[i].i_X >> dg_Fly[i].i_Y;
    }
    sort(dg_Fly, dg_Fly + n, step());
    cout << Lis_step(dg_Fly,n)<<"\n";
}