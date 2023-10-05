#include<bits/stdc++.h>
using namespace std;

const int N = 100000;

int main() {
    ofstream fin("input.txt");
    ofstream fans("answer.txt");

    int n = N, q = 2 * N;
    fin << n << " " << q << "\n";

    // 生成一個從1到N的序列
    for (int i = 1; i <= n; ++i) {
        fin << i << " ";
    }
    fin << "\n";

    // 用暴力方法計算答案
    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        arr[i] = i;
    }

    for (int i = 1; i <= n; ++i) {
        // 查詢整個範圍的和
        long long sum = 0;
        for (int j = 1; j <= n; ++j) {
            sum += arr[j];
        }
        fans << sum << "\n";

        // 在整個範圍內增加i
        for (int j = 1; j <= n; ++j) {
            arr[j] += i;
        }
        fin << "1 1 " << n << " " << i << "\n";
        fin << "2 1 " << n << "\n";
    }

    fin.close();
    fans.close();

    return 0;
}
