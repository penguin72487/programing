#include<iostream>
#include<vector>
#include<tuple>
#include<fstream>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    long long a, b,c;
    vector<tuple<long long, long long, long long>> iil;
    for(int i=0; i<m; ++i)
    {
        cin >> a >> b >> c;
        iil.push_back(make_tuple(a, b, c));
        //cout << a << " -> " << b << " [label=\"" << c << "\"]\n";
    }
    fstream f;
    f.open("graph.txt");
    for (auto it : iil)
    {
        auto [a, b, c] = it;
        f << a << " -> " << b << " [label=\"" << c << "\"]\n";
    }
    f.close();
        return 0;
}