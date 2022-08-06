#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
void swap(int &a,int &b);
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        vector<int> sorted_Arr = arr;
        sort(sorted_Arr.begin(), sorted_Arr.end());
        bool flag = 1;
        while(flag&&sorted_Arr!=arr)
        {
            flag = 0;
            for (auto it = next(arr.begin());it  != arr.end();++it)
            {
                if(*it<*prev(it)&&(*it^*prev(it)))
                {
                    swap(*it,*prev(it));
                    flag = 1;
                }
            }
        }
        if(sorted_Arr==arr)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
void swap(int &a,int &b)
{
    a^=b^=a^=b;
}