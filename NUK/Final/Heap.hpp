#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define endl "\n"
class value{
    public:
    value(){}
    virtual value &operator=(const value &) = 0;
    virtual bool operator<(const value &b) const = 0;
    virtual bool operator >(const value& b) const=0;
};


template<class T>
class max_Heap{
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
    int size;


    node min(node a, node b){
        
        return a.value < b.value?a:b;
    }

    void up_Heapify(int cur){

        if(cur == 0){
            return;
        }
        int parent = cur>>1;
        if(root[cur].value > root[parent].value){
            swap(root[cur],root[parent]);
            up_Heapify(parent);
        }
        return;
    }
    void down_Heapify(int cur)
    {
        int left = (cur<<1)>=size?-1:(cur<<1);
        int right = ((cur<<1)|1)>=size?-1:(cur<<1)|1;
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
    max_Heap(int _Max_Size):max_size(_Max_Size),size(0){
        root = new node[max_size];
    }
    ~max_Heap(){
        delete[] root;
    }
    void push(T __value){
        if(size == max_size){
            cout<<"Heap is full"<<endl;
            throw "Heap is full";
        }

        root[size] = node(__value);
        up_Heapify(size);
        size++;
    }
    void pop(){
        if(size == 0){
            cout<<"Heap is empty"<<endl;
            throw "Heap is empty";
        }
        root[0] = root[size-1];
        size--;
        down_Heapify(0);
    }
    T top(){
        if(size == 0){
            cout<<"Heap is empty"<<endl;
            throw "Heap is empty";
        }
        return root[0].value;
    }
    bool empty(){
        return size == 0;
    }
    friend ostream& operator<<(ostream& os, const max_Heap& h){
        for (int i = 0; i < h.size; ++i)
        {
            os<<h.root[i].value<<" ";
        }
        return os;
    }
};
template<class T>
class min_Heap{class node{
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
    int size;


    node min(node a, node b){
        
        return a.value < b.value?a:b;
    }

    void up_Heapify(int cur){

        if(cur == 0){
            return;
        }
        int parent = cur>>1;
        if(root[cur].value < root[parent].value){
            swap(root[cur],root[parent]);
            up_Heapify(parent);
        }
        return;
    }
    void down_Heapify(int cur)
    {
        int left = (cur<<1)>=size?-1:(cur<<1);
        int right = ((cur<<1)|1)>=size?-1:(cur<<1)|1;
        if(left == -1){
            return;
        }
        if(right == -1){
            if(root[left].value < root[cur].value){
                swap(root[left],root[cur]);
            }
            down_Heapify(left);
            return;
        }
        if(root[left].value < root[right].value){
            if(root[left].value < root[cur].value){
                swap(root[left],root[cur]);
            }
            down_Heapify(left);
        }
        else{
            if(root[right].value < root[cur].value){
                swap(root[right],root[cur]);
            }
            down_Heapify(right);
        }
    }
    public:
    min_Heap(int _Max_Size):max_size(_Max_Size),size(0){
        root = new node[max_size];
    }
    ~min_Heap(){
        delete[] root;
    }
    void push(T __value){
        if(size == max_size){
            cout<<"Heap is full"<<endl;
            throw "Heap is full";
        }

        root[size] = node(__value);
        up_Heapify(size);
        size++;
    }
    void pop(){
        if(size == 0){
            cout<<"Heap is empty"<<endl;
            throw "Heap is empty";
        }
        root[0] = root[size-1];
        size--;
        down_Heapify(0);
    }
    T top(){
        if(size == 0){
            cout<<"Heap is empty"<<endl;
            throw "Heap is empty";
        }
        return root[0].value;
    }
    bool empty(){
        return size == 0;
    }
    friend ostream& operator<<(ostream& os, const min_Heap& h){
        for (int i = 0; i < h.size; ++i)
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
//     max_Heap<int> h(n);
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