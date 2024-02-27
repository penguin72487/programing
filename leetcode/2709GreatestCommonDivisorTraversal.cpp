#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) 
    {
        if(nums.size()==1){
            return 1;
        }
        map<int, set<int>> mis;
        for(auto n:nums){
            auto primeDivisors = get_primeDivisors(n);
            for(auto p:primeDivisors){
                for(auto q:primeDivisors){
                    if(p==q)
                    {
                        mis[p];
                    }
                    else{
                        mis[p].insert(q);
                    }
                    
                }
            }

        }
        auto dsu = get_Dsu(mis);
        if(!sameLine(dsu)){
            return 0;
        }
        

            // return oneLine(mis);
            return 1;


    }
    set<int> get_primeDivisors(int n){
        set<int> primeDivisors;
        bool prime = 1;
        for (int i = 2;i<=n;i++){
            if(n%i==0){
                prime = 0;
                primeDivisors.insert(i);
                while(n%i==0){
                    n/=i;
                }
            }
        }
        if(prime){
            primeDivisors.insert(n);
        }
        return primeDivisors;
    }
    map<int, int> get_Dsu(map<int, set<int>> mis){
        map<int, int> parent;
        map<int, int> rank;
        for(auto m:mis){
            parent[m.first] = m.first;
            rank[m.first] = 0;
        }
        for(auto m:mis){
            for(auto s:m.second){
                if(parent[s]!=parent[m.first])
                {
                    if(rank[m.first]<rank[s]){
                        parent[m.first] = parent[s];
                        rank[m.first] = rank[s];
                    }
                    else if(rank[m.first]>rank[s]){
                        parent[m.first] = s;
                    }
                    else{
                        parent[s] = m.first;
                        rank[s]++;
                    }
                }

            }
        }
        return parent;

    }
    bool oneLine(map<int, set<int>> mis){
        int odd = 0;
        for(auto m:mis){
            if(m.second.size()&1){
                odd++;
            }
        }
        return odd<=2;
    }
    bool sameLine(map<int, int> dsu){
        int root = dsu.begin()->second;
        for(auto d:dsu){
            if(d.second!=root){
                return 0;
            }
        }
        return 1;
    }
};
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    Solution s;
    vector<int> nums2 = {40,22,15};
    cout << s.canTraverseAllPairs(nums2)<<endl;
    // vector<int> nums = {2,3,6};
    // cout << s.canTraverseAllPairs(nums)<<endl;
    // vector<int> nums1 = {3, 9, 5};
    // cout << s.canTraverseAllPairs(nums1)<<endl;

#ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}