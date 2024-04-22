#include<iostream>
#define endl "\n"
using namespace std;
template<class T>
class stack{
public:
    class node{
        public:
        T val;
        node* pre_N;
        node(T c_V)
        {
            val = c_V;
            pre_N = NULL;
        }
        node()
        {
            pre_N = NULL;
        }
    };
    int n;
    node *top_P;
    stack()
    {
        top_P = NULL;
        n = 0;
    }
    void push(T v_in){
        if(v_in=="")
        {
            return;
        }
        node* now = new node(v_in);
        now->pre_N = top_P;
        top_P = now;
        ++n;
    }
    void pop(){
        if(empty())
        {
            return;
        }
        node *t = top_P;
        top_P = top_P->pre_N;
        delete t;
        --n;
    }
    T top()
    {
        if(empty())
        {
            return "";
        }
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
    string op;//operator
    stack<string> st_S,st_F;//stack string st forward
    string cus = "http://www.acm.org/";

    while(cin>>op&&op!="QUIT")
    {
        if(op=="VISIT")
        {
            // if(cus!="")
            st_S.push(cus);
            string surl;
            cin >> surl;
            cout << surl << "\n";
            cus = surl;
            // st_F.clear();
        }
        else if(op=="BACK")
        {
            if(st_S.empty())
            {
                cout << "Ignored\n";
                continue;
            }
            cout << st_S.top() << "\n";
            st_F.push(cus);
            cus = st_S.top();
            st_S.pop();
            
        }
        else if(op=="FORWARD")
        {
            if(st_F.empty())
            {
                cout << "Ignored\n";
                continue;
            }
            cout << st_F.top() << "\n";
            st_S.push(cus);
            cus = st_F.top();
            st_F.pop();

        }
    }

    return 0;
}

/*
VISIT http://acm.ashland.edu/
VISIT http://acm.baylor.edu/acmicpc/
BACK
BACK
BACK
FORWARD
VISIT http://www.ibm.com/
BACK
BACK
FORWARD
FORWARD
FORWARD
QUIT
*/