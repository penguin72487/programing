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
    string name;
    float exercisePrice;
    int expirationDate;// month
    char callPut;// C or P
    float transactionTime;
    float transactionPrice;
    float transactionVolume;
    float openingAuctionPrice;

public:
    k_Bar() : Date(0), name(""), exercisePrice(0), expirationDate(0), callPut(' '), transactionTime(0), transactionPrice(0), transactionVolume(0), openingAuctionPrice(0) {}
    k_Bar(int _Date, string _name,  float _exercisePrice, int _expirationDate, char _callPut, float _transactionTime, float _transactionPrice, float _transactionVolume, float _openingAuctionPrice) : Date(_Date), name(_name), exercisePrice(_exercisePrice), expirationDate(_expirationDate), callPut(_callPut), transactionTime(_transactionTime), transactionPrice(_transactionPrice), transactionVolume(_transactionVolume), openingAuctionPrice(_openingAuctionPrice) {}
    heap_Value& operator=(const heap_Value& other) override {
        if (this != &other) {
            const k_Bar& k = dynamic_cast<const k_Bar&>(other);
            Date = k.Date;
            name = k.name;
            exercisePrice = k.exercisePrice;
            expirationDate = k.expirationDate;
            callPut = k.callPut;
            transactionTime = k.transactionTime;
            transactionPrice = k.transactionPrice;
            transactionVolume = k.transactionVolume;
            openingAuctionPrice = k.openingAuctionPrice;
        }
        return *this;
    }
    bool operator<(const heap_Value& b) const override {
        const k_Bar& k = dynamic_cast<const k_Bar&>(b);
        if(transactionPrice < k.transactionPrice) return true;
        else if(transactionPrice == k.transactionPrice) return Date < k.Date;
        else return false;
    }
    bool operator>(const heap_Value& b) const override {
        const k_Bar& k = dynamic_cast<const k_Bar&>(b);
        if(transactionPrice > k.transactionPrice) return true;
        else if(transactionPrice == k.transactionPrice) return Date > k.Date;
        else return false;
    }
    friend ostream& operator<<(ostream& os, const k_Bar& k) {
        os << k.Date << " " << k.name << " " << k.exercisePrice << " " << k.expirationDate << " " << k.callPut << " " << k.transactionTime << " " << k.transactionPrice << " " << k.transactionVolume << " " << k.openingAuctionPrice;
        return os;
    }
};
void option_Input(ifstream &file,linklist<k_Bar> &TXO_1000_201706_P,
    linklist<k_Bar> &TXO_9500_201706_C,
    linklist<k_Bar> &GIO_5500_201706_C,
    linklist<k_Bar> &TXO_9900_201705_C, int &size)
    {
        string header;
        getline(file, header); // 讀取並忽略表頭行
        getline(file, header); // 讀取並忽略表頭行
        string line;
        while(getline(file, line)){
            stringstream ss(line);
            string item;
            char trash;
            int Date;
            string name;
            float exercisePrice;
            int expirationDate;// month
            char callPut;// C or P
            float transactionTime;
            float transactionPrice;
            float transactionVolume;
            float openingAuctionPrice;
            ss >> Date >> trash >> name >> trash >> exercisePrice >> trash >> expirationDate >> trash >> callPut >> trash >> transactionTime >> trash >> transactionPrice >> trash >> transactionVolume >> trash >> openingAuctionPrice;
            if(name== "TXO" && exercisePrice==1000 && expirationDate==201706 && callPut=='P'){
                TXO_1000_201706_P.push_back(k_Bar(Date, name, exercisePrice, expirationDate, callPut, transactionTime, transactionPrice, transactionVolume, openingAuctionPrice));
            }
            else if(name=="TXO" && exercisePrice==9500 && expirationDate==201706 && callPut=='C'){
                TXO_9500_201706_C.push_back(k_Bar(Date, name, exercisePrice, expirationDate, callPut, transactionTime, transactionPrice, transactionVolume, openingAuctionPrice));
            }
            else if(name=="GIO" && exercisePrice==5500 && expirationDate==201706 && callPut=='C'){
                GIO_5500_201706_C.push_back(k_Bar(Date, name, exercisePrice, expirationDate, callPut, transactionTime, transactionPrice, transactionVolume, openingAuctionPrice));
            }
            else if(name=="TXO" && exercisePrice==9900 && expirationDate==201705 && callPut=='C'){
                TXO_9900_201705_C.push_back(k_Bar(Date, name, exercisePrice, expirationDate, callPut, transactionTime, transactionPrice, transactionVolume, openingAuctionPrice));
            }
            size++;
        }
    }

int main() {
    //////////////////////////////////////////////////////////////////////////////////////input
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    linklist<k_Bar> TXO_1000_201706_P;
    linklist<k_Bar> TXO_9500_201706_C;
    linklist<k_Bar> GIO_5500_201706_C;
    linklist<k_Bar> TXO_9900_201705_C;

    ////2017_05_15
    ifstream file("datasets\\problem2\\OptionsDaily_2017_05_15.csv");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    int size=0;
    option_Input(file, TXO_1000_201706_P, TXO_9500_201706_C, GIO_5500_201706_C, TXO_9900_201705_C, size);
    file.close();
    ////2017_05_16
    file.open("datasets\\problem2\\OptionsDaily_2017_05_16.csv");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    option_Input(file, TXO_1000_201706_P, TXO_9500_201706_C, GIO_5500_201706_C, TXO_9900_201705_C, size);
    file.close();
    ////2017_05_17
    file.open("datasets\\problem2\\OptionsDaily_2017_05_17.csv");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    option_Input(file, TXO_1000_201706_P, TXO_9500_201706_C, GIO_5500_201706_C, TXO_9900_201705_C, size);
    file.close();
    ////2017_05_18
    file.open("datasets\\problem2\\OptionsDaily_2017_05_18.csv");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    option_Input(file, TXO_1000_201706_P, TXO_9500_201706_C, GIO_5500_201706_C, TXO_9900_201705_C, size);
    file.close();
    ////2017_05_19
    file.open("datasets\\problem2\\OptionsDaily_2017_05_19.csv");
    if (!file.is_open()) {
        cerr << "Unable to open file" << endl;
        return 1;
    }
    option_Input(file, TXO_1000_201706_P, TXO_9500_201706_C, GIO_5500_201706_C, TXO_9900_201705_C, size);
    file.close();

    ////////////////////////////////////////////////////////////////////////////////////////////

    size = TXO_9900_201705_C.size();
    Heap<k_Bar> k_Heap(size);
    for(auto& it:TXO_9900_201705_C){
        k_Heap.push(it);
    }
    cout<<k_Heap.top()<<endl;
    cout<<endl;
    k_Heap.sort();
    // int n=k_Heap.size();
    cout<<"small K"<<endl;
    for(int i=0;i<10;i++){// small K
        cout<<k_Heap[i]<<endl;
    }
    cout<<endl;
    cout<<"large K"<<endl;
    for(int i=size-10;i<size;i++){// large K
        cout<<k_Heap[i]<<endl;
    }
    cout<<endl;

    return 0;
}
