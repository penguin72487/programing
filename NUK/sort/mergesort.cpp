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
void merge(vector<int> &a, int op, int mid, int end){

    vector<int> LeftSub(a.begin()+op, a.begin()+mid+1),
                RightSub(a.begin()+mid+1, a.begin()+end+1);

    LeftSub.push_back(2147483647);      // 在LeftSub[]尾端加入值為 Max 的元素
    RightSub.push_back(2147483647);    // 在RightSub[]尾端加入值為 Max 的元素

    int idxLeft = 0, idxRight = 0;

    for (int i = op; i <= end; i++) {

        if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
            a[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{
            a[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}

void mergesort(vector<int> &a, int op, int end){
                                         
    if (op < end) {                   
        int mid = (op+end)/2;         
        mergesort(a, op, mid);    
        mergesort(a, mid+1, end);   
        merge(a, op, mid, end);   
    }
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
    
    mergesort(a,0,n-1);

    for(int i=0; i<n;++i)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}