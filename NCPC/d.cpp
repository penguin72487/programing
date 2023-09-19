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
    Node* head = nullptr;

    static bool comp(const Node* a, const Node* b) {
        if(a->probability==b->probability)
            return a->letter > b->letter;
        else
            return a->probability > b->probability;
    }

    Huffman(priority_queue<Node*, vector<Node*>, decltype(&comp)>& pq) {
        while (pq.size() > 1) {
            Node* a = pq.top();
            pq.pop();
            Node* b = pq.top();
            pq.pop();
            Node* c = new Node(a->letter + b->letter, a->probability + b->probability);
            c->left = a;
            c->right = b;
            pq.push(c);
        }
        head = pq.top();
        pq.pop();
    }
    void let_Len(unordered_map<string,int>& m, Node* head,int nowLen){
        if(head==nullptr){
            return;
        }
        if(head->letter.size()==2){
            m[head->letter]=log2(nowLen);
            return;
        }
        let_Len(m,head->left,nowLen<<1);
        let_Len(m,head->right,nowLen<<1|1);

    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    // string scd="cd";
    // string sdc="dc";
    // cout<<(scd<sdc)<<"\n";
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<tuple<string,float>>vtcf;
        priority_queue<Huffman::Node *, vector<Huffman::Node *>, decltype(&Huffman::comp)> pq(Huffman::comp);
        for (int i = 0; i < n; ++i) {
            string c;
            float f;
            cin >> c >> f;
            for(auto&[cc,ff]:vtcf)
            {
                pq.push(new Huffman::Node(c+cc,f*ff));
                pq.push(new Huffman::Node(cc+c,f*ff));
                
            }
            pq.push(new Huffman::Node(c+c,f*f));
            vtcf.push_back({c,f});
        }        
        string s;
        cin >> s;
        Huffman h(pq);
        unordered_map<string,int> m;
        h.let_Len(m,h.head,1);
        long long ans=0;
        for(int i=0;i<s.size();i++)
        {
            string ss="";
            ss+=s[i];
            ++i;
            ss+=s[i];
            ans+=m[ss];
        }
        cout << ans << "\n";

    }
    return 0;
}
