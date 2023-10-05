#include <iostream>
#include <algorithm>
using namespace std;
int ask();
int ask_X(int t);
int ask_Y(int t);
int main()
{
   // cin.tie(0)->sync_with_stdio(0);
    //cout.tie(0);
    int t=ask();
    if(t==0)
    {
        cout << "! 3000 3000";
        cout.flush();
    }
    int x = ask_X(t);
    int y=ask_Y(t);
    cout << "! " << x << " " << y;
    cout.flush();

}
int ask()
{
    int op = 1;
    int ed = 12001;
    int mid;
    string in;
    while (op < ed)
    {
        mid=(op+ed)/2;
        cout << "? 3000 3000 " << mid;
        cout.flush();

        cin >> in;
        if(in=="Yes")
        {
            ed = mid;
        }
        else
        {
            op = mid + 1;
        }
    }
    return mid;
}
int ask_X(int t)
{
    int op = 1;
    int ed = 6001;
    int mid;
    string in;
    while (op < ed)
    {
        mid=(op+ed)/2;
        cout << "? "<<mid<<" 3000 " << t-3000+mid-1;
        cout.flush();

        cin >> in;
        if(in=="Yes")
        {
            op = mid;
           
        }
        else
        {
            ed = mid-1;
        }
    }
    return mid;

}

int ask_Y(int t)
{
    int op = 1;
    int ed = 6001;
    int mid;
    string in;
    while (op < ed)
    {
        mid=(op+ed)/2;
        cout << "? "<<" 3000 "<<mid << t-3000+mid-1;
        cout.flush();

        cin >> in;
        if(in=="Yes")
        {
            op = mid;
           
        }
        else
        {
            ed = mid-1;
        }
    }
    return mid;

}