#ifndef __HEAP_HPP__
#include <iostream>
using namespace std;
#define endl "\n"
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



template<class T> // custom class should be inherited from heap_Value
class Heap{// defalt max heap if want to make min heap, change the logic > to <
    class node{
    public:
        T value;
        node(){}
        node(T __value):value(__value){}
        void swap(node* a,node* b){
            T tmp = a->value;
            a->value = b->value;
            b->value = tmp;
        }

    };

    node *root;
    int max_size;
    int n;
    void up_Heapify(int cur){

        if(cur == 0){
            return;
        }
        int parent = cur >> 1;
        if(root[cur].value > root[parent].value){
            swap(root[cur],root[parent]);
            up_Heapify(parent);
        }
        return;
    }
    void down_Heapify(int cur)
    {
        if(n <2){
            return;
        }
        int left = (cur<<1)>=n?-1:(cur<<1);
        int right = ((cur<<1)|1)>=n?-1:(cur<<1)|1;
        if(left == -1){
            return;
        }
        if(right == -1){
            if(root[left].value > root[cur].value){
                swap(root[left],root[cur]);
            }
            down_Heapify(left);
            return;
        }
        if(root[left].value > root[right].value){
            if(root[left].value > root[cur].value){
                swap(root[left],root[cur]);
            }
            down_Heapify(left);
        }
        else{
            if(root[right].value > root[cur].value){
                swap(root[right],root[cur]);
            }
            down_Heapify(right);
        }
    }
    public:
    Heap(int _Max_Size):max_size(_Max_Size),n(0){
        root = new node[max_size];
    }
    ~Heap(){
        delete[] root;
    }
    void push(T __value){
        if(n == max_size){
            cout<<"Heap is full"<<endl;
            throw "Heap is full";
        }

        root[n] = node(__value);
        up_Heapify(n);
        n++;
    }
    void pop(){
        if(n == 0){
            cout<<"pop Heap is empty"<<endl;
            throw "Heap is empty";
        }
        swap(root[0],root[n-1]);
        n--;
        down_Heapify(0);
    }
    T top(){
        if(n == 0){
            cout<<"top Heap is empty"<<endl;
            throw "Heap is empty";
        }
        return root[0].value;
    }
    bool empty(){
        return n == 0;
    }
    int size(){
        return n;
    }
    void sort(){ //heap sort but it is not Heap anymore
        int tmp_Size=n;
        // node *res;
        while(!empty())
        {
            pop();
        }
        n=tmp_Size;
        for (int i = 1,j=1; i < n; ++i) {
            if (root[i].value != root[i - 1].value) {
                root[j++].value = root[i].value;
                tmp_Size = j;
            }
        }
        n=tmp_Size;

        // return root;
        return;
    }
    T operator[](int i){
        return root[i].value;
    }
    friend ostream& operator<<(ostream& os, const Heap& h){
        for (int i = 0; i < h.n; ++i)
        {
            os<<h.root[i].value<<" ";
        }
        return os;
    }
};
// int main()
// {
//     cin.tie(0)->sync_with_stdio(0);
//     cout.tie(0);
//     int n = 5;
//     Heap<int> h(n);
//     h.push(1);
//     h.push(20);
//     h.push(3);
//     h.push(7);
//     h.push(30);
//     cout<<h<<endl;
//     h.pop();
//     cout<<h<<endl;

//     min_Heap<int> h2(n);
//     h2.push(1);
//     h2.push(20);
//     h2.push(3);
//     h2.push(7);
//     h2.push(30);
//     cout<<h2<<endl;
//     h2.pop();
//     cout<<h2<<endl;
// }
# endif