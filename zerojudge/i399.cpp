#include <iostream>
using namespace std;
int main()
{
    int num[10] = {0};
    int i_Max=0;
    for(int i = 0; i < 3; i++)
    {
        int tmp ;
        cin >> tmp;
        ++num[tmp];
        i_Max=max(i_Max,num[tmp]);
    }
    cout<<i_Max<<" ";
    for(int i = 9; i >0; i--)
    {
        if(num[i])
        {
            cout<<i<<" ";
        }
    }
}