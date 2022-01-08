#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
    int n,ed;
    cin >> n>>ed;
    int fk_tree_Loc[n + 1];
    *fk_tree_Loc = 0;
    int *tree_Loc = fk_tree_Loc+1;
    for (int i = 0; i < n ;++i)
    {
        cin >> tree_Loc[i];
    }
    int tree_H[n];
    for (int i = 0; i < n;++i)
    {
        cin>>tree_H[i];
    }
        list<int> seg;
    for (int i = 0; i < n;++i)
    {
        seg.push_back(fk_tree_Loc[i+1]-fk_tree_Loc[i]);
    }
    for (auto it = seg.begin(); it != seg.end();++it)
    {
        cout << *it << " ";
    }
    cout << "\n";
}