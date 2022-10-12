#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    double score;
    for (int i = 0; i < 3;++i)
    {
        cin >> s>>score;
        cout<<s<<" "<< fixed << setprecision(1)<<score<<"\n";
    }
        return 0;
}