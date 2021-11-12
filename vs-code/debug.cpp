#include<iostream>
using namespace std;
int main()
{
    char data[8]="penguin";
    int count = 0;
    for(int i = 0;data[i];i++){
        count++;
    }
    cout << count << "\n";
}