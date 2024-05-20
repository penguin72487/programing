#include "BCD64.cpp"
#include<string>
#include<iostream>
#include<iomanip>
#ifdef ENABLE_TIMING
    #include <chrono>
#endif
using std::cin;
using std::cout;
using std::hex;
using std::ostream;
using std::string;
using std::to_string;
using std::setfill;
using std::setw;
#define endl "\n"


class BigBCD{
    class node{
        public:
        bcd64 value;
        node* next;
        node(bcd64 __value):value(__value),next(nullptr){}
        bcd64 FA(bcd64 b, unsigned long long &carry) { // Full Adder
            return value.FA(b, carry);
        }
        bcd64 FM(bcd64 b, unsigned long long &borrow) { // Full Minus
            return value.FM(b, borrow);
        }        
    };

    node* head;
    node* tail;
    void push_back(bcd64 __value){
        node* cur = new node(__value);
        if(head == nullptr){
            head = cur;
            tail = cur;
        }else{
            tail->next = cur;
            tail = cur;
        }
    }
    void push_back(node* __value){
        if(head == nullptr){
            head = __value;
            tail = __value;
        }else{
            tail->next = __value;
            tail = __value;
        }
    }
    void pop_back(){
        if(head == nullptr)
            throw "pop from empty BigBCD";
        if(head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        node* cur = head;
        while(cur->next!= tail){
            cur = cur->next;
        }
        delete tail;
        tail = cur;
        tail->next = nullptr;
        
        
        return;
    }
    public:
    BigBCD():head(nullptr),tail(nullptr){}
    ~BigBCD(){
        node* cur = head;
        while(cur!= nullptr){
            node* next = cur->next;
            delete cur;
            cur = next;
        }
    }
    BigBCD(string __string): head(nullptr),tail(nullptr){
        int n = __string.size();
        for(int i = n-16; i >-16; i-=16){
            string tmp;
            if(i < 0){
                // i = 0;
                tmp=__string.substr(0,16+i);
                goto add;
            }
            tmp = __string.substr(i,16);
            // bcd64 value(tmp);
            add:
            node *cur = new node(bcd64(tmp));
            if(head == nullptr){
                head = cur;
                tail = cur;
            }else{
                tail->next = cur;
                tail = cur;
            }
        }

    }
    BigBCD operator+(const BigBCD& b) const{
        BigBCD c;
        node* cur = head;
        node* rhs = b.head;
        unsigned long long carry = 0;
        while(cur!= nullptr && rhs!= nullptr){
            c.push_back(cur->value.FA(rhs->value, carry));
            cur = cur->next;
            rhs = rhs->next;
            // cout<<c<<endl;
        }
        while(cur!= nullptr){
            c.push_back(cur->value.FA(bcd64(0), carry));
            cur = cur->next;
        }
        while(rhs!= nullptr){
            c.push_back(rhs->value.FA(bcd64(0), carry));
            rhs = rhs->next;
        }
        if(carry){
            c.push_back(bcd64(1));
        }
        return c;
    }

    BigBCD operator-(const BigBCD& b) const{
        BigBCD c;
        node* cur = head;
        node* rhs = b.head;
        unsigned long long borrow = 0;
        while(cur!= nullptr && rhs!= nullptr){
            c.push_back(cur->value.FM(rhs->value, borrow));
            cur = cur->next;
            rhs = rhs->next;
        }
        while(cur!= nullptr){
            c.push_back(cur->value.FM(bcd64(0), borrow));
            cur = cur->next;
        }
        while(rhs!= nullptr){
            c.push_back(rhs->value.FM(bcd64(0), borrow));
            rhs = rhs->next;
        }
        if(borrow){
            c.push_back(bcd64(10));
        }
        c.erase_Zero();
        return c;
    }
    BigBCD& operator=(const BigBCD& b) {
        if (this == &b) {
            // Check for self-assignment
            return *this;
        }

        // Clear the current list
        node* cur = head;
        while (cur != nullptr) {
            node* next = cur->next;
            delete cur;
            cur = next;
        }
        head = nullptr;
        tail = nullptr;

        // Copy the list from the source object
        node* src_node = b.head;
        while (src_node != nullptr) {
            push_back(src_node->value);
            src_node = src_node->next;
        }

        return *this;
    }
    void erase_Zero(){
        erase_Zero(head);
    }
    void erase_Zero(node* cur){
        if(cur == nullptr){
            return;
        }
        erase_Zero(cur->next);
        if(cur == head){
            return;
        }
        if(cur->value == bcd64(0)){
           pop_back();
        }
    }

    bool operator==(const BigBCD& b) const{
        node* cur = head;
        node* rhs = b.head;
        while(cur!= nullptr && rhs!= nullptr){
            if(cur->value!= rhs->value)
                return false;
            cur = cur->next;
            rhs = rhs->next;
        }
        if(cur!= nullptr || rhs!= nullptr)
            return false;
        return true;
    }

    // void print(node* cur) const {
    //     if(cur == nullptr){
    //         return;
    //     }
    //     print(cur->next);
    //     if(cur==tail){
    //         cout << cur->value;
    //     }
    //     else
    //     {
    //         cout<<setfill('0')<<setw(16)<<cur->value;
    //     }
               
    // }
    friend ostream& operator<<(ostream& os, const BigBCD& b){
        string res;
        node *cur = b.head;
        while(cur!= b.tail){
            res = cur->value.to_string(0) + res;
            cur = cur->next;
        }
        res = cur->value.to_string() + res;
        
        os << res;


        return os;
    }
};
int main(){
    // BigBCD a("12345678901234567");
    // cout<<a<<endl;

    freopen("ex-in.txt", "r", stdin);
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string a;
    string sig;
    string b;
    cin >> a;
    BigBCD res(a);
    while(cin >> sig >> b){
        if(b=="STOP"||sig == "STOP"){
            cout << res << endl;
            break;
        }
        if(sig == "+"){
            #ifdef ENABLE_TIMING
                #include <chrono>
                using namespace std::chrono;
                auto start = high_resolution_clock::now();
            #endif
            res = res + BigBCD(b);
            #ifdef ENABLE_TIMING
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(stop - start);
                cout << "\nTotal time taken: " << double (duration.count())/1000000.0 << " ms.\n";
            #endif
        }else if(sig == "-"){
            res = res - BigBCD(b);
        }else if (sig == "="){
            cout << res << endl;
            res = BigBCD(b);
        }

    }

    return 0;
}