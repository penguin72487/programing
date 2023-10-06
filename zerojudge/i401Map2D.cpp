#include <iostream>
#include <vector>
#include <set>
#include<map>
using namespace std;
class node{
public:
    int x;
    int y;
    int type;
    node(int t_X,int t_Y,int t_Ty){
        x=t_X;
        y=t_Y;
        type=t_Ty;// 0 / 1 \/
    }
    node()
    {

    }    
      
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int t_X,t_Y,t_Ty;
    map<int,map<int, node>> iin_vec;
    int x_max=0;
    int y_min=0, y_max=-2147483648;
    for(int i=0;i<n;i++){
        cin>>t_X>>t_Y>>t_Ty;
        iin_vec[t_X][t_Y] =node(t_X,t_Y,t_Ty^1);
        
        x_max = max(x_max, t_X);
        y_max = max(y_max, t_Y);
        y_min = min(y_min, t_Y);
    }
    
    set<int> vec_X[x_max+1];
    set<int> vec_Y[y_max-y_min+1];

    y_min = abs(y_min);
    int x=0,y=y_min;
    
    for(auto it=iin_vec.begin(); it!=iin_vec.end();++it)
    {
        for(auto jt = it->second.begin(); jt != it->second.end();++jt)
        {
            vec_X[it->first].insert(jt->first + y_min);
            vec_Y[jt->first + y_min].insert(jt->second.x);
        }
    }

    int abs_Vec = 0; // 0 right 1 up 2 left 3 down
    //int x_Vec[4]={0,-1,0,1};
    //int y_Vec[4]={1,0,-1,0};

    int ans = -1; 
    for (;;)
    {
        ++ans; 
        if(abs_Vec==0)
        {
            set<int>::iterator it;
            if(ans!=0)
            {
                it = vec_Y[y].find(x);
                ++it;
            }
            else
            {
                it = vec_Y[y].begin();
            }
            
            
            if(it==vec_Y[y].end())
            {
                cout<<ans<<"\n";
                break;
            }
            else
            {
                x = *it;
                if(iin_vec[x][y-y_min].type==0)
                {
                    abs_Vec = 1;
                }
                else
                {
                    abs_Vec = 3;
                }
                
            }
        }
        else if(abs_Vec==1)
        {
            auto it = vec_X[x].find(y);
            if(it==vec_X[x].begin())
            {
                cout<<ans<<"\n";
                break;
            }
            else
            {
                --it;
                y = *it;
                if(iin_vec[x][y-y_min].type==0)
                {
                    abs_Vec = 0;
                }
                else
                {
                    abs_Vec = 2;
                }
                
            }
        }
        else if(abs_Vec==2)
        {
            auto it = vec_Y[y].find(x);
            if(it==vec_Y[y].begin())
            {
                cout<<ans<<"\n";
                break;
            }            
            else
            {
                --it;
                x = *it;
                if(iin_vec[x][y-y_min].type==0)
                {
                    abs_Vec = 3;
                }
                else
                {
                    abs_Vec = 1;
                }
                
            }

        }
        else if(abs_Vec==3)
        {
            auto it = vec_X[x].find(y);
            ++it;
            if(it==vec_X[x].end())
            {
                cout<<ans<<"\n";
                break;
            }
            else
            {
                y = *it;
                if(iin_vec[x][y-y_min].type==0)
                {
                    abs_Vec = 2;
                }
                else
                {
                    abs_Vec = 0;
                }
                
            }
        }
    }
}