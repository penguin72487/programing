#include<bits/stdc++.h>
using namespace std;
int main(){
    set<long long> same;
    string s,s1;
    while(getline(cin,s) && s!="0"){
        same.clear();
        stringstream sti(s);
        long long int a=0,b=0;
        cout<<"Original number was "<<s<<endl;
       while(1){
        sort(s.rbegin(),s.rend());
        stringstream sti1(s);
        sti1 >> a;
        sort(s.begin(),s.end());
        stringstream sti2(s);
        sti2 >> b;
        cout<<a<<" - "<<b<<" = "<<a-b<<endl;
        if( same.find(a-b) != same.end() ){
            break;
        }
         same.insert(a-b);
         stringstream its;
         its << a-b;
         its >> s;
       }
       cout<<"Chain length "<<same.size()+1<<endl<<endl;
    }

}