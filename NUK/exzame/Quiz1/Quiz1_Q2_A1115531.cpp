#include<iostream>
using namespace std;
int main(){
    
    int n;
    int i = 0;
    int i_Max = 0;
    int i_Min = 2147483647;
    long long sum = 0;
    cout << "please input a positive integer (0 end) :";
    while (cin >> n)
    {
        if(n == 0)
        {
            break;
        }
        ++i;
        i_Max = max(i_Max, n);
        i_Min=min(i_Min, n);
        sum += n;
        cout << "\nplease input a positive integer (0 end) :";
    }
    //cout.tie(0)->sync_with_stdio(0);
    cout << "max = " << i_Max<<"\n";
    cout << "min = " << i_Min << "\n";
    cout << "AVG = " << ((long double)sum / (long double)i);

    return 0;
}