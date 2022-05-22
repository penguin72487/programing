#include <iostream>
#include <vector>
using namespace std;
const long long MOD = 1000000007;
class matrix
{
    public:
        vector<vector<long long> >val;
        matrix()
        {
            val.resize(2);
            val[0].resize(2);
            val[1].resize(2);
        }
        matrix(initializer_list<int> tmp)
        {
            val.resize(2);
            val[0].resize(2);
            val[1].resize(2);
            auto it =tmp.begin();
            for(int i = 0; i < 2; i++)
            {
                for(int j = 0; j < 2; j++)
                {
                    val[i][j] = *it;
                    ++it;
                }
            }

        }
        ~matrix(){

        }
        vector<long long> & operator[] (int i)
        {
            return val[i];
        }
        matrix operator* (matrix B)
        {
            matrix ans{0,0,0,0};
            for(int i=0; i<2;i++)
            {
                for(int j=0; j< 2;++j)
                {
                    ans[i][j] = ((val[i][0] * B[0][j])%MOD+(val[i][1]*B[1][j])%MOD)%MOD;
                }
            }
            return ans;
        }
        void operator= (matrix tmp)
        {
            for (int i = 0; i < 2;++i)
            {
                for(int j = 0; j < 2;++j)
                {
                    val[i][j] = tmp[i][j];
                }
            }
        }
};
long long fib(long long n)
{
    matrix I = {1, 0, 0, 1};
    matrix Ans = {1, 1, 1, 0};
    matrix B = {1, 1, 1, 0};
    if(n==0) 
    return 0;
    if(n==1)
    return 1;
    while(n)
    {
        if(n&1)
        {
            Ans = Ans * B;
        }
        B = B * B;
        n>>=1;
    }
    return Ans[1][1];
}

int main()
{
    long long n;
    cin >> n;
    cout<<fib(n)<<"\n";

}