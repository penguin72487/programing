#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    char c_Cash;
    int k=0;
    while(t--)
    {
        ++k;
        int s_D, s_M, s_Y; //now
        int t_D, t_M, t_Y;//birth
        cin >> s_D >> c_Cash >> s_M >> c_Cash >> s_Y;
        cin >> t_D >> c_Cash >> t_M >> c_Cash >> t_Y;
        long long abs_Time=s_D+(s_M<<5)+(s_Y<<9);
        long long abt_Time=t_D+(t_M<<5)+(t_Y<<9);
        cout << "Case #" << k<<": ";
        if(abs_Time<abt_Time)
        {
            cout << "Invalid birth date\n";
        }
        else if(abs_Time>=abt_Time+(131ll<<9))
        {
            cout << "Check birth date\n";
        }
        else{
            int time = abs_Time - abt_Time;
            cout << (time >> 9) << "\n";
        }
    }  
    return 0;
}