#include<iostream>
#define endl "\n"
using namespace std;
template<class T>
class queue{
public:
    class node{
        public:
        T val;
        node* nex_N;
        node(T c_V)
        {
            val = c_V;
            nex_N = NULL;
        }
        node()
        {
            nex_N = NULL;
        }
    };
    int n;
    node *top_P;
    node *end_P;
    queue()
    {
        top_P = NULL;
        end_P = NULL;
        n = 0;
    }
    void push(T v_in){
        node* now = new node(v_in);
        end_P->nex_N = now;
        end_P = end_P->nex_N;
        ++n;
    }
    void pop(){
        if(empty())
        {
            return;
        }
        node *t = top_P;
        top_P = top_P->nex_N;
        delete t;
        --n;
    }
    T top()
    {
        return top_P->val;
    }
    bool empty()
    {
        return (n == 0);
    }
    void clear()
    {
        while(top_P)
        {
            pop();
        }
        n = 0;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    while(cin>>t&&t!=0){
        int n;
        cin >> n;
        

        
    }
}
