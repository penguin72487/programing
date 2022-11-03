#include<iostream>
using namespace std;
int count_element(int a[])
{
    return (int)sizeof(a);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int *p = &a[0];

    cout << a <<" "<< p+1<<"\n";
    for(int i=0; i<10; ++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    int *ed = a + 10;
    for (int *ip = a; ip < ed;++ip)
    {
        cout << *ip << " ";
    }
    cout << "\n";

    cout << count_element(a) << "\n";

    return 0;
}