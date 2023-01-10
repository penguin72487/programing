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
    bool operator<(student b)
    {
        if(score ==b.score )
        {
            return (num < b.num);
        }
        else {
            return (score<b.score);
        }
    }
};
student* binary_Search(int op,int ed,int target,student* people)
{
    if(op>=ed)
    {
        return people+op;
    }
    int mid=(op+ed)/2;
    if(people[mid].score>=target)
    {
        return binary_Search(op, mid, target, people);
    }
    else {
        return binary_Search(mid+1, ed,target, people);
    }

}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    student people[n];
    for(int i=0; i<n; i++){
        cin >> people[i].num >> people[i].score;
    }
    sort(people, people + n,[](auto &a,auto &b)->bool{
        if(a.score ==b.score )
        {
            return (a.num < b.num);
        }
        else {
            return (a.score<b.score);
        }
    });
    int target;
    cin >> target;
    cout << binary_Search(0, n, target, people)-people;
    // for (auto it = people; it != people + n;++it)
    // {
    //     cout << it->num << " " << it->score << "\n";
    // }

    return 0;
}
/*
3
1095501 80
1095502 90
1095503 60
75


4
1095501 80
1095502 90
1095503 60
1095504 59
75

5
1095501 80
1095502 90
1095503 60
1095504 59
1095505 75
75

6
1095501 80
1095502 90
1095503 60
1095504 59
1095505 75
1095506 74
75

6
1095501 80
1095502 90
1095503 60
1095504 59
1095505 75
1095506 74
90


6
1095501 80
1095502 90
1095503 60
1095504 59
1095505 75
1095506 74
100
*/