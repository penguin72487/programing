#include<bits/stdc++.h>
using namespace std;
struct student{
public:
    int num;
    int score;
    bool operator>(student b)
    {
        if(score ==b.score )
        {
            return (num > b.num);
        }
        else {
            return (score>b.score);
        }
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    student people[n];
    for(int i=0; i<n; i++){
        cin >> people[i].num >> people[i].score;
    }
    for(int i=0; i<n;++i)
    {
        for(int j=0; j<n-i-1;++j)
        {
            if(people[j]>people[j+1])
            {
                swap(people[j],people[j+1]);
            }
        }
    }
    for (auto it = people; it != people + n;++it)
    {
        cout << it->num << " " << it->score << "\n";
    }

        return 0;
}