#include<iostream>
using namespace std;
unsigned long long P(unsigned long long n){
	unsigned long long a=1,i=1;
	while(i<=n){
		a*=i;
		i++;
	}
	return a;
}

unsigned long long C(unsigned long long a,unsigned long long b){
	return P(a)/(P(b)*P(a-b));
}

int main(){
	for(unsigned long long i=1;i<30;i++){
		for(unsigned long long j=1;j<=i;j++){
			cout << C(i-1,j-1) << " ";
		}
		cout << endl;
	}
}
