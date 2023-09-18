#include<bits/stdc++.h>
using namespace std;

class Huffman {
public:
    class Node {
    public:
        string letter;
        float probability;
        Node* left;
        Node* right;

        Node(string l, float p) : letter(l), probability(p), left(nullptr), right(nullptr) {}
    };

    static bool comp(const Node* a, const Node* b) {
        return a->probability > b->probability;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {

        int n;
        cin>>n;
        priority_queue<Huffman::Node*, vector<Huffman::Node*>, decltype(&Huffman::comp)> pq(Huffman::comp);
        for (int i = 0; i < n;++i)
        {
            string s;
            float p;
            cin >> s >> p;
            pq.push(new Huffman::Node(s, p));
        }
        string s;
        cin >> s;
        Huffman h(pq);


    }
    return 0;
}