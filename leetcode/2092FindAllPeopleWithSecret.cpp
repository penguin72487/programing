#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> ans;
        vector<vector<pair<int,int>>> meetingsMap(n);
        for(int i=0; i<meetings.size(); i++){
            meetingsMap[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            meetingsMap[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        // 獲取firstPerson最早的會議時間
        vector<int> minleaktime(n, INT_MAX);
        queue<tuple<int,int>> q;// {person, firstleaktime}
        q.push({0, 0}); // 0號總是知道秘密的
        q.push({firstPerson, 0});
        while(!q.empty()){
            auto [person, firstleaktime] = q.front();
            q.pop();
            if(firstleaktime >= minleaktime[person]){
                continue;
            }
            ans.push_back(person);
            minleaktime[person] = firstleaktime;
            for(auto [nextPerson, nextleaktime]:meetingsMap[person]){
                if(nextleaktime >= firstleaktime){
                    q.push({nextPerson, nextleaktime});
                }
            }
        }
        

        ans.push_back(0); // 確保0總是在答案中，因為0號總是知道秘密的
        ans.push_back(firstPerson); // 確保firstPerson總是在答案中
        sort(ans.begin(), ans.end()); // 確保答案是排序的
        ans.erase(unique(ans.begin(), ans.end()), ans.end()); // 移除重複元素
        return ans;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    int n = 12;
    vector<vector<int>> meetings = {{10, 8, 6}, {9, 5, 11}, {0, 5, 18}, {4, 5, 13}, {11, 6, 17}, {0, 11, 10}, {10, 11, 7}, {5, 8, 3}, {7, 6, 16}, {3, 6, 10}, {3, 11, 1}, {8, 3, 2}, {5, 0, 7}, {3, 8, 20}, {11, 0, 20}, {8, 3, 4}, {1, 9, 4}, {10, 7, 11}, {8, 10, 18}};
    int firstPerson = 9;
    vector<int> ans = s.findAllPeople(n, meetings, firstPerson);
    for(auto i:ans){
        cout << i << " ";
    }

    return 0;
}