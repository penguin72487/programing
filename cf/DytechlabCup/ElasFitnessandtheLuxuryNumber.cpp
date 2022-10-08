#include<iostream>
using namespace std;
float q_sqrt(unsigned long long x) { 
	if(x == 0) return 0; 
	float result = x; 
	float xhalf = 0.5f*result; 
	int i = *(int*)&result; 
	i = 0x5f375a86- (i>>1); // what the fuck? 
	result = *(float*)&i; 
	result = result*(1.5f-xhalf*result*result); // Newton step, repeating increases accuracy 
	result = result*(1.5f-xhalf*result*result); 
	return 1.0f/result; 
}
bool luxurious(long long x) {
    int q=q_sqrt(x); 
    if(x%q==0)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long l, r;
        cin >> l>>r;
        for (int i = l;i<r; i++)
        {
            cout << luxurious(i) << " ";
        }
    }


    return 0;
}