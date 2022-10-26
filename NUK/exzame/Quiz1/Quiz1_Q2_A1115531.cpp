#include <iostream> // cin cout
#include <numeric> // accumulate -> sum of vector
#include <vector> // similar to array but dynamic 
#include <algorithm>// max_element min_element
#include <iomanip> //fixed -> fixed the the decimal point if not whith  setprecision(n) output n digit (totle of before and after the decimal)    setprecision(3) -> the third digit after the decimal point 
using namespace std;
int main(){
    cout.tie(0)->sync_with_stdio(0); // input output aka io optimization
    cin.tie(0);
    int n;
    vector<int> vec;
    

    //cout << "please input a positive integer (0 end) : ";



    while (cin >> n&&n!=0)
    {
        vec.push_back(n); // add element to vector
        //cout << "\nplease input a positive integer (0 end) : ";
    }

    cout << "max = " << *max_element(vec.begin(),vec.end())<<"\n";
    cout << "min = " << *min_element(vec.begin(),vec.end()) << "\n";
    long double AVG = ((float)(accumulate(vec.begin(),vec.end(),0)) / (float)vec.size())+0.0005f;
    cout << "AVG = " << fixed<<setprecision(3)<<AVG << "\n";

    return 0;
}