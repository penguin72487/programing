#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 128;
    vector<int> val;
    val.push_back(1);
    for(int i=0; i<n; i++)
    {
        for(auto it=val.begin(); it!=val.end(); ++it)
        {
            *it *= 2;
        }
        for (int j = 0; j < val.size(); ++j) 
        {
            if (val[j] > 9)
            {
                if (val.size() == j + 1)
                    val.push_back(val[j] / 10);
                else
                    val[j + 1] += val[j] / 10;
                val[j] = val[j] % 10;
            }
        }
        vector<int> out(val);
        reverse(out.begin(), out.end());
        for(auto it=out.begin(); it!=out.end();++it)
        {
            cout << *it;
        }
        cout << "\n";
    }
}