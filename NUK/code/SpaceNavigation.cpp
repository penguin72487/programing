#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    //int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};//L U R D L U R D
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int count_Op[4]={0,0,0,0};
        string in;
        cin >> in;
        for(auto i:in)
        {
            if(i=='L')
            {
                count_Op[0]++;
            }
            else if(i=='U')
            {
                count_Op[1]++;
            }
            else if(i=='R')
            {
                count_Op[2]++;
            }
            else if(i=='D')
            {
                count_Op[3]++;
            }
        }
        bool flag_X = 0, flag_Y = 0;
        if(n<0)
        {
            if(count_Op[0]>=-n)
            {
                flag_X = 1;
            }
        }
        else{
            if(count_Op[2]>=n)
            {
                flag_X = 1;
            }
        }
        if(m<0)
        {
            if(count_Op[3]>=-m)
            {
                flag_Y = 1;
            }
        }
        else{
            if(count_Op[1]>=m)
            {
                flag_Y = 1;
            }
        }
        cout<<(flag_X&&flag_Y?"YES":"NO")<<"\n";


    }
}