#include<bits/stdc++.h>
#pragma pack(push)  //push current alignment to stack
#pragma pack(1)     //set alignment to 1 byte boundary
using namespace std;
struct s1{
    double d;
    char *str;
    void *ptr;
};
struct s2{
    s1 s;//24
    int n;//4
    char ch[5];//5
    void pring_F();
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cout << sizeof(s1) << " " << sizeof(s2) << "\n";
    //cout<<sizeof(void)<<"\n";
    return 0;
}
#pragma pack(pop)