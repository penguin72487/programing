#ifndef __HUFFMAN_HPP__
#define __HUFFMAN_HPP__
#include <iostream>
#include "Heap.hpp"
#include "linklist.hpp"
#include <string>
using namespace std;
#define endl "\n"
class huffman_Value {
    public:
    string name;
    int frequency;
    huffman_Value() : name(""), frequency(0) {}
    huffman_Value(string _name, int _frequency) : name(_name), frequency(_frequency) {}
};

class Huffman {
    class node : public heap_Value {
    public:
        string code;// char
        int frequency;
        node* left;
        node* right;
        node() : code(""), frequency(0), left(nullptr), right(nullptr) {}
        node(string _code, int _frequency) : code(_code), frequency(_frequency), left(nullptr), right(nullptr) {}
        heap_Value& operator=(const heap_Value& other) override {
            if (this != &other) {
                const node& n = dynamic_cast<const node&>(other);
                code = n.code;
                frequency = n.frequency;
                left = n.left;
                right = n.right;
            }
            return *this;
        }
        bool operator<(const heap_Value& b) const override {
            const node& n = dynamic_cast<const node&>(b);
            return frequency > n.frequency;
        }
        bool operator>(const heap_Value& b) const override {
            const node& n = dynamic_cast<const node&>(b);
            return frequency < n.frequency;
        }
        bool operator!=(const heap_Value& b) const override {
            const node& n = dynamic_cast<const node&>(b);
            return frequency != n.frequency;
        }
    };
    node* root;
    int n;
    string* codeTable;
    void buildTable(node*& cur, string code) {
        if (cur->left == nullptr && cur->right == nullptr) {
            codeTable[cur->code[0]-'A'] = code;
            return;
        }
        if (cur->left != nullptr) {
            buildTable(cur->left, code + "0");
        }
        if (cur->right != nullptr) {
            buildTable(cur->right, code + "1");
        }
    }
    void del(node*& cur) {
        if (cur->left != nullptr) {
            del(cur->left);
        }
        if (cur->right != nullptr) {
            del(cur->right);
        }
        delete cur;
    }

    public:

    Huffman(linklist<huffman_Value>& list) {
        n = list.size();
        codeTable = new string[n];
        Heap<node> h(n);
        for (auto& i : list) {
            h.push(node(i.name, i.frequency));
        }
        while (h.size() > 1) {
            node* a = new node(h.top());
            h.pop();
            node* b = new node(h.top());
            h.pop();
            node* c = new node(a->code + b->code, a->frequency + b->frequency);
            c->left = a;
            c->right = b;
            h.push(*c);
        }
        root = new node(h.top());
        h.pop();
        buildTable(root, "");
    }
    ~Huffman() {
        delete[] codeTable;
        del(root);
    }
    string encode(char s) {
        return codeTable[s-'A'];
    }
    string operator[](const char s) {
        return codeTable[s-'A'];
    }
    
    friend ostream& operator<<(ostream& os, const Huffman& h) {
        for (int i = 0; i < h.n; ++i) {
            os << (char)(i+'A') << " " << h.codeTable[i] << endl;
        }
        return os;
    }
};
#endif
