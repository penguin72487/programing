#include <iostream>
#include "linklist.hpp"
#include "Huffman.hpp"
using namespace std;
#define endl "\n"
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    linklist<huffman_Value> list;
    freopen("sampin.txt", "r", stdin);
    // freopen("testin.txt", "r", stdin);
    freopen("sampout.txt", "w", stdout);
    string s;
    int f;
    while (cin.peek()!='\n') {
        cin >> s >> f;
        list.push_back(huffman_Value(s, f));
        cin.ignore();
    }
    Huffman h(list);
    cout<<h<<endl;
    cin>>s;
    for(auto c:s){
        cout<<h[c];
    }
    cout<<endl;


    return 0;
}
