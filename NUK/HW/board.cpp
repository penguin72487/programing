#include<bits/stdc++.h>
using namespace std;
string crouse = "CS101 introduction to OOP programming";//CS101 introduction to C++ programming
class gBook{
    public:
        void displayMsg(string course){
            cout << "wellcom to the grade book for\n"<<course<<"\n";
        }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    gBook book;
    string s;
    getline(cin, s);
    book.displayMsg(s);
    book.displayMsg(::crouse);
    return 0;
}