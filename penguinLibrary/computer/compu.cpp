#include<bits/stdc++.h>
using namespace std;

int getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void compute(stack<long long>& sll, stack<char>& sc) {
    long long a = sll.top(); sll.pop();
    long long b = sll.top(); sll.pop();
    char c = sc.top(); sc.pop();
    if (c == '+') {
        sll.push(b + a);
    } else if (c == '-') {
        sll.push(b - a);
    } else if (c == '*') {
        sll.push(b * a);
    } else if (c == '/') {
        sll.push(b / a);
    }
}

int main() {
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        stack<char> sc;
        stack<long long> sll;
        char op;
        long long tmp;
        while (ss) {
            if (ss.peek() == ' ') ss.ignore();
            if (ss.peek() >= '0' && ss.peek() <= '9') {
                ss >> tmp;
                sll.push(tmp);
            } else if (ss.peek() == '+' || ss.peek() == '-' || ss.peek() == '*' || ss.peek() == '/') {
                ss >> op;
                while (!sc.empty() && getPrecedence(sc.top()) >= getPrecedence(op)) {
                    compute(sll, sc);
                }
                sc.push(op);
            } else if (ss.peek() == '(') {
                ss >> op;
                sc.push(op);
            } else if (ss.peek() == ')') {
                ss >> op;
                while (sc.top() != '(') {
                    compute(sll, sc);
                }
                sc.pop(); // pop '('
            }
            ss.ignore();
        }
        while (!sc.empty()&&!sll.empty()) {
            compute(sll, sc);
        }
        if (!sll.empty()) {
            cout << sll.top() << "\n";
        }
    }
    return 0;
}
