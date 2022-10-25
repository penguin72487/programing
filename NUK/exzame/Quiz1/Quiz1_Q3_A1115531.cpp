#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    vector<int> a(3,0);
    for (int i = 1; i <= 5;++i)
    {
        a[0]=i;
        for(int j = i+1; j <= 5;++j)
        {
            a[1]=j;
            for(int k = j+1; k <= 5;++k)
            {
                a[2]=k;
                do {
                    cout << a[0] << a[1] << a[2] << " ";
                } while (next_permutation(a.begin(), a.end()));
            }
            cout << "\n";
        }
        
    }
        return 0;
}