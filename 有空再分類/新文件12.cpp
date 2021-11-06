#include <iostream>
#include <vector>
using namespace std;
int main(){
  vector<int> vec;
  int s=10;
  for(int i=1; i<=s;i++) {
  	vec.push_back(i);
	}
	for(int i=0;i<vec.size();i++){
		cout << vec[i] << endl;
	}
}
