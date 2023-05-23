#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n;
    int t = 0;
    while(cin>>n)
    {
        ++t;
        cout<<setw(4)<<t<<". ";
        vec.clear();
        vector<string> vs;
        if(n==0)
        {
            cout<<"0\n";
            continue;
        }
        while(n)
        {
            int k=n%100;
            if(k!=0)
            {
                vs.push_back(to_string(k));
            }
            n/=100;
            if(n==0)break; 
            k=n%10;
            if(k!=0)
            {
                vs.push_back("shata");
                vs.push_back(to_string(k));
            }
            n/=10;
            if(n==0)break;
            k=n%100;

            if(k!=0)
            {
                vs.push_back("hajar");
                vs.push_back(to_string(k));
            }
            n/=100;
            if(n==0)break;
            k=n%100;

            if(k!=0)
            {
                vs.push_back("lakh");
                vs.push_back(to_string(k));
            }
            n/=100;
            if(n==0)
            {
                break;
            }
            else{
                vs.push_back("kuti");
            }
        }
        for(int i=vs.size()-1;i>=0;--i)
        {
            cout << vs[i];
            if(i!=0)
            {
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}
/*
400600004090000
*/