#include<iostream>
using namespace std;
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    cout << &arr<<" "<<&arr +1 << " " << arr <<" "<<arr+1<< "\n";
    int len = *(&arr + 2) - arr;
    cout << len << "\n";
}