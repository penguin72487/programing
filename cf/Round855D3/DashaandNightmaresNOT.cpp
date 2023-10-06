#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<string> vs(n);
    for(auto& it:vs)
    {
        cin>>it;
    }
    
    vector<vector<int>> count(n,vector<int>(26,0));
    for(int i=0;i<n;++i)
    {
        for(auto& it:vs[i])
        {
            count[i][it-'a']++;
        }
    }
    multimap<int,vector<int>> mtMi_vi;
    for(auto& it:count)
    {
        mtMi_vi.insert({count_if(it.begin(),it.end(),[](int x){return x>0;}),it});
    }

    int ans = 0;
    for(auto& it:mtMi_vi)
    {
        int sz = it.first;
        if(mtMi_vi.find(25 - sz)!=mtMi_vi.end())
        {
            int n=mtMi_vi[sz].size();
            int m=mtMi_vi[25-sz].size();
            for (int i = 0;i<n;++i)
            {
                for (int j = 0;j<m;++j)
                {
                    vector<int> tmp_Count(26,0);
                    for (int k = 0; k < 26;++k)
                    {
                        tmp_Count[k] = mtMi_vi[sz][i][k] + mtMi_vi[25-sz][j][k];
                    }
                    if(count_if(tmp_Count.begin(),tmp_Count.end(),[](int x){return x>0;})==25)
                    {
                        if((sz+25-sz)&1)
                        {
                            bool flag = true;
                            for (int k = 0; k < 26;++k)
                            {
                                if(tmp_Count[k]&1||tmp_Count[k]==0)
                                {
                                }
                                else{
                                    flag = false;
                                    break;
                                }
                            }
                            if(flag)
                            {
                                ans++;
                            }
                        }        
                    }
                }
            }
        }
    }
    cout << ans << "\n";

    return 0;
}
            // vector<int> tmp_Count(26,0);
            // for (int k = 0; k < 26;++k)
            // {
            //     tmp_Count[k] = count[i][k] + count[j][k];
            // }
            // if(count_if(tmp_Count.begin(),tmp_Count.end(),[](int x){return x>0;})==25)
            // {
            //     if((vs[i].size()+vs[j].size())&1)
            //     {
            //         bool flag = true;
            //         for (int k = 0; k < 26;++k)
            //         {
            //             if(tmp_Count[k]&1||tmp_Count[k]==0)
            //             {
            //             }
            //             else{
            //                 flag = false;
            //                 break;
            //             }
            //         }
            //         if(flag)
            //         {
            //             ans++;
            //         }
            //     }        
            // }