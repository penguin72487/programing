#include <iostream>

using namespace std;
class node{
public:

    char val;
    node* l=nullptr;
    node* r=nullptr;
    node()
    {

    }
    node(char tmp)
    {
        val=tmp;
    }
};
class math{
public:

    node* root=nullptr;
    math()
    {

    }
    ~math()
    {
        detree(root);


    }
    void detree(node* op)
    {
        if(!op)
        {
            return;
        }
        detree(op->l);
        node* tmp = op->r;
        delete op;
        detree(tmp);
    }

    void insert(char tmp)
    {
        if(!root)
        {
            root->val=tmp;
        }
        else
        {
            node* node_tmp= new node(tmp);

        }
    }

};
int main()
{
    math a;
    string s;
    cin>>s;
    for(auto it=s.begin();it!=s.end();++it)
    {
        if(*it=='('||*it==')')
        {
            s.erase(it);
        }
    }
    for(auto it=s.begin();it!=s.end();++it)
    {
        a.insert(*it);
    }
    return 0;
}
