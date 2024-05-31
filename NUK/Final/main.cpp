#include "Heap.hpp"
#include "linklist.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#define endl "\n"
class k_Bar : public heap_Value {
    int Date;
    float open;
    float High;
    float Low;
    float close;
public:
    k_Bar() : Date(0), open(0), High(0), Low(0), close(0) {}
    k_Bar(int _Date, float _open, float _High, float _Low, float _close) : Date(_Date), open(_open), High(_High), Low(_Low), close(_close) {}
    heap_Value& operator=(const heap_Value& other) override {
        if (this != &other) {
            const k_Bar& k = dynamic_cast<const k_Bar&>(other);
            Date = k.Date;
            open = k.open;
            High = k.High;
            Low = k.Low;
            close = k.close;
        }
        return *this;
    }
    bool operator<(const heap_Value& b) const override {
        const k_Bar& k = dynamic_cast<const k_Bar&>(b);
        if(close < k.close) return true;
        else if(close == k.close) return Date < k.Date;
        else return false;
    }
    bool operator>(const heap_Value& b) const override {
        const k_Bar& k = dynamic_cast<const k_Bar&>(b);
        if(close > k.close) return true;
        else if(close == k.close) return Date > k.Date;
        else return false;
    }
    friend ostream& operator<<(ostream& os, const k_Bar& k) {
        os << k.Date << " " << k.open << " " << k.High << " " << k.Low << " " << k.close;
        return os;
    }
};

int main() {
    //////////////////////////////////////////////////////////////////////////////////////input
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    linklist<k_Bar> k_line;
    
    ifstream file("datasets/problem1/TWII_withRepeatedData.csv");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    
    string header;
    getline(file, header); // 讀取並忽略表頭行
    
    string line;
    int size = 0;
    while (getline(file, line)) {
        stringstream ss(line);
        string item;
        char trash;
        int Date;
        float open, High, Low, close;
        ss >> Date >> trash >> open >> trash >> High >> trash >> Low >> trash >> close;

        k_line.push_back(k_Bar(Date, open, High, Low, close));
        size++;
    }

    file.close();
    cout << size << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////


    max_Heap<k_Bar> k_Heap(size);
    for(auto& it:k_line){
        k_Heap.push(it);
    }
    cout<<k_Heap.top()<<endl;
    cout<<endl;
    k_Heap.sort();
    // int n=k_Heap.size();
    for(int i=0;i<10;i++){// small K
        cout<<k_Heap[i]<<endl;
    }
    cout<<endl;
    for(int i=size-10;i<size;i++){// large K
        cout<<k_Heap[i]<<endl;
    }
    cout<<endl;

    return 0;
}
