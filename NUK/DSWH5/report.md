# report
Please describe your implementation of Huffman Coding.
If you design a HuffmanTree class, please also describe your consideration. (Bonus 5%)
Just write 1 ~ 4 pages
# 我如何實作赫夫曼樹呢?

因為這個作業不能用C++幾乎所有的STL除了string，所以我把我已經寫好的`linklist`輔助我儲存input，然後還要再使用min_Heap，因為赫夫曼樹會先從頻率最小的節點開始合併，所以我用min_Heap儲存所有node之後，最高的兩個node就是每輪要合併的。
在這裡要注意，node要去heap裡面排序，所以要繼承heap_Value的抽象類別才能保證heap的功能正常。
```cpp
class heap_Value {
public:
    virtual heap_Value& operator=(const heap_Value&) { // Heap custom class should be inherited from heap_Value
        return *this;
    }
    virtual bool operator!=(const heap_Value &b) const = 0;
    virtual bool operator<(const heap_Value&) const = 0;// follow the logic of < to make max heap reverse the logic of < to make min heap
    virtual bool operator>(const heap_Value&) const = 0;// follow the logic of < to make max heap reverse the logic of < to make min heap
    virtual ~heap_Value() = default;
};
```
合併到最後只剩一個node就可以停止了，然後不能使用map，但是在這裡的輸入只有ABCDE按照順序而已所以我就創造一個string的陣列儲存編碼，使用encode()或是[char]取得編碼。

```cpp
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
```
buildTable就是在赫夫曼樹建完之後尋訪所有節點，走到跟節點就把編碼存到table裡面。注意code要用pass by value，還沒到根要把上一段的編碼繼續傳下去。
```cpp
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
```


