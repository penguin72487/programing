#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int arr[3];
        for(int i=0;i<3;++i){
            cin>>arr[i];
        }
        sort(arr,arr+3);
        for(int i=0;i<3;++i){
            arr[i]=arr[i]-arr[0];
        }
        if((arr[1]/arr[0]+arr[2]/arr[0])<=5){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
