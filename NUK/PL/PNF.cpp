#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

bool id(string s) {
    if (s.size() == 1 && (s[0] == 'A' || s[0] == 'B' || s[0] == 'C' || s[0] == 'D')) {
        return true;
    }
    return false;
}

bool expr(string s);
bool term(string s);
bool factor(string s);

bool expr(string s) {
    if (id(s)) {
        return true;
    }
    if(s.length() == 0) {
        return false;
    }
    string expr_S = "";
    string tern_S = "";
    bool result = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            expr_S = s.substr(0, i);
            tern_S = s.substr(i + 1);
            result |= expr(expr_S) && term(tern_S);
        }
    }
    return result;
}

bool term(string s) {
    if (factor(s)) {
        return true;
    }
    if(s.length() == 0) {
        return false;
    }

    string term_S = "";
    string factor_S = "";
    bool result = false;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*' || s[i] == '/') {
            term_S = s.substr(0, i);
            factor_S = s.substr(i + 1);
            result |= term(term_S) && factor(factor_S);
        }
    }
    return result;
}

bool factor(string s) {
    if (id(s)) {
        return true;
    }
    if(s.length() == 0) {
        return false;
    }
    if (s[0] != '(') {
        return false;
    }
    string expr_S = "";
    bool result = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == ')') {
            expr_S = s.substr(1, i - 1);
            result |= expr(expr_S);
        }
    }
    return result;
}

bool assign(string s) {
    string id_S = "";
    string expr_S = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '=') {
            id_S = s.substr(0, i);
            expr_S = s.substr(i + 1);
            break;
        }
    }
    return id(id_S) && expr(expr_S);
}

int main() {
    string statements[] = {
        "A=B - C / A - A",
        "A=B*C/D-A",
        "A=B / (C-A)",
        "A=B - (C*A)",
        "A=B * (D-A)"
    };
    
    // Remove spaces
    for (string& stmt : statements) {
        stmt.erase(std::remove_if(stmt.begin(), stmt.end(), ::isspace), stmt.end());
    }

    for (string stmt : statements) {
        cout << stmt;
        cout << (assign(stmt) ? " True" : " False") << endl;
    }

    return 0;
}
