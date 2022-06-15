#include <iostream>
#include <vector>
#include <set>
#include<unordered_map>
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
    bool operator <(const node &val2)const {
            if(x==val2.x)
            {
                return (y<val2.y);
            }
            else
            {
                return (x < val2.x);
            }

        }
    
      
};
class sort_X{
    public:
    sort_X()
    {

    }
    bool operator ()(const node val,const node &val2)const {
            if(val.x==val2.x)
            {
                return (val.y<val2.y);
            }
            else
            {
                return (val.x < val2.x);
            }

        }
};
class sort_Y{
    public:
    sort_Y()
    {

    }
    bool operator ()(const node val2,const node &val)const {
            if(val.x==val2.x)
            {
                return (val.y<val2.y);
            }
            else
            {
                return (val.x < val2.x);
            }

        }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int t_X,t_Y,t_Ty;
    set<node,sort_X> list_X;
    set<node,sort_Y> list_Y;
    unordered_map<int, unordered_map<int, int>> ii_vec;
    int x_max=0;
    int y_min=0, y_max=-2147483648;
    for(int i=0;i<n;i++){
        cin>>t_X>>t_Y>>t_Ty;
        //node &tmp = node(t_X, t_Y, t_Ty);
        list_X.insert(node(t_X, t_Y, t_Ty));
        list_Y.insert(node(t_X, t_Y, t_Ty));
        
        x_max = max(x_max, t_X);
        y_max = max(y_max, t_Y);
        y_min = min(y_min, t_Y);
    }
    
    vector<set<int>> vec_X(x_max+1);
    vector<set<int>> vec_Y(y_max-y_min+1);

    y_min = abs(y_min);
    int x=0,y=y_min;
    
    for(auto it=list_X.begin(); it!=list_X.end();++it){
        vec_X[it->x].insert(it->y+y_min);
        ii_vec[it->x][it->y+y_min] = (it->type^1);
    }
    for(auto it=list_Y.begin(); it!=list_Y.end();++it){
        vec_Y[it->y+y_min].insert(it->x);
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
                if(ii_vec[x][y]==0)
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
                if(ii_vec[x][y]==0)
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
                if(ii_vec[x][y]==0)
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
                if(ii_vec[x][y]==0)
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