#include<iostream>
using namespace std;
int main()
{
    int n,p;
    while (cin >> n >> p)
    {
        int c[n],d[n];
        for (int i=0;i<n;i++)
        {
            cin >> c[i];
        }
        int m;
        int sum=0;
        cin >> m;
        for (int i=0;i<m;i++)
        {
            sum=0;
            for (int j=0;j<n;j++)
            {
                cin >> d[j];
                if (d[j]==c[j])
                    sum+=p;
            }
            cout << sum << endl;
        }
    }
    return 0;
}
