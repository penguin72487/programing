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
        set<int> numsSet;
        for(auto n:nums){
            numsSet.insert(n);
        }
        if(numsSet.find(1)!=numsSet.end()){
            return 0;
        }
        set<int> primes = get_prime(*numsSet.rbegin());

        for(auto n:numsSet){
            auto primeDivisors = get_primeDivisors(n, primes);
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

    set<int> get_prime(int n) {
        // 使用篩法預先計算100000以內的所有質數
        vector<bool> is_prime(n + 1, true);
        for (int i = 2; i * i <= n; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        set<int> primes;
        // 將所有質數加入集合中
        for (int i = 2; i <= n; ++i) {
            if (is_prime[i]) {
                primes.insert(i);
            }
        }
        return primes;
    }

    set<int> get_primeDivisors(int n, set<int>& primes) {
        set<int> primeDivisors;
        // 遍歷所有質數，找出質因數
        for (int prime : primes) {
            while (n % prime == 0) {
                primeDivisors.insert(prime);
                n /= prime;
            }
        }

        // 如果n本身是一個質數，則將其加入質因數集合中
        if (n > 1) {
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
                    int x = find(m.first, parent);
                    int y = find(s, parent);
                    if(rank[x]>rank[y]){
                        parent[y] = x;
                    }
                    else if(rank[x]<rank[y]){
                        parent[x] = y;
                    }
                    else{
                        parent[y] = x;
                        rank[x]++;
                    }
                }

            }
        }
        for(auto m:mis){
            parent[m.first] = find(m.first, parent);
        }
        return parent;

    }
    int find(int x, map<int, int> parent){
        if(parent[x]!=x){
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
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
        if(dsu.size()==0){
            return 0;
        }
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
    vector<int> nums2 = {42, 40, 45, 42, 50, 33, 30, 45, 33, 45, 30, 36, 44, 1, 21, 10, 40, 42, 42};
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