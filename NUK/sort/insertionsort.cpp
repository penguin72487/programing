#include<iostream>
using namespace std;
void swap(int & a,int & b)
{
    a^=b^=a^=b;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n = 10;
    // cin >> n;
    // int a[n];
    int a[10] = {19, 29, 2, 27, 3, 23, 5, 9, 8, 0};
    // for(int i=0; i<n;++i){
    //     cin>>a[i];
    // }
    
    for(int i=0; i<n;++i)
    {
        for (int j = i; j > 0&&a[j]<a[j-1];--j)
        {
            swap(a[j],a[j-1]);
        }
    }

    for(int i=0; i<n;++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}