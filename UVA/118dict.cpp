#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};//W N E S

    int x_Ed,y_Ed;
    cin>>x_Ed >> y_Ed;
    int x, y;
    char vec;
    set<pair<int, int>> spii;
    while(cin>>x>>y>>vec)
    {
        int v = 0;
        switch(vec)
        {
            case 'W':
                v = 0;
                break;
            case 'N':
                v = 1;
                break;
            case 'E':
                v = 2;
                break;
            case 'S':
                v = 3;
                break;

            default:
                v = 5;
                break;
        }
        if(v==5)
        {
            break;
        }
        string s;
        cin >> s;
         // abs
        bool flag = 0;
        for(auto& it:s)
        {

            if(it=='R')
            {
                ++v;
                v %= 4;
            }
            else if(it=='L')
            {
                --v;
                v += 4;
                v%= 4;
            }
            else if(it=='F')
            {
                x += dx[v];
                y += dy[v];
                if(x<0||y<0||x>x_Ed||y>y_Ed)
                {
                    if(spii.find({x - dx[v], y - dy[v]})!=spii.end())
                    {
                        x -= dx[v];
                        y -= dy[v];
                        continue;
                    }
                    cout << x - dx[v] << " " << y - dy[v];
                    switch(v)
                    {
                        case 0:
                            cout << " W LOST\n";
                            
                            break;
                        case 1:
                            cout << " N LOST\n";
                            break;
                        case 2:
                            cout << " E LOST\n";
                            break;
                        case 3:
                            cout << " S LOST\n";
                            break;

                    }
                    spii.insert({x - dx[v], y - dy[v]});
                    flag = 1;
                    break;
                }
            }

        }
        if(flag)
        {
            continue;
        }
        cout << x << " " << y;
        switch(v)
        {
            case 0:
                cout << " W\n";
                
                break;
            case 1:
                cout << " N\n";
                break;
            case 2:
                cout << " E\n";
                break;
            case 3:
                cout << " S\n";
                break;    
        }

    }
    return 0;
}