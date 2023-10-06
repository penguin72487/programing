#include<bits/stdc++.h>
using namespace std;

class unifi{//union find
    public:
    int n;
    vector<int> uni;
    vector<set<int>> uni_Graph;
    vector<long long> sum_Uni;
    unifi(int t_n){
        n = t_n;
        uni.resize(n);
        uni_Graph.resize(n);
        sum_Uni.resize(n);
        for(int i=0; i<n;++i)
        {
            uni[i] = i;
            sum_Uni[i] = i;
            uni_Graph[i].insert(i);
        }
    }
    void a_To_setB(int a, int b){// move a to the set include b
        if(find_F(a)==find_F(b))
        {
            return;
        }
        else {
            if(uni_Graph[a].size()==1)
            {
                setA_To_setB(a,b);
            }
            else if(uni[a]==a)
            {
                int num=*uni_Graph[a].begin();
                for(auto& it:uni_Graph[a])
                {
                    if(it!=a)
                    {
                        num = it;
                        break;
                    }
                }
                uni[num] = num;
                setA_To_setB(a, num);
                a_To_setB(a, b);
            }
            else {
                sum_Uni[find_F(a)] -= a;
                uni_Graph[find_F(a)].erase(a);
                uni_Graph[a].insert(a);
                uni[a] = a;
                sum_Uni[a] += a;
                setA_To_setB(a, b);
            }
        }
    }
    void setA_To_setB(int a, int b){ // move set A into set B
        if(find_F(a)==find_F(b))
        {
            return;
        }
        else {
            
            sum_Uni[find_F(b)] += sum_Uni[find_F(a)];
            sum_Uni[find_F(a)] = 0;
            int f = find_F(a);
            for(auto& it:uni_Graph[find_F(a)])
            {
                uni_Graph[find_F(b)].insert(it);
                uni[it] = find_F(b);
            }
            uni_Graph[f].clear();
            uni[a] = find_F(b);
        }
    }
    int find_F(int op)
    {
        if(uni[op]==op)
        {
            return op;
        }
        return find_F(uni[op]);
    }

};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    while(cin >> n >> m)
    {
        if(n==m&&n==0)
        {
            break;
        }
        ++n;

        unifi uni(n);
        for (int i = 0; i < m;++i)
        {
            int type;
            cin >> type;
            if(type ==1)
            {
                int a, b;
                cin >> a >> b;
                uni.setA_To_setB(a,b);

            }
            else if(type ==2)// move a to the set include b
            {
                int a, b;
                cin >> a >> b;
                uni.a_To_setB(a, b);
                //uni[a] = find_F(b, uni);

            }
            else if(type ==3)
            {
                int a;
                cin >> a;
                cout << uni.uni_Graph[uni.find_F(a)].size() << " " << uni.sum_Uni[uni.find_F(a)]<<"\n";
            }
        }
    }
    
        return 0;
}