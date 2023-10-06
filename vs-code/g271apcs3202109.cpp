#include<iostream>
#include<vector>
#include<limits>
using namespace std;
vector<long long>::iterator min_It(vector<long long> &val)
{
    long long i_Min = numeric_limits<long long>::max();
    for (auto it = val.begin(); it != val.end();++it)
    {
        i_Min = min(i_Min, *it);
    }
    auto it = val.begin();
    while(*it!=i_Min)
    {
        ++it;
    }
    return it;
}
long long i_Sum(vector<long long> &val)
{
    long long ans = 0;
    for (auto it = val.begin(); it != val.end();++it)
    {
        ans += *it;
    }
        return ans;
}
long long i_Liky(vector<long long> &val)
{
    if(val.size()==1)
    {
        return val[0];
    }
    vector<long long> l_Vec;
    vector<long long> r_Vec;
    auto it_Min = min_It(val);
    l_Vec.assign(val.begin(), it_Min);
    r_Vec.assign(++it_Min, val.end());
    if(i_Sum(r_Vec)>=i_Sum(l_Vec))
    {
        return i_Liky(r_Vec);
    }
    else
    {
        return i_Liky(l_Vec);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<long long> list(n);
    for (auto it = list.begin(); it != list.end();++it)
    {
        cin >> *it;
    }
    cout << i_Liky(list) << "\n";

}