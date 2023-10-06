#include <iostream>
using namespace std;

inline int ans(int n, int numbers[]) {
    int diffCount = 0;
    for (int i=0; i<n-1; i++) {
        if (numbers[i] != numbers[i+1]) {
            diffCount++;
        }
    }
    return diffCount;
}

inline void readNumbers(int n, int numbers[]) {
    for (int i=0; i<n; i++) {
        cin >> numbers[i];
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    if (n==1) {
        int trash;
        cin >> trash;
        cout << "0" << endl;
        return 0;
    } else if (n==2) {
        int a, b;
        cin >> a >> b;
        cout << (a==b ? "0" : "1") << endl;
        return 0;
    }
    
    int numbers[n];
    readNumbers(n, numbers);
    
    int leftIndex = n%2 ? n/2 : n/2-1, rightIndex = n%2 ? n/2+1 : n/2;
    for (int i=0; i<k; i++) {
        do {
            leftIndex--;
        } while (leftIndex > -1 and numbers[leftIndex] != numbers[leftIndex+1]);
        do {
            rightIndex++;
        } while (rightIndex < n-1 and numbers[rightIndex] != numbers[rightIndex-1]);
        
        if (leftIndex >= 0 and rightIndex < n and numbers[leftIndex] != numbers[rightIndex]) {
            int temp = numbers[leftIndex];
            numbers[leftIndex] = numbers[rightIndex]; numbers[rightIndex] = temp;
        } else if (leftIndex >= 0 and rightIndex < n) {
            leftIndex += 2;
            int temp = numbers[leftIndex];
            numbers[leftIndex] = numbers[rightIndex]; numbers[rightIndex] = temp;
        } else {
            break;
        }
        //cout << leftIndex << " " << rightIndex << endl;
    }
    cout << ans(n, numbers) << endl;
    return 0;
}