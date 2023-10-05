#include<bits/stdc++.h>
using namespace std;
vector<int> vec;
void to_Bangla(long long x,int count)
{
    if(x==0)
    {
        return;
    }
    if(count%4==1)
    {
        vec.push_back(x%10);
        to_Bangla(x/10,count+1);
    }
    else {
        vec.push_back(x%100);
        to_Bangla(x/100,count+1);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n;
    int t = 0;
    while(cin>>n)
    {
        ++t;
        vec.clear();
        to_Bangla(n,0);
        vector<string> vec2;
        for (int i = 0;i<vec.size();i++)
        {
            if(vec[i]!=0)
            {
                vec2.push_back(to_string(vec[i]));
            }


            if(i%4==0)
            {
                vec2.push_back("shata");
            }
            else if(i%4==1)
            {
                vec2.push_back("hajar");
            }
            else if(i%4==2)
            {
                vec2.push_back("lakh");
            }
            else if(i%4==3)
            {
                vec2.push_back("kuti");
            }
        }
        if (!vec2.empty()) {
            vec2.pop_back();
        }
        reverse(vec2.begin(),vec2.end());
        cout<<t<<". ";
        for(auto it:vec2)
        {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}
//4