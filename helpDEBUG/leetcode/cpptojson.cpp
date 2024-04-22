#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    vector<string> v;
    while(getline(cin, s))
    {
        //cin.get();
        cin.sync();

        if(s=="    return 0;")
        {
            //v.push_back("\""+s+"\",");
            break;
        }
        v.push_back("\""+s+"\",");
    }
    for(auto &v : v)
    {
        cout << v << "\n";
    }
    cout << "\"    return 0;\",\n\"}\"\n";
    return 0;
}