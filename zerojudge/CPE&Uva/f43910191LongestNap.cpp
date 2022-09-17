#include<bits/stdc++.h>
using namespace std;
int s_To_Minute(string s)
{
    return ((s[0]-'0')*10+(s[1]-'0')) * 60 + ((s[2]-'0')*10+(s[3]-'0'));
}
string minute_To_S(int minute)
{
    return to_string(minute/60)+ " hours and " + to_string(minute%60);
}
int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    int max_Nap=0;
    int max_Nap_Op = s_To_Minute("10:00");
    int last_Ed=s_To_Minute("10:00");
    int nap_Cash;
    int i=0;
    while(cin>>n)
    {
        ++i;
        string op, ed, cash;
        for(int i = 0; i < n; ++i)
        {
            cin >> op >> ed >> cash;
            nap_Cash = s_To_Minute(op)-last_Ed;
            if(nap_Cash > max_Nap)
            {
                max_Nap = nap_Cash;
                max_Nap_Op = s_To_Minute(op);
            }
            last_Ed = s_To_Minute(ed);

        }
        {
            op =last_Ed;
            ed = "18:00";
            nap_Cash = s_To_Minute(op)-last_Ed;
            if(nap_Cash > max_Nap)
            {
                max_Nap = nap_Cash;
                max_Nap_Op = s_To_Minute(op);
            }
            last_Ed = s_To_Minute(ed);

        }
        if(max_Nap<60)
        {
            cout << "Day #" << i << " the longest nap starts at " << minute_To_S(max_Nap_Op)<<" and will last for "<< max_Nap << " minutes.\n";
        }
        else 
        {
            cout << "Day #" << i << " the longest nap starts at " << minute_To_S(max_Nap_Op)<<" and will last for "<< minute_To_S(max_Nap) << " minutes.\n";
        }
       
    }

    return 0;
}
