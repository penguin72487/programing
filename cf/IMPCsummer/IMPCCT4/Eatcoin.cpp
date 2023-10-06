#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ull unsigned long long

class bignumber{
    public:
    vector<ull> val;
    bignumber()
    {

    }
    bignumber(string s)
    {
        while(s.length()>9)
        {
            val.push_back(stoull(s.substr(s.length()-9,9)));
            s.erase(s.length()-9);
        }
        if(s.length())
        {
            val.push_back(stoull(s));
        }

    }
    void operator=(bignumber t_Val)
    {
        val=t_Val;
    } 
};
bignumber q_Pow(int n)
{
    bignumber ans("1");
    
    return ans;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int p, q;
    cin >> p >> q;


}