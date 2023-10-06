#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
        long long index, pri;
        long long val, sum;
        node *l, *r;
        node(long long k, long long v) : index(k), pri(rand()), val(v), sum(v), l(nullptr), r(nullptr){
 
        }
        node(node* t): index(t->index), pri(t->pri), val(t->val), sum(t->sum), l(t->l), r(t->r){
 
        }
};
int main()
{
    //unique_ptr
    //shared_ptr
    //weak_ptr
    
    return 0;
}