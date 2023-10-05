#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    queue <int> time;
    for(int i=0;i<n;i++)
    {
        int tmp;
        cin>>tmp;
        time.push(tmp);
        while(tmp-time.front()>3000)
        {
            time.pop();
        }
        cout<<time.size()<<endl;
    }

}
