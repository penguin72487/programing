#include <iostream>
#include<set>
using namespace std;
int main()
{
    //cin.tie(0)->sync_with_stdio(0);
    //cout.tie(0);
    int n,k;
    cin >> n>>k;
    set<int> set;
    for (int i = 1; i <= n; ++i) set.insert(i);

    //int k = 2;
    ++k;
    int multiply = k;
    int multiply_Cash=0;
    int last = 0;
    while (!set.empty())
    {
        last = *set.rbegin();
         while (k <= n)
        {
            cout << k << " ";
            set.erase(k);
            k += multiply;
            ++multiply_Cash;
        }
        multiply *= 2;
        multiply += multiply_Cash;
        multiply_Cash = 0;
        //--multiply;

        k %= n;
    }
}


 