#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> s;
vector<int> t;

void checkFlag() {

    bool yoyo = false;

    for(int i = 0; i < s.size() - 1; i++) {

        for(int j = 0; j < s.size() - i - 1; j++) {

            if(t[j] > s[j+1] && s[j+1] > s[j]) {

                int tempS1 = s[j];
                int tempT1 = t[j];
                int tempS2 = s[j+1];
                int tempT2 = t[j+1];

                s.erase(std::find(s.begin(),s.end(),tempS1));
                s.erase(std::find(s.begin(),s.end(),tempS2));
                t.erase(std::find(t.begin(),t.end(),tempT1));
                t.erase(std::find(t.begin(),t.end(),tempT2));

                int a = min(tempS1, tempS2);
                int b = max(tempS1, tempS2);
                int c = min(tempT1, tempT2);
                int d = max(tempT1, tempT2);

                s.push_back(a);
                t.push_back(b);
                s.push_back(c);
                t.push_back(d);
                
                yoyo = true;
                break;

            }

        }

        if(yoyo == true) {

            break;

        }

    }

    if(yoyo == true) {

        // sort
        for(int i = 0; i < s.size() - 1; i++) {

            for(int j = 0; j < s.size() - i - 1; j++) {

                if(s[j] > s[j+1]) {

                    int temp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = temp;

                    temp = t[j];
                    t[j] = t[j+1];
                    t[j+1] = temp;

                }

            }

        }

        checkFlag();

    }

}

int main() {

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {

        int a, b;
        cin >> a >> b;

        s.push_back(a);
        t.push_back(b);

    }

    // sort
    for(int i = 0; i < s.size() - 1; i++) {

        for(int j = 0; j < s.size() - i - 1; j++) {

            if(s[j] > s[j+1]) {

                int temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;

                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;

            }

        }

    }

    checkFlag();

    // sort
    for(int i = 0; i < s.size() - 1; i++) {

        for(int j = 0; j < s.size() - i - 1; j++) {

            if(s[j] > s[j+1]) {

                int temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;

                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;

            }

        }

    }

    // print
    for(int i = 0; i < s.size(); i++) {

        cout << s[i] << " " << t[i];

        if(i != s.size() - 1) {

            cout << endl;

        }

    }

    return 0;
}