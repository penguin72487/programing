#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int n, m;
    cin >> n >> m;
    int sp_M[10000][3];
    int sp_Mi = 0;

    for (int i = 0; i < n;++i)
    {
        int r;
        cin >> r;
        int e_I[r];
        for (int j = 0; j < r;++j)
        {
            cin >> e_I[j];
        }
        for (int j = 0; j < r;++j)
        {
            sp_M[sp_Mi][0] = i+1;
            sp_M[sp_Mi][1] =e_I[j];
            cin >> sp_M[sp_Mi][2];
            sp_Mi++;
        }
    }
    for (int i = 0; i < sp_Mi;++i)
    {
        cout << sp_M[i][0] << " " << sp_M[i][1] << " " << sp_M[i][2]<<"\n";
    }
    cout << endl;


    int c_Col [10000]={};
    for (int i = 0; i < sp_Mi;++i)
    {
        c_Col[sp_M[i][1]]++;
    }
    int pos[sp_Mi];
    int nzc[sp_Mi];
    int nzc_I = 0;//none zero count
    pos[0] = 0;
    for (int i = 1; i < sp_Mi;++i)
    {
        pos[i] = pos[i-1] + c_Col[i-1];
    }


    int sp_MT[10000][3];
    int sp_MTi = sp_Mi;
    for (int i = 0; i < sp_MTi;++i)
    {
        sp_MT[pos[sp_M[i][1]]][0] = sp_M[i][1];
        sp_MT[pos[sp_M[i][1]]][1] = sp_M[i][0];
        sp_MT[pos[sp_M[i][1]]][2] = sp_M[i][2];
        nzc[nzc_I++] = sp_M[i][0];
        pos[sp_M[i][1]]++;
    }
    for (int i = 0; i < sp_MTi;++i)
    {
        cout << sp_MT[i][0] << " " << sp_MT[i][1] << " " << sp_MT[i][2]<<"\n";
    }
    cout << endl;
    cout << m << " " << n<<"\n";
    int nzc_J = 0;
    int sp_MTj = 0;
    for (int i = 0; i < m; ++i)
    {
        cout << c_Col[i+1]<<" ";
        for (int j = 0; j < c_Col[i+1];++j)
        {
            cout << sp_MT[sp_MTj++][1]<<" ";
        }
        cout << endl;
        sp_MTj -= c_Col[i + 1];
        for (int j = 0; j < c_Col[i+1];++j)
        {
            cout << sp_MT[sp_MTj++][2]<<" ";
        }
        // sp_MTj++;

        cout << endl;
    }

}