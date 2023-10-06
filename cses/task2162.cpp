#include <iostream>
#include<set>
using namespace std;
 int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> set;

    for (int i = 1; i <= n; ++i) set.insert(i);

    int k = 2;
    int multiply = 2;
    int last = 0;
    while (!set.empty())
    {
        last = *set.rbegin();
        while (k <= n)
        {
            cout << k << " ";
            set.erase(k);
            k += multiply;
        }
        multiply *= 2;

        if (!set.empty()) 
        {
            k = *set.rbegin() != last && set.size() > 1 ? *++set.begin() : *set.begin();
        }
    }
}


 