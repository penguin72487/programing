#include <iostream>
#include<algorithm>
#include<list>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int i_list[n];
    list<int> andone;
	list<int> andzero;
    for (int i = 0; i < n;++i)
    {
        cin >> i_list[i];
        if(i&1)
        {
            
            andone.push_back(i_list[i]);
        }
        else
        {
            andzero.push_back(i_list[i]);
        }
    }
    andone.sort();
    andzero.sort();
    //sort(andone.begin(),andone.end());
    //sort(andzero.begin(),andzero.end());
    int m = n >> 1;
    long long ans = 0;
    for (int i = 0; i < m;++i)
    {
        if(*andone.begin()<*andzero.begin())
        {
            ans += *andone.begin();
            andone.pop_front();
            andzero.pop_back();
        }
        else
        {
            ans += *andzero.begin();
            andzero.pop_front();
            andone.pop_back();
        }
    }
    cout << ans << "\n";

    return 0;
}