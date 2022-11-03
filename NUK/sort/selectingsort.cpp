#include<iostream>
using namespace std;
// void swap(int & a,int & b)
// {
//     a^=b^=a^=b;
// }
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n;++i){
        cin>>a[i];
    }
    int* min_P;
    for(int i=0; i<n-1;++i)
    {
        min_P =&a[i];
        for(int j=i+1; j<n;++j)
        {
            if(a[j]<*min_P)
            {
                min_P=&a[j];
            }

        }
        swap(a[i], *min_P);
    }
    for(int i=0; i<n;++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}