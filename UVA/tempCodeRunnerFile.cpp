#include<bits/stdc++.h>
using namespace std;
int find_F(int op,vector<int> &uni)
{
    if(uni[op]==op)
    {
        return op;
    }
    return find_F(uni[op], uni);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ++n;
    vector<int> uni(n);
    vector<set<int>> uni_Graph(n);
    vector<long long> sum_Uni(n);
    for(int i=0; i<n;++i)
    {
        uni[i] = i;
        sum_Uni[i] = i;
        uni_Graph[i].insert(i);
    }
    for (int i = 0; i < m;++i)
    {
        int type;
        cin >> type;
        if(type ==1)
        {
            int a, b;
            cin >> a >> b;
            if(find_F(a,uni)==find_F(b,uni))
            {
                continue;
            }
            else {
                
                sum_Uni[find_F(b,uni)] += sum_Uni[find_F(a, uni)];
                sum_Uni[find_F(a, uni)] = 0;
                int f = find_F(a, uni);
                for(auto& it:uni_Graph[find_F(a, uni)])
                {
                    uni_Graph[find_F(b, uni)].insert(it);
                    uni[it] = find_F(b, uni);
                }
                uni_Graph[f].clear();
                uni[a] = find_F(b, uni);
            }

        }
        else if(type ==2)// move a to the set include b
        {
            int a, b;
            cin >> a >> b;
            if(find_F(a,uni)==find_F(b,uni))
            {
                continue;
            }
            else {
                sum_Uni[find_F(a,uni)] -= a;
                sum_Uni[find_F(b,uni)] += a;
                if(uni[a]==a)
                {
                    uni_Graph[find_F(a, uni)].erase(a);
                    uni[a] = find_F(b, uni);
                }
                uni_Graph[find_F(b, uni)].insert(a);
                uni[a] = find_F(b, uni);
            }
            //uni[a] = find_F(b, uni);

        }
        else if(type ==3)
        {
            int a;
            cin >> a;
            cout << uni_Graph[find_F(a,uni)].size() << " " << sum_Uni[find_F(a,uni)]<<"\n";
        }
    }
        return 0;
}