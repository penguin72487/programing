#include<bits/stdc++.h>
using namespace std;
float GPA(int score);
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    vector<int> b(n, 0);
    for (int i = 0; i < n;i++)
    {
        cin >> b[i];
    }
    int semester;
    cin >> semester;
    float sum = 0;
    

    return 0;
}
float GPA(int score)
{
    float res = 0;
//     A+	4.3	90-100
// A	4.0	85-89
// A-	3.7	80-84
// B+	3.3	77-79
// B	3.0	73-76
// B−
// 2.7	70-72
// C+	2.3	67-69
// C	2.0	63-66
// C-	1.7	60-62
// F	0	0-59
    if(score<60)
    {
        res = 0;
    }
    else if(score<63)
    {
        res = 1.7;
    }
    else if(score<67)
    {
        res = 2.0;
    }
    else if(score<70)
    {
        res = 2.3;
    }
    else if(score<73)
    {
        res = 2.7;
    }
    else if(score<77)
    {
        res = 3.0;
    }
    else if(score<80)
    {
        res = 3.3;
    }
    else if(score<85)
    {
        res = 3.7;
    }
    else if(score<90)
    {
        res = 4.0;
    }
    else if(score<=100)
    {
        res = 4.3;
    }
    
    return res;
    
}