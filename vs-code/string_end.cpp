#include<iostream>
using namespace std;

int main()
{
    char p[] = "penguin";
    cout << p << "\n";
    cout << (int) p[7]<< "\n";
    string test = "penguin";
    cout << test << "\n";
    cout << (int) *test.end() << "\n";
}