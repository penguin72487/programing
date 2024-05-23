

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
    bcd64(string &__string) : value(0) {
        if(__string.size() > 16) {
            cout<<"bcd64 string too long"<<endl;
            throw "bcd64 string too long";
        }
        for(auto c : __string) {
            value <<= 4;
            // value |= (c - '0');
            value |= c ^ 48;
        }
    }
    bcd64(unsigned long long __value): value(__value) {}

    bcd64 FA(bcd64 &b, unsigned long long &carry) {
        unsigned long long result = 0;
        unsigned long long mask = 0xf;  // 1111
        unsigned long long tmp_A = value;
        unsigned long long tmp_C = b.value;
        for (int i = 0; i < 16; ++i) {
            unsigned long long a = tmp_A & mask;
            unsigned long long c = tmp_C & mask;
            unsigned long long sum = a + c + carry;
            carry = (sum > 9) ? 1 : 0;
            result |= ((sum + ((carry <<2)+(carry<<1))) & mask) << (i <<2);
            tmp_A >>= 4;
            tmp_C >>= 4;
        }
        return bcd64(result);
    }

    bcd64 FM(bcd64 &b, unsigned long long &borrow) {
        unsigned long long result = 0;
        unsigned long long mask = 0xf;  // 1111
        unsigned long long tmp_A = value;
        unsigned long long tmp_C = b.value;
        for(int i = 0; i < 16; ++i) {
            unsigned long long a = tmp_A & mask;
            unsigned long long c = tmp_C & mask;
            unsigned long long diff = a - c - borrow;
            if (diff > a) {  // This means there was a borrow
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result |= (diff & mask) << (i <<2);
            tmp_A >>= 4;
            tmp_C >>= 4;
        }
        return bcd64(result);
    }


    bool operator<(const bcd64& b) {
        return value < b.value;
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
            unsigned long long a = (value >> (i <<2)) & mask;
            if(leading_zero && a == 0) {
                continue;
            }
            leading_zero = false;
            result += a^48;
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