#include<bits/stdc++.h>
using namespace std;

class linklist{

class node{
    public:
    int v;
    node *next=nullptr;
    node(){
    }
    node(int v){
        this->v = v;
    }
};
public:
    int size=0;
    node *head = nullptr;
    node *end=nullptr;
    // linklist(int n) :n(n){
        
    // }
    void push_back(int a){
        if(size==0)
        {
            ++size;
            head = new node(a);
            end =head;
        }
        else {
            ++size;
            end->next = new node(a);
            end = end->next;
        }
    }
    void erase(int index){
        node *now=head;
        for (int i = 0; i < index;++i)
        {
            now = now->next;
        }
        if(index==0)
        {
            node* tmp = head->next;
            delete head;
            head = tmp;
        }
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    linklist a;
    a.push_back(1);
    a.push_back(2);

    return 0;
}