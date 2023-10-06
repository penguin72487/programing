#include<iostream>
#include<vector>
using namespace std;
// void swap(int & a,int & b)
// {
//     a^=b^=a^=b;
// }
// void swap(int & a,int & b)
// {
//     int tmp = a;
//     a = b;
//     b=tmp;
// }
void quicksort(int op, int ed,vector<int> &a)
{
    if(op>=ed)
    {
        return; 
    }
    int i=op+1;
    int j=ed;
    int& privot =a[op];
    while(1){
        while(a[i]<=privot&&i<ed+1)
        {
            ++i;
        }
        while(a[j]>privot&&j>op-1)
        {
            --j;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
        else {
            break;
        }
    }
    swap(privot,a[j]);
    quicksort(op, j-1, a);
    quicksort(i, ed, a);
    return;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n;++i){
        cin>>a[i];
    }
    
    quicksort(0,n-1,a);

    for(int i=0; i<n;++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}