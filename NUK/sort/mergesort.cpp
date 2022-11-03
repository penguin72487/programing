#include<iostream>
#include<vector>
using namespace std;
// void swap(int & a,int & b)
// {
//     a^=b^=a^=b;
// }
void swap(int & a,int & b)
{
    int tmp = a;
    a = b;
    b=tmp;
}
vector<int> mergesort(int op, int ed,vector<int> &a)
{
    vector<int> tmp;
    if(op ==ed)
    {
        
        tmp.push_back(op);
        return tmp;
    }
    int mid = (op + ed) / 2;
    vector<int> l = mergesort(op,mid,a);
    vector<int> r = mergesort(mid+1,ed,a);
    auto it = l.begin();
    auto jt = r.begin();
    while(it!=l.end()||jt!=r.end())
    {
        if(it==l.end()||jt==r.end())
        {
            if(it==l.end())
            {
                tmp.push_back(*jt);
                ++jt;
            }
            else {
                tmp.push_back(*it);
                ++it;
            }
        }
        if(it<jt)
        {
            tmp.push_back(*it);
            ++it;
        }
        else {
            tmp.push_back(*jt);
            ++jt;
        }
    }
    return tmp;
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
    
    mergesort(0,n-1,a);

    for(int i=0; i<n;++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}