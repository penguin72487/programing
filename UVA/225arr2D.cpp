#include<bits/stdc++.h>
using namespace std;
bool can_K_Move(int k,int q){ // can k move?
    if((q==9&&k==0)||(q==14&&k==7)||(q==49&&k== 56)||(q==54&&k==63))
    {
        return 0;
    }
    else {
        return 1;
    }
}
bool in(int a,int b){  // if a in  b
    if(a%8==b%8||(a<b-b%8+8&&a>b-b%8))
    {
        return 1;
    }
    else {
        return 0;
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int k, q, n;
    while(cin>>k>>q>>n)
    {
        if(k==q)
        {
            cout << "Illegal state\n";
        }
        else if(q==n)
        {
            cout<<"Illegal move\n";
        }
        else if(!can_K_Move(k,q))
        {
            break;
        }
        else if(in(n,q)){ // n in q?
            if(in(k,q)) // k in q?
            {
                
            }
            else if(in(q,k)){// q in k?
                cout<<"Illegal move\n";
            }
            else if(!in(q,k))
            {
                cout << "Continue\n";
            }
        }
        else{
            cout<<"move not allowed\n";
        }
    }
    return 0;
}
// 17 17 49
// 17 49 56
// 17 49 9
// 17 49 17
// 17 49 25
// 17 49 33
// 17 49 41
// 17 49 49
// 56 48 49