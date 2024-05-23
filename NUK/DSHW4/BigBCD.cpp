#include "BCD64.hpp"
#include<string>
#include<iostream>
#include<iomanip>
#ifdef ENABLE_TIMING
    #include <chrono>
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();
    auto diff = duration_cast<nanoseconds>(end - start);
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

    class BigBCD
    {
        class node
        {
        public:
        bcd64 value;
        node* next;
        node(bcd64 __value):value(__value),next(nullptr){}
        bcd64 FA(bcd64 &b, unsigned long long &carry) { // Full Adder
            return value.FA(b, carry);
        }
        bcd64 FM(bcd64 &b, unsigned long long &borrow) { // Full Minus
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
    void push_back(node* &__value){
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
        head = nullptr;
        tail = nullptr;
    }
    BigBCD(string &__string): head(nullptr),tail(nullptr){

        while(__string.length()>15)
        {
            int n = __string.length();
            string tmp = "0000000000000000";
            for(int i=0;i<16;i++)
            {
                tmp[i]=__string[n-16+i];
            }
            for(int i=0;i<16;i++)
            {
                __string.pop_back();
            }
            push_back(bcd64(tmp));
            
        }
        push_back(bcd64(__string));


    }
    BigBCD operator+(const BigBCD& b) const{
        BigBCD c;
        node* cur = head;
        node* rhs = b.head;
        unsigned long long carry = 0;
        bcd64 zero = bcd64(0);
        while(cur!= nullptr && rhs!= nullptr){
            c.push_back(cur->value.FA(rhs->value, carry));
            cur = cur->next;
            rhs = rhs->next;
            // cout<<c<<endl;
        }
        while(cur!= nullptr){
            c.push_back(cur->value.FA(zero, carry));
            cur = cur->next;
        }
        while(rhs!= nullptr){
            c.push_back(rhs->value.FA(zero, carry));
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
        bcd64 zero = bcd64(0);
        while(cur!= nullptr && rhs!= nullptr){
            c.push_back(cur->value.FM(rhs->value, borrow));
            cur = cur->next;
            rhs = rhs->next;
        }
        while(cur!= nullptr){
            c.push_back(cur->value.FM(zero, borrow));
            cur = cur->next;
        }
        while(rhs!= nullptr){
            c.push_back(rhs->value.FM(zero, borrow));
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
        this->~BigBCD();
        node* src_node = b.head;
        while (src_node != nullptr) {
            push_back(src_node->value);
            src_node = src_node->next;
        }
        return *this;
    }
    void erase_Zero(){
        if(tail->value == bcd64(0)){
            pop_back();
        }
        return;
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
            res += cur->value.to_string(0);
            cur = cur->next;
        }
        res += b.tail->value.to_string();
        int n = res.length();        
        int less = n%16;
        int t=n>>4;
        if(less!= 0){
            for (int i = 0; i < less;++i)
            {
                os << res[(t<<4)+i];
            }
        }
        for (int i = t-1; i>-1; --i)
        {
            for (int j = 0; j < 16; ++j)
            {
                os << res[(i<<4)+j];
            }
            // os << " ";
        }
        
        // os << res;


        return os;
    }
};
int main(){
    // BigBCD a("12345678901234567");
    // cout<<a<<endl;

    freopen("ex-in.txt", "r", stdin);
    freopen("ex-out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string a;
    string sig;
    string b;
    cin >> a;
    #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
    #endif
    BigBCD res(a);
    #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<microseconds>(end - start);
                cout << "\n BCD encode Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
    #endif
    while(cin >> sig >> b){
        if(b=="STOP"||sig == "STOP"){
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif
            cout << res << endl;
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<microseconds>(end - start);
                cout << "\n BCD output Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
            #endif
            break;
        }
        if(sig == "+"){
            BigBCD B(b);
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif

            res = res + B;
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<microseconds>(end - start);
                cout << "\n BCD Add Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
            #endif
        }else if(sig == "-"){
            res = res - BigBCD(b);
        }else if (sig == "="){
            #ifdef ENABLE_TIMING
                start = high_resolution_clock::now();
            #endif
            cout << res << endl;
            #ifdef ENABLE_TIMING
                end = high_resolution_clock::now();
                diff = duration_cast<microseconds>(end - start);
                cout << "\n BCD output Total time taken: " << double (diff.count())/1000000.0 << " ms.\n";
            #endif
            res = BigBCD(b);
            
        }

    }

    return 0;
}