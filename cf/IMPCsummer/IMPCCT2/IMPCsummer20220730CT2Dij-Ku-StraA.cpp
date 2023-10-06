#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;
unordered_map<int, int> map_Neighbors;
void pass(int i_Now,vector<int> &count_Line)
{
    
    auto it = map_Neighbors.find(i_Now);
    if(it == map_Neighbors.end())
    {
        return;
    }
    else
    {
        count_Line[it->second] =max(count_Line[it->second],count_Line[i_Now]+1);
        pass(it->second,count_Line);
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;

    int t_Cash;
    for(int i = 0; i < n;++i)
    {
        cin >> t_Cash;
        // if(t_Cash==-1)
        // {
        //     map_Neighbors[i] = i;
        // }
        if(t_Cash!=-1)
        {
            map_Neighbors[i] =t_Cash-1;
        }
    }
    vector<int> count_Line(n);
    fill(count_Line.begin(), count_Line.end(), 1);
    for(int i=0; i<n; i++)
    {
        pass(i, count_Line);
    }
    int i_max=0;
    for(int i=0; i<n; i++)
    {
        i_max=max(count_Line[i],i_max);
    }
    cout << i_max<< "\n";
}