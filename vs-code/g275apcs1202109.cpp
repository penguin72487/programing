#include<iostream>
using namespace std;
bool rulA(int *tmp)
{
    if(tmp[1]!=tmp[3]&&tmp[1]==tmp[5])
    {
        return 1;
    }
    return 0;
}
bool rulB(int *val,int *val2)
{
    if(val[6]&&!val2[6])
    {
        return 1;
    }
    return 0;
}
bool rulC(int *val,int *val2)
{
    if(val[1]^val2[1]&&val[3]^val2[3]&&val[5]^val2[5])
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;++i)
    {
        int u[7];
        int d[7];
        for (int j = 0; j < 7;++j)
        {
            cin >> u[j];
        }
        for (int j = 0; j < 7;++j)
        {
            cin >> d[j];
        }
        bool flag = 1;
        if(rulA(u)&&rulA(d))
        {

        }
        else
        {
            flag = 0;
            cout << "A";
        }
        if(!rulB(u,d))
        {
            flag = 0;
            cout << "B";
        }
        if(!rulC(u,d))
        {
            flag = 0;
            cout << "C";
        }
        if(flag)
        {
            cout << "None";
        }
        cout << "\n";
    }
}