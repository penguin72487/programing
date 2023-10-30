#include<bits/stdc++.h>
#include "SalesPerson.h"
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,ection-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#define endl "\n"
using namespace std;

SalesPerson::SalesPerson(){
    for (int i = 0; i < 4; i++)  // 改成 4 個季度
        sales[i] = 0;
    srand(time(0));
    getSalesFromUser();
}

void SalesPerson::getSalesFromUser(){
    for (int i = 1; i <= 4; i++){  // 改成 4 個季度
        //cout << "Enter sales amount for quarter " << i << ": ";  // 改成 quarter
        setSales(i, rand() % 1000 + 1000);
    }
}

void SalesPerson::setSales(int quarter, int amount){  // 改成 int
    if (quarter >= 1 && quarter <= 4 && amount > 0)  // 改成 4 個季度
        sales[quarter - 1] = amount;
    else
        cout << "Invalid quarter or sales figure" << endl;  // 改成 quarter
}

void SalesPerson::printAnnualSales(){
    cout << "\nThe total annual sales are: $"
         << totalAnnualSales() << endl;
}

int SalesPerson::totalAnnualSales(){  // 改成 int
    int total = 0;  // 改成 int
    for (int i = 0; i < 4; i++)  // 改成 4 個季度
        total += sales[i];
    return total;
}
