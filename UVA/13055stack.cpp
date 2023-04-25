#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    string s;
    stack<string> st;
    while(t--)
    {
        cin >> s;
       if(s=="Sleep")
       {
           cin >> s;
           st.push(s);
       }
       else if(s=="Test")
       {
           if(st.empty())
           {
               cout << "Not in a dream\n";
           }
           else {
               cout << st.top() << "\n";
           }
       }
       else if(s=="Kick")
       {
           if(!st.empty())
               st.pop();
           }
       }
    return 0;
}