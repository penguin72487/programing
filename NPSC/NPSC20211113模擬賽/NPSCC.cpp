#include<iostream>
using namespace std;
int main()
{
    int op = 1, ed = 1001;
    int mid = 501;
    string react;
    cout<<"501\n"<<flush;
    while(cin>>react&&react!="correct")
    {
        
        if(react=="lower")
        {
            ed = mid;
            mid = (op + ed) / 2;
        }
        else
        {
            op = mid;
            mid = (op + ed) / 2;
        }
        cout << mid <<"\n"<<flush;
    }
}