

#ifndef BCD64_HPP
#include<string>
#include<iostream>
using std::cout;
using std::hex;
using std::ostream;
using std::string;
#define endl "\n"

class bcd64 {
    unsigned long long value;
public:
    bcd64(): value(0) {}
    bcd64(string __string) : value(0) {
        if(__string.size() > 16) {
            cout<<"bcd64 string too long"<<endl;
            throw "bcd64 string too long";
        }
        for(auto c : __string) {
            value <<= 4;
            value |= (c - '0');
        }
    }
    bcd64(unsigned long long __value) : value(__value) {}
    bcd64 FA(bcd64 &b, unsigned long long &carry) { // Full Adder
        unsigned long long result = 0;
        unsigned long long mask = 0xf;// 1111
        unsigned long long tmp_A = value;
        unsigned long long tmp_C = b.value;
        for(int i = 0; i < 16; ++i) {
            unsigned long long a = tmp_A& mask;
            unsigned long long c = tmp_C& mask;
            unsigned long long sum = a + c + carry;
            if(sum >= 10) {
                carry = 1;
                sum += 6;
            } else {
                carry = 0;
            }
            result |= (sum & mask) << (i * 4);
            // cout<<result<<endl;
            tmp_A >>= 4;
            tmp_C >>= 4;
        }
        return bcd64(result);
    }
    bcd64 FM(bcd64 &b, unsigned long long &borrow) { // Full Minus
        unsigned long long result = 0;
        unsigned long long mask = 0xf;// 1111
        unsigned long long tmp_A = value;
        unsigned long long tmp_C = b.value;
        for(int i = 0; i < 16; ++i) {
            unsigned long long a = tmp_A& mask;
            unsigned long long c = tmp_C& mask;
            if(a<c+borrow){
                a += 10-borrow;
                borrow = 1;
            }
            else{
                a -= borrow;
                borrow = 0;
            }
            unsigned long long diff = a - c;
            result |= (diff & mask) << (i * 4);
            // cout<<result<<endl;
            tmp_A >>= 4;
            tmp_C >>= 4;
        }
        return bcd64(result);
    }

    bool operator<(const bcd64& b) {
        return value < b.value;
    }
    bcd64 operator+(const bcd64& b) {
        unsigned long long carry = 0;
        unsigned long long result = 0;
        unsigned long long mask = 0xf;// 1111
        for(int i = 0; i < 16; ++i) {
            unsigned long long a = (value >> (i * 4)) & mask;
            unsigned long long c = (b.value >> (i * 4)) & mask;
            unsigned long long sum = a + c + carry;
            if(sum >= 10) {
                carry = 1;
                sum += 6;
            } else {
                carry = 0;
            }
            result |= (sum & mask) << (i * 4);
            // cout<<result<<endl;

        }
        return bcd64(result);
    }
    bcd64 operator-(const bcd64& b) {
        if(*this < b) {
            cout<<"bcd64 underflow"<<endl;
            throw "bcd64 underflow";
        }
        unsigned long long borrow = 0;
        unsigned long long result = 0;
        unsigned long long mask = 0xf;// 1111
        unsigned long long temp_V = value;
        unsigned long long temp_bV = b.value;
        for(int i = 0; i < 16; ++i) {
            unsigned long long a = temp_V&mask;
            unsigned long long c = temp_bV&mask;
            if(a<c+borrow){
                a += 10-borrow;
                borrow = 1;
            }
            else{
                a -= borrow;
                borrow = 0;
            }
            unsigned long long diff = a - c;
            result |= (diff & mask) << (i * 4);
            // cout<<result<<endl;
            temp_V >>= 4;
            temp_bV >>= 4;
        }
        return bcd64(result);

    }
    bool operator==(const bcd64& b) {
        return value == b.value;
    }
    bool operator!=(const bcd64& b) {
        return value!= b.value;
    }
    string to_string(bool leading_zero = true) {
        // BCD64 to string
        string result;
        unsigned long long mask = 0xf;
        for(int i = 15; i >-1; --i) {
            unsigned long long a = (value >> (i * 4)) & mask;
            if(leading_zero && a == 0) {
                continue;
            }
            leading_zero = false;
            result += (a + '0');
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const bcd64& b) {
        os <<hex << b.value;
        return os;
    }

};
// int main() {
//     bcd64 a("45");
//     bcd64 b("5");
//     bcd64 c("1234567890123456");
//     // cout << b << endl;
//     // cout << a + b << endl;
//     // cout << c - b << endl;
//     // cout << c.to_string() << endl;
//     return 0;
// }

#endif