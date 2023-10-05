#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> cost;
    int benif[n];
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        cost.push_back(tmp);
    }
    reverse(cost.begin(),cost.end());
    int i=0;
    for(auto it=cost.begin();it!=cost.end();++it,++i)
    {
        make_heap(cost.begin(),it);
        benif[n-1-i]=cost[0]-*it;
    }
    make_heap(benif,benif+n);
    cout<<benif[0]<<endl;

}
