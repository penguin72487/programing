#include<iostream>
#include<vector>
#include<unordered_map>
#include<iterator>
#include<limits>
#include<fstream>
using namespace std;
unordered_map<int *, long long> pi_Map;
int* min_Ptr(int *val,int *ed)
{
    int i_Min=numeric_limits<int>::max();
    for (auto it = val; it != ed; ++it)
    {
        i_Min = min(i_Min, *it);
    }
    auto it = val;
    while(*it!=i_Min)
    {
        ++it;
    }
    return it;
}
int i_Liky(int *val,int *ed)
{
    /*
    for (auto it = val; it != ed;++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
    */
    int *p_Min = min_Ptr(val, ed);
    if(val+1==ed)
    {
        return *val;
    }
    //cout <<"prior " << pi_Map[p_Min-1]-pi_Map[val-1]<< " "<< pi_Map[ed - 1] - pi_Map[p_Min] << " ";
    if(pi_Map[p_Min-1]-pi_Map[val-1]>pi_Map[ed-1]-pi_Map[p_Min])
    {
        return i_Liky(val, p_Min);
    }
    else
    {
        return i_Liky(p_Min + 1, ed);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio (0);
    int n;
    fstream file;
	file.open("g271"); 
    file >> n;
    int *tmp = new int[n + 1];
    //int tmp[n + 2];
    int *list = tmp + 1;
    pi_Map[tmp] = 0;
    long long i_Sum = 0;
    for(int i = 0; i < n;++i)
    {
        file>>list[i];
        i_Sum += list[i];
        pi_Map[&list[i]] = i_Sum;
    }
        cout<< i_Liky(list,list+n) << "\n";
}